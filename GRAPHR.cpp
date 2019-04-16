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

int n , m , maxC = 0 ;
vector<pii> ke[maxN] ;


int fastRead() {
    char c ; int res = 0 ;
    for (c = getchar() ; c < '0' || c > '9' ; c = getchar()) ;
    for ( ; c >= '0' && c <= '9' ; c = getchar()) res*= 10 , res += c - '0' ;
    return res ;
}

void enter () {
    n = fastRead() ; m = fastRead() ;
    forinc(i,1,m) {
        int u = fastRead() , v = fastRead() , c = fastRead() ;
        maximize(maxC,c) ;
        ke[u].push_back({v,c}) ;
        ke[v].push_back({u,c}) ;
    }
}

bool vis[maxN] ;

void dfs(int u , int x){
    vis[u] = true ;
    for (auto v : ke[u]) if (v.se <= x && !vis[v.fi]) dfs(v.fi,x) ;
}

bool Tcheck(int mid) {
    forinc(i,1,n) vis[i] = false ;
    dfs(1,mid) ;
    return vis[n] ;
}

void process () {
    int L = 0 , R = maxC , res = 0 ;
    while (L <= R) {
        int mid = (L+R) / 2 ;
        if (Tcheck(mid)) R = mid - 1 , res = mid ; else L = mid + 1 ;
    }
    if (res > 0) cout << res << endl ; else cout << "NO PATH EXISTS" << endl ;
}

int main () {
    freopen("GRAPHR.inp" , "r" , stdin) ;
    freopen("GRAPHR.out" , "w" , stdout) ;
    enter () ;
    process () ;
    return 0 ;
}
