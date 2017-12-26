#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)
#define forv(j,u) for (int j = 0 ; j < u.size() ; j++)
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define mk make_pair
#define pii pair<int,int>
#define oo 1000000000

using namespace std ;

int n , m , a , b , c , d , val[1001][1001] , f[1001][1001] , min_row[1001][1001] , min_col[1001][1001] , sn , sm , sa , sb ;

int enter()
{
    cin >> n >> m >> b >> a >> d >> c ;
    sn = n ; sm = m ; sa = a ; sb = b ;
    forinc(i,1,m)
    forinc(j,1,n) {
        int x ; cin >> x ;
        val[i][j] = val[i-1][j] + val[i][j-1] - val[i-1][j-1] + x ;
    }
    return 0 ;
}

int get(int x , int y , int u , int v)
{
    return val[u][v] - val[x-1][v] - val[u][y-1] + val[x-1][y-1] ;
}

int build()
{
    forinc(i,2,m-c)
    forinc(j,2,n-d) f[i-1][j-1] = get(i,j,i+c-1,j+d-1) ;
    return 0 ;
}

int fix_leng()
{
    sm = m - c - 1 ; sn = n - d - 1 ;
    sa = a - c - 1 ; sb = b - d - 1 ;
    return 0 ;
}

deque<int> st ;

int empty_deque()
{
    while (!st.empty()) st.pop_back() ;
    return 0 ;
}

int find_min()
{
    forinc(row,1,sm){
        empty_deque() ;
        forinc(i,1,sn) {
            while (!st.empty() && f[row][i] < f[row][st.back()]) st.pop_back() ;
            if (!st.empty() && i - st.front() + 1 > sb) st.pop_front() ;
            st.push_back(i) ;
            if (i >= sb) min_row[row][i-sb+1] = st.front() ;
        }
    }

    forinc(col,1,sn){
        empty_deque() ;
        forinc(i,1,sm) {
            while (!st.empty() && f[i][min_row[i][col]] < f[st.back()][min_row[st.back()][col]]) st.pop_back() ;
            if (!st.empty() && i - st.front() + 1 > sa) st.pop_front() ;
            st.push_back(i) ;
            if (i >= sa) min_col[i-sa+1][col] = st.front() ;
        }
    }
    return 0 ;
}

int solve(int i , int j)
{
    int res = 0 ;
    int x = min_col[i][j] , y = min_row[x][j] , stin = f[x][y] ;
    res = get(i , j , i + a - 1 , j + b - 1) - stin ;
    return res ;
}

int process()
{
    build() ;
    fix_leng() ;
    find_min() ;
    int res = -oo , cax = 0 , cbx = 0 , cay = 0 , cby = 0 ;
    forinc(i,1,sm-sa+1)
    forinc(j,1,sn-sb+1) {
        int tmp = solve(i,j) ;
        if (tmp > res) {
            res = tmp ;
            cax = i  ; cay = j  ;
            int x = min_col[i][j] , y = min_row[x][j] ;
            cbx = x  ; cby = y  ;
        }
    }
    cout << cay << " " << cax << endl << cby+1 << " " << cbx+1 << endl ;
    return 0 ;
}

int main()
{
    //freopen("MPYRAMID.inp" , "r" , stdin) ;
    enter() ;
    process() ;
    return 0 ;
}

