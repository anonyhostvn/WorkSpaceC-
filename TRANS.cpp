#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)
#define forv(j,u) for (int j = 0 ; j < u.size() ; j++)
#define fi first
#define se second
#define pii pair<int,int>

template <class _T> bool maximize(_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize(_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

const int ooit = 2e9 ;
const long long ooll = 1e15 ;
const int base = 1000000007 ;

using namespace std ;

int fastRead() {
    char c ; int res = 0 ;
    for (c = getchar() ; c < '0' || c > '9' ; c = getchar()) ;
    for ( ; c >= '0' && c <= '9' ; c = getchar()) res*= 10 , res += c - '0' ;
    return res ;
}

#define maxN 105

int n , m , deg[maxN] ;
vector<int> ke[maxN] ;
set<int> nxt[maxN] ;
bool ok_sub2 = true ;

void enter () {
    n = fastRead() ; m = fastRead() ;
    forinc(i,1,m) {
        int u = fastRead() , v = fastRead() ;
        ke[u].push_back(v) ; ke[v].push_back(u) ;
        nxt[u].insert(v) ; nxt[v].insert(u) ;
        deg[u] ++ ; deg[v] ++ ; if (deg[u] > 2 || deg[v] > 2) ok_sub2 = false ;
    }
}

struct Tbit_tree {
    int val[maxN] ;

    void reset() {
        forinc(i,1,n) val[i] = 0 ;
    }

    void update(int i , int x) {
        for ( ; i <= n ; i += i & -i) val[i] += x ;
    }

    int get(int i) {
        int res = 0 ;
        for ( ; i > 0 ; i -= i & -i) res += val[i];
        return res ;
    }
} tree ;

///========================================================================================================================================================
///                                             SUB 1
///========================================================================================================================================================

int child [maxN] , par[maxN] ;
struct __node {
    int t , x ;
} ;
vector<__node> ans ;

void dfs(int u , int p) {
    child[u] = 0 ;
    for (auto v : ke[u]) if (v != p) child[u] ++ , par[v] = u , dfs(v,u) ;
}

void bfs() {
    queue<int> q ; forinc(i,1,n) if (child[i] == 0) q.push(i) ;

    while (!q.empty()) {
        int u = q.front() ; q.pop() ;
        if (tree.get(u-1) + 1 > 1) ans.push_back({1,tree.get(u-1) + 1}) , tree.update(u,-1) ;
        if (par[u] > -1) child[par[u]] -- ;
        if (!child[par[u]]) q.push(par[u]) ;
    }
}

void sub1 () {
    dfs(1,-1) ;
    forinc(i,1,n) tree.update(i,1) ;

    bfs() ;
    cout << ans.size() << endl ;
    for (auto tmp : ans) cout << tmp.t << " " << tmp.x << endl ;
}

///========================================================================================================================================================
///                                                 SUB 2
///========================================================================================================================================================

void sub2 () {
    forinc(i,1,n) tree.update(i,1) ;

    queue<int> q ; forinc(i,1,n) if (nxt[i].size() == 1) q.push(i) ;

    while (!q.empty()) {
        int u = q.front() ; q.pop() ;
        if (nxt[u].size() > 0)
            ans.push_back({1 , tree.get(u-1) + 1}) , tree.update(u , -1) ;

        vector<int> must_era ;
        for (auto v : nxt[u]) {
            nxt[v].erase(u) ; must_era.push_back(v) ;
            if (nxt[v].size() == 1)
                    q.push(v) ;
        }

        for (auto v : must_era)
                nxt[u].erase(v) ;
    }

    cout << ans.size() << endl ;
    for (auto tmp : ans) cout << tmp.t << " " << tmp.x << endl ;
}

///========================================================================================================================================================
///                                         PROCESS
///========================================================================================================================================================

void process () {
    if (m == n - 1) sub1 () ; else sub2 () ;
}

int main () {
    freopen("TRANS.inp" , "r" , stdin) ;
    freopen("TRANS.out" , "w" , stdout) ;
    enter () ;
    process () ;
    return 0 ;
}
