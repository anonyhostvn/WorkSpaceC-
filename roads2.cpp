#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)
#define forv(j,u) for (int j = 0 ; j < u.size() ; j++)
#define base 1000000000
#define oo 2000000000

using namespace std ;

int n , m , num[10001],  color[10001] ;
bool cycle[10001] , vis[10001] ;
long long f[10001] ;
vector <int> ke[10001] , ke_re[10001] ;

int enter()
{
    cin >> n >> m ;
    forinc(i,1,m) {
        int u , v ; cin >> u >> v ;
        ke[u].push_back(v) ;
        ke_re[v].push_back(u) ;
    }
}

int dfs(int u , vector<int> ke[10001] )
{
    color[u] = 1 ;
    forv(j,ke[u]){
        int v = ke[u][j] ;
        if (color[v] == 0) dfs(v,ke) ;
        else if (color[v] == 1) cycle[v] = true ;
     }
     color[u] = 3 ;
     return 0 ;
}

int dfs1(int u , vector<int> ke[10001])
{
    vis[u] = true  ;
    forv(j,ke[u]){
        int v = ke[u][j] ;
        if (!vis[v]) dfs1(v,ke) ;
    }
}

int prepare()
{
    dfs(1,ke) ;
    dfs1(n,ke_re) ;
}

bool check_case1()
{
    forinc(i,1,n) if (vis[i] && cycle[i]) return true ;
    return false ;
}

int dp(int u)
{
    vis[u] = true ;
    forv(j,ke[u]){
        int v = ke[u][j] ;
        if (!cycle[v]) {
            f[v] = (f[v] + f[u]) ;
            dp(v) ;
            }
        else f[v] = 0 ;
    }
}

long long call(int u)
{
    if (cycle[u]) return 0 ;
    if (u == n) return 1  ;
    if (f[u] != -1) return f[u] ;
    long long res= 0 ;
    forv(j,ke[u]){
        int v = ke[u][j] ;
        res = (res + call(v)) % base ;
    }
    f[u] = res ;
    return f[u] ;
}

int process()
{
    prepare() ;
    if (check_case1()) {
        cout << "INFINITE PATHS" ;
        return 0 ;
    }
    memset(f,-1,sizeof(f)) ;
    cout << call(1) ;
    return 0 ;
}

int main()
{
    //freopen("roads2.inp" , "r" , stdin) ;
    enter() ;
    process() ;
    return 0 ;
}
