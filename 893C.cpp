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
#define ooll (long long) 1e15
#define ooit (int) 2e9

template <class _T> bool maximize(_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize(_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

using namespace std ;

#define maxN 100005

int n , m , a[maxN] ;
vector<int> ke[maxN] ;

void enter() {
    cin >> n >> m ;
    forinc(i,1,n) cin >> a[i] ;
    forinc(i,1,m) {
        int u , v ; cin >> u >> v ;
        ke[u].push_back(v) ;
        ke[v].push_back(u) ;
    }
}

bool vis[maxN] ;
int wmin = 0 ;

void dfs(int u) {
    vis[u] = true ; minimize(wmin,a[u]) ;
    for (int v : ke[u]) if (!vis[v]) dfs(v) ;
}

void process () {
    long long res = 0 ;
    forinc(i,1,n) if (!vis[i]) wmin = ooit , dfs(i) , res += wmin ;
    cout << res << endl ;
}

int main () {
    //freopen("893C.inp" , "r" , stdin) ;
    enter() ;
    process () ;
    return 0 ;
}
