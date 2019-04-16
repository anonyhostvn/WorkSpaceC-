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

int fastRead() {
    char c ; int res = 0 ;
    for (c = getchar() ; c < '0' || c > '9' ; c = getchar()) ;
    for ( ; c >= '0' && c <= '9' ; c = getchar()) res*= 10 , res += c - '0' ;
    return res ;
}

#define maxM 400005
#define maxN 200005

struct node {
    int u , v , c;
} e[maxM] ;

struct Builder {
    int splane , cost ;
};

int n , m , c;

void enter () {
    n = fastRead() ; m = fastRead() ; c = fastRead() ;
    forinc(i,1,m) {
        int u = fastRead() , v = fastRead() , c = fastRead() ;
        e[i].u = u ; e[i].v = v ; e[i].c = c ;
    }
    sort(e + 1, e + 1 + m , [] (node a , node b) {
         return a.c < b.c ;
         }) ;
}

int lab[maxN] ;
vector<int> ke[maxN] ;

int get_root(int u) {
    if (u == lab[u]) return u ;
    lab[u] = get_root(lab[u]) ;
    return lab[u] ;
}

void _union(int u , int v) {
    lab[get_root(u)] = get_root(v) ;
    get_root(u) ;
}

bool vis[maxN] ;
long long cost_build = 0 ;

void dfs(int u) {
    vis[u] = true ;
    for (auto v : ke[u]) if (!vis[v]) dfs(v) ;
}

#define pli pair<long long , int>

int scomp = 0 ;

void prepare () {
    forinc(i,1,n) lab[i] = i ;
    forinc(i,1,m) if (get_root(e[i].u) != get_root(e[i].v)) {
        _union(e[i].u,e[i].v) ; cost_build += e[i].c ;
        ke[e[i].u].push_back(e[i].v) ; ke[e[i].v].push_back(e[i].u) ;
    }

    forinc(i,1,n) if (!vis[i]) {
        scomp ++ ;
        dfs(i) ;
    }
}

void solve(int cost , int s) {
    long long res = min((long long) cost * n , cost_build + (long long) cost * scomp );
    cout <<res << endl ;
}

void sub1 () {
    forinc(i,1,c) {
        int s , cost ; cin >> cost >> s ;
        if (s < scomp) cout << -1 << endl ; else  solve(cost,s) ;
    }
}

void sub2() {
    forinc(i,1,c) {
        int s , cost ; cin >> cost >> s ;
        if (s < scomp) cout << -1 << endl ; else {
            long long res = min((long long) n * cost , cost_build + cost) ;
            cout << res << endl ;
        }
    }
}

void div_sub() {
    prepare() ;
    if (m == n-1) sub2() ; else sub1() ;
}

int main () {
    freopen("AIRPORTS.inp" , "r" , stdin) ;
    freopen("AIRPORTS.out" , "w" , stdout) ;
    enter () ;
    div_sub() ;
    return 0 ;
}
