#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)
#define forv(j,u) for (int j = 0 ; j < u.size() ; j++)

using namespace std ;

int n , m , f[101][2] ;
vector<int> ke[101] ;

int enter()
{
    cin >> n >> m ;
    forinc(i,1,m){
        int u , v  ; cin >> u >> v ;
        ke[u].push_back(v) ;
        ke[v].push_back(u) ;
    }
    return 0 ;
}

int dfs(int u , int p)
{
    int scon = 0 , a[101][2] , g[101][101] ;
    f[u][1] = -1 ; f[u][0] = -1 ;
    forv(j,ke[u]){
        int v = ke[u][j] ;
        if (v!=p){
            dfs(v,u) ;
            a[++scon][0] = f[v][0] ;
            a[scon][1] = f[v][1] ;
        }
    }

    if (scon == 0){
        f[u][0] = -1 ;
        f[u][1] = 0 ;
        return 0 ;
    }
    forinc(i,0,scon)
    forinc(j,0,scon) {
        g[i][j] = -1 ;
        g[i][j] = -1 ;
    }
    g[0][0] = 0 ;
    forinc(i,0,scon-1)
    forinc(j,0,scon)
    if (g[i][j] > -1){
        if (a[i+1][0] > -1) g[i+1][j] = max(g[i+1][j],g[i][j] + a[i+1][0]) ;
        if (a[i+1][1] > -1) g[i+1][j+1] = max(g[i+1][j+1],g[i][j] + a[i+1][1]) ;
    }
    forinc(i,0,scon)if (g[scon][i] > -1) {
        if (i % 2 == 0) f[u][1] = max(f[u][1],scon-i+g[scon][i]) ;
        if (i % 2 != 0) f[u][0] = max(f[u][0],scon-i+g[scon][i]) ;
    }

    return 0 ;
}

int process()
{
    dfs(1,-1) ;
    cout << f[1][0] ;
}

int main()
{
    //freopen("tree.inp" , "r" , stdin) ;
    enter() ;
    process() ;
    return 0 ;
}
