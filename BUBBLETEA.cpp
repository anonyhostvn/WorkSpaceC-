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

int n , k ;
long long sum = 0 ;
vector<pii> ke[maxN] ;
bool import[maxN] ;

int fastRead() {
    char c ; int res = 0 ;
    for (c = getchar() ; c < '0' || c > '9' ; c = getchar()) ;
    for ( ; c >= '0' && c <= '9' ; c = getchar()) res *= 10 , res += c - (int) '0' ;
    return res ;
}

void enter () {
    //cin >> n >> k ;
    n = fastRead() ; k = fastRead() ;
    forinc(i,1,k) {
        int x = fastRead() ; //cin >> x ;
        import[x] = true ;
    }

    forinc(i,1,n-1) {
        int u = fastRead() , v = fastRead() , c = fastRead() ; //cin >> u >> v >> c ;
        sum += c ;
        ke[u].push_back({v,c}) ; ke[v].push_back({u,c}) ;
    }
}

bool possible(int mid , vector<long long> &g , long long smax) {
    vector<long long> p ;
    forv(i,g) if (i != mid) p.push_back(g[i]) ;
    int m = p.size() - 1 ;

    forinc(i,0,m/2) if (p[i] + p[m-i] > smax) return false ;
    return true ;
}

long long f[maxN] ;
bool ok = true ;

void dfs(int u , int p , long long smax) {
    if (!ok) return ;
    vector<long long> g ;
    if (import[u]) g.push_back(0) ;

    for (auto tmp : ke[u]) if (tmp.fi != p) {
        dfs(tmp.fi,u,smax) ;
        if (!ok) return ;
        if (f[tmp.fi] > -1) g.push_back(f[tmp.fi] + tmp.se) ;
    }

    sort(g.begin() , g.end()) ;
    int m = g.size() - 1 ;

    if (g.size() == 1) {f[u] = g[0] ; return ; }
    if (g.size() == 0) {f[u] = -1 ; return ;}

    if (g.size() % 2 == 0) {
        forinc(i,0,m/2) if (g[i] + g[m-i] > smax) { ok = false ; return ; }
        f[u] = -1 ; return ;
    }

    int L = 0 , R = m , ans = -1 ;
    while (L <= R) {
        int mid = (L+R) / 2 ;
        if (possible(mid,g,smax)) R = mid - 1 , ans = mid ; else L = mid + 1 ;
    }

    if (ans == -1) {ok = false ; return ; }

    f[u] = g[ans] ;
}

bool check(long long mid) {
    ok = true ;

    dfs(1,-1,mid) ;

    return ok ;
}

void process () {
    long long L = 0 , R = sum , res = -1 ;

    while (L <= R) {
        long long mid = (L + R) / 2 ;
        if (check(mid)) R = mid - 1 , res = mid ; else L = mid + 1 ;
    }

    cout << res << endl ;
}

int main () {
    freopen("BUBBLETEA.inp" , "r" , stdin) ;
    freopen("BUBBLETEA.out" , "w" , stdout) ;

    enter () ;
    process () ;

    return 0 ;
}
