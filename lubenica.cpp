#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)
#define forv(j,u) for (int j = 0 ; j < u.size() ; j++)
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define oo 1000000000

using namespace std ;

int n , nlog , f[100001][20] , cnt , stin[100001]  , stout[100001] , gmax[100001][20] , gmin[100001][20] ;
vector<int> ke[100001] , ts[100001] ;

int enter()
{
    cin >> n ;
    forinc(i,1,n-1){
        int u , v , c ; cin >> u >> v >> c ;
        ke[u].push_back(v) ;
        ke[v].push_back(u) ;
        ts[u].push_back(c) ;
        ts[v].push_back(c) ;
    }
    nlog = log2(n) ;
}

int dfs(int u , int p)
{
    stin[u] = ++cnt ;
    forinc(i,1,nlog) {
        f[u][i] = f[f[u][i-1]][i-1] ;
        gmax[u][i] = max(gmax[u][i-1],gmax[f[u][i-1]][i-1]) ;
        gmin[u][i] = min(gmin[u][i-1],gmin[f[u][i-1]][i-1]) ;
    }
    forv(j,ke[u]){
        int v = ke[u][j] ;
        if (v != p){
            f[v][0] = u ;
            gmax[v][0] = ts[u][j];
            gmin[v][0] = ts[u][j] ;
            dfs(v,u) ;
        }
    }
    stout[u] = ++cnt ;
}

bool anc(int u , int v)
{
    return (stin[u] <= stin[v] && stout[u] >= stout[v]) ;
}

int findmax(int u , int v)
{
    if (u == v) return 0 ;
    int res = 0 ;
    fordec(i,nlog,0)
    if (!anc(f[u][i],v)) {
        res = max(res,gmax[u][i]) ;
        u = f[u][i] ;
    }
    return max(res,gmax[u][0]) ;
}

int findmin(int u , int v)
{
    if (u == v) return oo ;
    int res = oo ;
    fordec(i,nlog,0)
    if (!anc(f[u][i],v)) {
        res = min(res,gmin[u][i]) ;
        u = f[u][i] ;
    }
    return min(res,gmin[u][0]) ;
}

int LCA(int u , int v)
{
    if (anc(u,v)) return u ;
    if (anc(v,u)) return v ;
    fordec(i,nlog,0)
    if (!anc(f[u][i],v)) u = f[u][i] ;
    return f[u][0] ;
 }

 int process()
 {
     f[1][0] = 1 ;
     dfs(1,-1);
     int k ; cin >> k ;
     forinc(i,1,k){
         int D , E; cin >> D >> E ;
         int u = LCA(D,E) ;
         cout << min(findmin(D,u),findmin(E,u)) << " " << max(findmax(D,u),findmax(E,u)) << endl  ;
     }
 }

int main()
{
    //freopen("lubenica.inp" , "r" , stdin) ;
    enter() ;
    process() ;
}
