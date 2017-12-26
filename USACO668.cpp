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

using namespace std ;

int n , x[201] , y[201] , p[201] , total = 0 ;
bool vis[201] ;
vector<int> ke[201] ;

int enter()
{
    cin >> n ;
    forinc(i,1,n) cin >> x[i] >> y[i] >> p[i] ;
    return 0 ;
}

bool can_connect(int i , int j)
{
    long long a1 = x[i] - x[j] , a2 = y[i] - y[j] ;
    if (a1 * a1 + a2 * a2 <= (long long) p[i] * p[i]) return true ;
    return false ;
}

int add(int u , int v)
{
    ke[u].push_back(v) ;
    return 0 ;
}

int dfs(int u)
{
    total ++ ;
    vis[u] = true ;
    forv(j,ke[u]) {
        int v = ke[u][j] ;
        if (!vis[v]) dfs(v) ;
    }
    return 0 ;
}

int process()
{
    forinc(i,1,n)
    forinc(j,1,n)
        if (can_connect(i,j)) add(i,j) ;
    int res = 0 ;
    forinc(i,1,n) if (!vis[i]) {
        total = 0 ;
        dfs(i) ;
        res = max(res,total) ;
    }
    cout << res ;
    return 0 ;
}

int main()
{
    freopen("moocast.in" , "r" , stdin) ;
    //freopen("moocast.out" , "w"  , stdout) ;
    enter() ;
    process() ;
}
