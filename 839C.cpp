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
#define maxN 100000

using namespace std ;

int n , sleaf = 0 , d[maxN+1] ;
double xs [maxN+1] ;
vector<int> ke[maxN+1] , leaf;

int enter()
{
    cin >> n ;
    forinc(i,1,n-1) {
        int u , v ; cin >> u >> v ;
        ke[u].pb(v) ;
        ke[v].pb(u) ;
    }
    return 0 ;
}

int dfs(int u , int p)
{
    int scon = 0 ;
    forv(j,ke[u]) if (ke[u][j] != p) scon ++ ;
    forv(j,ke[u]){
        int v = ke[u][j] ;
        if (v != p){
            xs[v] = (double) xs[u] * ((double)1 / scon) ;
            d[v] = d[u] + 1 ;
            dfs(v,u) ;
        }
    }
    if (scon == 0) leaf.pb(u) ;
    return 0 ;
}

int process()
{
    xs[1] = 1 ;
    dfs(1,-1) ;
    double res = 0 ;
    forv(j,leaf){
        int v = leaf[j] ;
        res += (double) d[v] * xs[v] ;
    }
    cout << fixed << setprecision(15) << res ;
    return 0 ;
}

int main()
{
    //freopen("839C.inp" , "r" , stdin) ;
    enter() ;
    process() ;
    return 0 ;
}
