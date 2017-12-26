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
#define maxN 200000
#define maxL 20

using namespace std ;

int n , m , cnt = 0 , num[maxN+1] , low[maxN+1]  , sbridge = 0 ;
bool dd[2*maxN+1] ;
vector<pii> ke[maxN+1] ;
pii query[maxN+1] ;

int enter()
{
    cin >> n ;
    forinc(i,1,n-1) {
        int u , v ; cin >> u >> v ;
        ke[u].pb(mk(v,i)) ;
        ke[v].pb(mk(u,i)) ;
    }
    int cnt = n-1 ;
    cin >> m ;
    forinc(i,1,m){
        int u , v  ; cin >> u >> v ; ++cnt ;
        ke[u].pb(mk(v,cnt)) ;
        ke[v].pb(mk(u,cnt)) ;
    }
    return 0 ;
}

int dfs(int u , int p , int edge)
{
    num[u] = ++ cnt ;
    low[u] = cnt ;
    forv(j,ke[u]) if (ke[u][j].se != edge) {
        int v = ke[u][j].fi ;
        if (num[v] == 0){
            dfs(v,u,ke[u][j].se) ;
            low[u] = min(low[u],low[v]) ;
        }
        else low[u] = min(low[u],num[v]) ;
    }
    if (num[u] == low[u] && p != -1) sbridge ++ ;
    return 0 ;
}

int process()
{
    dfs(1,-1,-1) ;
    cout << sbridge ;
    return 0 ;
}

int main()
{
    //freopen("KBUILD.inp" , "r", stdin) ;
    enter() ;
    process() ;
    return 0 ;
}
