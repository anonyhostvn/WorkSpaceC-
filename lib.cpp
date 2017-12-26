#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)
#define forv(j,u) for (int j = 0 ; j < u.size() ; j++)
#define oo 100000000

using namespace std ;

int n , m , clib , croad , node ;
vector <int> ke[100001] ;
bool dd[100001] ;

int enter()
{
    cin >> n >> m >> clib >> croad ;
    forinc(i,1,m) {
        int u , v ;
        cin >> u >> v ;
        ke[u].push_back(v) ;
        ke[v].push_back(u) ;
    }
    return 0 ;
}

int dfs(int u)
{
    ++node ;
    dd[u] = true ;
    forv(j,ke[u]){
        int v = ke[u][j] ;
        if (!dd[v]) dfs(v) ;
    }
}

int process()
{
    long long res = 0 ;
    forinc(i,1,n)
    if (!dd[i]){
        node = 0 ;
        dfs(i) ;
        res = res + clib ;
        res = res + (long long) min(clib,croad) * (node-1) ;
    }
    cout << res << endl ;
}

int main()
{
    //freopen("lib.inp" , "r" , stdin) ;
    //freopen("lib.out" , "w" , stdout) ;
    int q ;
    cin >> q ;
    forinc(i,1,q){
        enter() ;
        process() ;
        forinc(i,1,n){
            ke[i].clear() ;
            dd[i] = false ;
        }
    }
    return 0  ;
}
