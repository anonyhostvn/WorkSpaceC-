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
#define maxN 200001

using namespace std ;

int n , q , a[maxN] , b[maxN] ,dep[maxN] , y[maxN] , f[20][maxN] , maxdep = 0 ;
vector<int> ke[maxN] ;

int enter()
{
    cin >> n >> q ;
    forinc(i,1,n-1) {
        int u , v ; cin >> u >> v ;
        ke[u].push_back(v) ;
        ke[v].push_back(u) ;
    }
    forinc(i,0,n-1) cin >> a[i] ;
    forinc(i,1,q) cin >> b[i] ;
    return 0 ;
}

int dfs(int u , int p)
{
    maxdep = max(maxdep,dep[u]) ;
    forv(j,ke[u]) {
        int v = ke[u][j] ;
        if (v != p) {
            dep[v] = dep[u] + 1 ;
            dfs(v,u) ;
        }
    }
    return 0 ;
}

int getbit(int x , int i)
{
    return (x >> i) &  1 ;
}

int power[20] ;

int process()
{
    dfs(0,-1) ;
    power[0] = 1 ;
    forinc(i,1,18) power[i] = power[i-1] * 2 ;
    forinc(i,0,n-1) y[dep[i]] ^= a[i] ;
    forinc(i,0,maxdep) f[0][i] = y[i] ;
    forinc(i,0,17)
    forinc(j,0,maxdep)
    if (getbit(j,i) == 1) f[i+1][j] = f[i][j ^ power[i]] ;
    else f[i+1][j] = f[i][j] ^ f[i][j ^ power[i]] ;
    forinc(i,1,q) cout << f[18][b[i]] << endl ;
    return 0 ;
}

int main()
{
    freopen("WEASELT.inp" , "r" , stdin) ;
    enter() ;
    process() ;
    return 0 ;
}
