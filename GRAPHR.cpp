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

template <class _T> bool maximize(_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize(_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

const int ooit = 2e9 ;
const long long ooll = 1e15 ;

using namespace std ;

#define maxN 50005

int n , m , maxL ;
vector<pii> ke[maxN] ;

void enter () {
    cin >> n >> m ;
    forinc(i,1,m) {
        int u , v , c ; cin >> u >> v >> c ;
        maximize(maxL , c) ;
        ke[u].push_back({v,c}) ; ke[v].push_back({u,c}) ;
    }
}

bool vis[maxN] ;

void dfs(int u , int x) {
    vis[u] = true ;
    for (auto tmp : ke[u]) if (!vis[tmp.fi] && tmp.se <= x) dfs(tmp.fi,x) ;
}

bool check(int x) {
    forinc(i,1,n) vis[i] = false ;
    dfs(1,x) ;
    return vis[n] ;
}

void process () {
    int l = 0 , r = maxL , res = -1 ;
    while (l <= r) {
        int mid = (l+r) / 2 ;
        if (check(mid)) r = mid - 1 , res = mid ; else l = mid + 1 ;
    }

    if (res > -1) cout << res ; else cout << "NO PATH EXISTS" ; cout << endl ;
}

int main () {
    //freopen("GRAPHR.inp" , "r" , stdin) ;
    //freopen("GRAPHR.out" , "w" , stdout) ;
    enter () ;
    process () ;
    return 0 ;
}
