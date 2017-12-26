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
#define maxN 1001

using namespace std ;

const int oo = 100000000 ;

int n , f[maxN][3] ;
vector <int> ke[maxN] ;

int enter()
{
    forinc(i,1,n-1){
        int u ,  v ; cin >> u >> v ;
        ke[u].pb(v) ;
        ke[v].pb(u) ;
    }
    return 0 ;
}

int tripmin(int a , int b , int c)
{
    return min(a,min(b,c)) ;
}

int dfs(int u , int p)
{
    f[u][1] = 1 ; f[u][2] = oo ; f[u][0] = 0 ;
    int sum = 0 ; bool ok = false ;
    forv(j,ke[u]){
        int v = ke[u][j] ;
        if (v != p) {
            dfs(v,u) ;
            f[u][0] += f[v][2] ;
            f[u][1] += tripmin(f[v][0],f[v][1],f[v][2]) ;
            sum += min(f[v][2],f[v][1]) ;
        }
    }
    forv(j,ke[u]) if(ke[u][j] != p) f[u][2] = min(f[u][2],sum-min(f[ke[u][j]][1],f[ke[u][j]][2]) + f[ke[u][j]][1]) ;
    return 0 ;
}

int process()
{
    dfs(1,-1) ;
    cout << min(f[1][1],f[1][2]) << endl  ;
    forinc(i,1,n) ke[i].clear() ;
}

int main()
{
    //freopen("NTPFECT.inp" , "r" , stdin) ;
    while (cin >> n) {
        if (n == 0) return 0 ;
        enter() ;
        process() ;
    }
    return 0 ;
}
