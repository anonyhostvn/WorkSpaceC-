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

using namespace std ;

int n , color[maxN] ;
vector<int> ke[maxN] ;

int enter()
{
    cin >> n ;
    forinc(i,1,n-1) {
        int u , v ; cin >> u >> v ;
        ke[u].push_back(v) ;
        ke[v].push_back(u) ;
    }
    return 0 ;
}

int dfs(int u , int p)
{
    forv(j,ke[u]) if (ke[u][j] != p) color[ke[u][j]] = 1 - color[u] , dfs(ke[u][j],u) ;
    return 0 ;
}

int process()
{
    int csub = 0 ;
    long long res = 0 ;
    dfs(1,-1) ;
    forinc(i,1,n) csub += color[i] ;
    forinc(i,1,n) if (color[i] == 0) res += (long long) (csub - ke[i].size()) ;
    cout << res ;
    return 0 ;
}

int main()
{
    //freopen("862B.inp" , "r" , stdin) ;
    enter() ;
    process() ;
    return 0 ;
}
