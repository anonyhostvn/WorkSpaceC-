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
#define oo (long long) 1e15
#define maxN 40

using namespace std ;

int n , m  , a[maxN][maxN] ;
int gox[4] = { 0 , 0 , -1 , +1} ;
int goy[4] = {-1 , +1 , 0 ,  0} ;
bool sub2 = true ;

void enter()
{
    scanf("%d%d" , &m , &n) ;
    forinc(i,1,m) forinc(j,1,n) {
        scanf("%d" , &a[i][j]);
        if (a[i][j] == -1) sub2 = false ;
    }
}

int get_bit(int x , int i) {return (x >> i) & 1 ; }

bool check(int st)
{
    forinc(i,1,m) forinc(j,1,n) {
        if (a[i][j] == -1) continue ;
        int cnt = 0 ;
        forinc(k,0,3) {
            int cx = i + gox[k] , cy = j + goy[k] ;
            if (cx >= 1 && cy >= 1 && cx <= m && cy <= n && get_bit(st,(cx - 1) * n + cy -1) == 1) cnt ++ ;
        }
        if (cnt % 2 != a[i][j]) return false ;
    }
    return true ;
}

void sub_1()
{
    int l = (1 << n * m) -1 ;
    int res = 0 ;
    forinc(st,0,l) if (check(st)) res ++ ;
    printf("%d" , res) ;
}

int b[25][25] ;

int solve(int st)
{
    forinc(i,1,n) b[1][i] = get_bit(st,i-1) ;
    forinc(i,2,m) forinc(j,1,n) {
        int cnt = b[i-1][j-1] + b[i-1][j+1] + b[i-2][j] ;
        if (cnt % 2 != a[i-1][j]) b[i][j] = 1 ; else b[i][j] = 0 ;
    }
    forinc(i,1,m) forinc(j,1,n){
        int cnt = b[i-1][j] + b[i+1][j] + b[i][j-1] + b[i][j+1] ;
        if (cnt % 2 != a[i][j]) return 0 ;
    }
    return 1 ;
}

void sub_2()
{
    int l = (1 << n) - 1 ;
    int res = 0 ;
    forinc(st,0,l) res += solve(st) ;
    printf("%d" , res) ;
}

int x[maxN*maxN][maxN*maxN] , nxt[maxN*maxN][maxN*maxN] , count_[maxN*maxN];

int khu_gau(int i , int j) {
    forinc(k,i+1,n*m) if (x[k][j] == 1) {
        x[k][j] == 0 ; count_[k] -- ;
    }
}

void solve()
{
    forinc(i,1,m*n) {
        int prev = 0 ;
        fordec(j,m*n,1) {
            nxt[i][j] = prev ;
            if (x[i][j] == 1) prev = i, count_[i] ++ ;
        }
    }
    int k = n * m ;
    forinc(i,1,n*m) if (count_[i] == 0) k -- ; else {
        for (int id = 1 ; id > 0 ; id = nxt[i][id]) if (x[i][id] == 1) k -= khu_gau(i,id) ;
    }
}

void sub3()
{
    forinc(i,1,m) forinc(j,1,n) {
        forinc(k,0,3) {
            int cx = i + gox[k] , cy = j + goy[k] ;
            if (cx >= 1 && cy >= 1 && cx <= m && cy <= n) x[(i-1) * n + j][(cx-1) * n + cy] = 1 ;
        }
    }
}

void process()
{
    if (n <= 5 && m <= 5) sub_1() ;
    else if (n <= 20 && m <= 20 && sub2) sub_2() ;
}

int main()
{
    freopen("BOMB.inp" , "r" , stdin) ;
    freopen("BOMB.out" , "w" , stdout) ;
    enter() ;
    process() ;
    return  0 ;
}
