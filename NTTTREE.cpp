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
#define maxN 10001
#define maxL 15

using namespace std ;

int n , par[maxN];
long long f[maxN] ;
vector <pii> ke[maxN] ;
long long res = 0 ;

int enter()
{
    cin >> n ;
    forinc(i,1,n-1) {
        int u , v, w ; cin >> u >> v >> w ;
        ++ u , ++ v ;
        ke[u].pb(mk(v,w)) ;
        ke[v].pb(mk(u,w)) ;
    }
    return 0  ;
}

int dfs(int u , int p)
{
    f[u] = 1 ;
    forv(j,ke[u]){
        pii tmp = ke[u][j] ;
        int v = tmp.fi , dist = tmp.se ;
        if (v != p){
            dfs(v,u) ;
            f[u] += f[v] ;
            res += (long long) dist * (n-f[v]) * f[v] ;
        }
    }
    return 0 ;
}

int process()
{
    dfs(1,-1) ;
    cout << res ;
    return 0 ;
}

int main()
{
    //freopen("NTTTREE.inp" , "r" , stdin) ;
    enter() ;
    process() ;
    return 0 ;
}
