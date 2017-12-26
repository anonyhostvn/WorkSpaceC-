#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)
#define forv(j,u) for (int j = 0 ; j < u.size() ; j++)
#define oo 100000000000

using namespace std ;

int n , m , a[51][51] ;
long long sum[51][51] , dd[51][51][51][51] ;

int enter()
{
    cin >> n >> m ;
    forinc(i,1,n)
    forinc(j,1,m) cin >> a[i][j] ;
}

long long get(int x , int y , int u , int v)
{
    return sum[u][v] - sum[x-1][v] - sum[u][y-1] + sum[x-1][y-1] ;
}

long long cal(int x , int y , int u , int v)
{
    if (dd[x][y][u][v] > -1) return dd[x][y][u][v] ;
    if (x == u && y == v) {
        dd[x][y][u][v] = 0 ;
        return 0 ;
    }
    long long res = get(x,y,u,v) , nmin = oo ;
    forinc(i,x,u-1) nmin = min(nmin,cal(x,y,i,v) + cal(i+1,y,u,v)) ;
    forinc(i,y,v-1) nmin = min(nmin,cal(x,y,u,i) + cal(x,i+1,u,v)) ;
    dd[x][y][u][v] = res + nmin ;

    return res + nmin ;
}

int prepare()
{
    forinc(i,1,n)
    forinc(j,1,m) sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + a[i][j] ;
    forinc(i,1,n)
    forinc(j,1,m)
    forinc(u,1,n)
    forinc(v,1,m) dd[i][j][u][v] = -1 ;
}

int process()
{
    prepare() ;
    cout << cal(1,1,n,m) ;
}

int main()
{
    freopen("raisins.in" , "r" , stdin) ;
    freopen("raisins.out" , "w" , stdout) ;
    enter() ;
    process();
    return 0 ;
}
