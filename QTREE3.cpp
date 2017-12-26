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

#define maxN 100000

int n , q ;
vector<int> ke[maxN] ;

void enter () {
    cin >> n >> q ;
    forinc(i,1,n-1) {
        int u , v ; cin >> u >> v ;
        ke[u].push_back(v) ; ke[v].push_back(u) ;
    }
}

int f[maxN] , par[maxN] , spec[maxN] ;

void visit(int u , int p) {
    f[u] = 1 ; int tmp = 0 ;
    for (auto v : ke[u]) if (v != p) {
        visit(v,u)  ; f[u] += f[v]  ; par[v] = u ;
        if (maximize(tmp,f[v])) spec[u] = v ;
    }
}

int pos[maxN] , chainHead[maxN] , cnt = 0 , adj[maxN] ;

void heavy_Light(int u , int p) {
    pos[u] = ++ cnt ; adj[cnt] = u ;
    if (spec[u] == 0) return ;
    chainHead[spec[u]] = chainHead[u] ;
    heavy_Light(spec[u] , u) ;
    for (auto v : ke[u]) if (v != p && v != spec[u]) heavy_Light(v,u) ;
}

void build_heavy_Light() {
    forinc(i,1,n) chainHead[i] = i ;
    visit(1,-1) ;
    heavy_Light(1,-1) ;
}

int val[4 * maxN] ;

void update(int s , int l , int r , int i) {
    if (r < i || i < l) return ;
    if (l == r) { val[s] = 1 - val[s]  ; return ; }
    int mid = (l+r) / 2 ;
    update(2 * s , l , mid , i) ;
    update(2 * s + 1 , mid + 1 , r , i ) ;
    val[s] = val[2 * s] + val[2 * s + 1] ;
}

int get(int s , int l , int r , int u , int v) {
    if (r < u || v < l) return 0 ;
    if (u <= l && r <= v) return val[s] ;
    int mid = (l+r) /  2;
    return get(2 * s , l , mid , u , v) + get(2 * s + 1 , mid + 1 , r , u , v) ;
}

int solve(int u) {
    int pu = 0 ;
    while (1) {
        int v = chainHead[u] ;
        if (get(1,1,n,pos[v],pos[u]) > 0) pu = u ;
        u = par[chainHead[u]] ;
        if (u == 0) break ;
    }
    if (pu == 0) return -1 ;
    int l = pos[chainHead[pu]] , r = pos[pu] , res = 0 ;
    while (l <= r) {
        int mid = (l+r) / 2 ;
        if (get(1,1,n,l,mid) > 0) r = mid - 1 , res = mid ; else l = mid + 1 ;
    }
    return adj[res] ;
}

void process () {
    build_heavy_Light() ;
    forinc(i,1,q) {
        int query , u  ; cin >> query >> u ;
        if (query == 0) update(1,1,n,pos[u]) ;
        else cout << solve(u) << endl  ;
    }
}

int main () {
    freopen("QTREE3.inp" , "r" , stdin) ;
    //freopen("QTREE3.out" , "w" , stdout) ;
    enter () ;
    process () ;
    return 0 ;
}
