#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)
#define forv(j,u) for (int j = 0 ; j < u.size() ; j++)

using namespace std ;

int direct , n , d , m , bit[150001] ;
long long a[100001] ;
pair<int,int> c[100001] , b[100001];

int enter()
{
    cin >> direct >> n >> d  >> m ;
}

int sub1()
{
    long long res = 0 ;
    forinc(i,1,n) cin >> a[i] ; sort(a+1,a+1+n) ;
    int j = 1 ;
    forinc(i,1,n){
        while (j < i && a[i] - a[j] > d) ++ j ;
        res += i - j ;
    }
    cout << res ;
}

int update(int i , int x)
{
    while (i < 150000) {
        bit[i] += x ;
        i += i & (-i) ;
    }
}

int get(int i)
{
    int res = 0  ;
    while (i > 0){
        res += bit[i] ;
        i -= i & (-i) ;
    }
    return res ;
}

int sub2()
{
    forinc(i,1,n)  cin >> c[i].first >> c[i].second ;
    forinc(i,1,n) {
        b[i].first = c[i].first - c[i].second ;
        b[i].second = c[i].first + c[i].second ;
    }
    sort(b+1,b+1+n) ;
    long long  res = 0 ;
    int j = 1 ;
    forinc(i,1,n){
        while (j < i && abs(b[i].first - b[j].first) > d) {
            update(b[j].second,-1) ;
            j++ ;
        }
        res =  res + (long long) get(min(150000,b[i].second+d)) - get(max(1,b[i].second-d)-1) ;
        update(b[i].second,1) ;
    }
    cout << res ;
}

struct node{
    int x , y , z ;
};
node e[100001] ;
int cnt[152][152][152] , sum[152][152][152] ;

int get(int k , int x , int y , int u , int v)
{
    return sum[k][u][v] - sum[k][x-1][v] - sum[k][u][y-1] + sum[k][x-1][y-1] ;
}

int sub3()
{
    forinc(i,1,n) cin >> e[i].x >> e[i].y >> e[i].z ;
    forinc(i,1,n) cnt[e[i].x][e[i].y-e[i].z+76][e[i].z+e[i].y+1] ++ ;

    forinc(x1,0,75)
    forinc(i,1,151)
    forinc(j,1,151) sum[x1][i][j] = sum[x1][i-1][j] + sum[x1][i][j-1]  - sum[x1][i-1][j-1] + cnt[x1][i][j]  ;

    long long res = 0 ;
    forinc(i,0,75)
    forinc(j,1,151)
    forinc(k,1,151) if (cnt[i][j][k] > 1) res += (long long) (cnt[i][j][k]) * (cnt[i][j][k]-1)  ;

    forinc(x1,0,75)
    forinc(y1,0,75)
    forinc(z1,0,75)
    forinc(x2,0,75){
        int newd = d - abs(x1-x2) ;
        if (newd < 0) continue ;
        int a = y1 - z1 + 76 , b = y1 + z1 + 1 , x = max(1,a-newd) , y = max(1,b-newd) , u = min(151,a+newd) , v = min(151,b+newd) ;
        if (cnt[x1][a][b] == 0) continue ;
        if (x1 == x2) res += (long long) (get(x2,x,y,u,v) - cnt[x1][a][b]) * cnt[x1][a][b] ; //+ ((long long ) (cnt[x1][a][b]-1) * cnt[x1][a][b] / 2);
        else res += (long long) get(x2,x,y,u,v) * cnt[x1][a][b] ;
    }

    cout << res / 2 ;
}

int process()
{
    if (direct == 1) sub1() ;
    else if (direct == 2) sub2() ; else sub3() ;
}

int main()
{
    freopen("pairs.inp" , "r" , stdin) ;
    freopen("pairs.out" , "w" , stdout) ;
    enter() ;
    process() ;
}
