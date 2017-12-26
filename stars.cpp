#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)
#define forv(j,u) for (int j = 0 ; j < u.size() ; j++)
#define pb push_back
#define pf push_front
#define fi first
#define se second

using namespace std ;

int n , q , c , qx[100001] , qy[100001] , s[100001];
long long  f[13][101][101] ;

int enter()
{
    cin >> n>> q >> c ;
    forinc(i,1,n) cin >> qx[i] >> qy[i] >> s[i] ;
}

int prepare()
{
    int a[101][101];
    forinc(i,0,c) {
        memset(a,0,sizeof(a)) ;
        forinc(j,1,n) {
            int bright = (s[j] + i) % (c+1) ;
            a[qx[j]][qy[j]] += bright ;
        }
        forinc(u,1,100)
        forinc(v,1,100) f[i][u][v] = f[i][u-1][v] + f[i][u][v-1] - f[i][u-1][v-1] + a[u][v] ;
    }
}

long long get(int i , int x , int y , int u , int v)
{
    return f[i][u][v] - f[i][x-1][v] - f[i][u][y-1] + f[i][x-1][y-1] ;
}

int process()
{
    prepare() ;
    forinc(i,1,q){
        int t , x ,y , u , v ; cin >> t >> x >> y >> u >> v ;
        cout << get(t % (c+1) , x , y , u , v) << endl ;
    }
}

int main()
{
    freopen("stars.inp" , "r" , stdin) ;
    freopen("stars.out" , "w" , stdout) ;
    enter() ;
    process() ;
}
