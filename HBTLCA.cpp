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
#define maxN 100001
#define maxL 20

using namespace std ;

int n , f[maxN][maxL+1] , cnt = 0 , stin[maxN] , stout[maxN] , d[maxN] ;
vector<int> ke[maxN] ;

int enter()
{
    forinc(i,1,n-1) {
        int u , v ; cin >> u >> v ;
        ke[u].pb(v) ;
        ke[v].pb(u) ;
    }
    return 0 ;
}

int dfs(int u , int p)
{
    stin[u] = ++cnt ;
    forinc(i,1,maxL)
    f[u][i] = f[f[u][i-1]][i-1] ;
    forv(j,ke[u]){
        int v  = ke[u][j] ;
        if (v != p){
            f[v][0] = u ;
            d[v] = d[u] + 1 ;
            dfs(v,u) ;
        }
    }
    stout[u] = ++cnt ;
    return 0 ;
}

bool anc(int u, int v)
{
    return (stin[u] <= stin[v] && stout[u] >= stout[v]) ;
}

int LCA(int u ,int v)
{
    if (anc(u,v)) return u ;
    if (anc(v,u)) return v ;
    fordec(i,maxL,0) if (!anc(f[u][i],v)) u =f[u][i] ;
    return f[u][0] ;
}

int solve(int root)
{
    int u , v ; cin >> u >> v ;
    int p = LCA(u,v) ;
    if (!anc(p,root)) return p ;
    if (anc(v,u)) swap(u,v) ;
    if (p == u) {
        if (anc(v,root)) return v ;
        return root ;
    }
    if (anc(u,root)) return u ;
    if (anc(v,root)) return v ;
    if (anc(root,u) || anc(root,v)) return root ;
    int par1 = LCA(root,u) , par2 = LCA(root,v) ;
    if (d[root] - d[par1] > d[root] - d[par2]) return par1 ; else return par2 ;
    return 0 ;
}

int resq(int root)
{
    int u , v ; cin >> u >> v ;
    int par1 = LCA(u,v) , par2 = LCA(u,root) , par3 = LCA(v,root) , nmax = max(d[par1],max(d[par2],d[par3])) ;
    if (nmax == d[par1]) return par1 ;
    else if (nmax == d[par2]) return par2 ;
    return par3 ;
}

int process()
{
    f[1][0] = 1 ;
    dfs(1,-1) ;
    int m , root = 1 ; cin >> m ;
    forinc(i,1,m) {
        char chr ; cin >> chr ;
        if (chr == '!') cin >> root ;
        else cout << solve(root) << endl ;
    }
    forinc(i,1,n) ke[i].clear() ;
    return 0 ;
}

int main()
{
    //freopen("HBTLCA.inp" , "r" , stdin) ;
    while (cin >> n){
        if (n == 0) return 0 ;
        enter() ;
        process() ;
    }
    return 0 ;
}
