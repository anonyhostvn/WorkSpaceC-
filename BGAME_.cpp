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

#define maxM 100005
#define maxN 100005

int n , m ;
struct node {
    int u , v , c ;
} Tedge[maxM] ;

void enter () {
    n = fastRead() ; m = fastRead() ;
    forinc(i,1,m) Tedge[i].u = fastRead() , Tedge[i].v = fastRead() , Tedge[i].c = fastRead() ;
    sort(Tedge + 1 , Tedge + 1 + m , [] (node a , node b) {
         return a.c > b.c ;
         }) ;
    //forinc(i,1,m) cout << Tedge[i].u << " " << Tedge[i].v << " " << Tedge[i].c << endl ;
}

int lab[maxN] ;
bool used[maxM] ;

int get_root(int u) {
    if (u == lab[u]) return lab[u] ;
    lab[u] = get_root(lab[u]) ;
    return lab[u] ;
}

void uni(int u , int v) {
    lab[get_root(u)] = get_root(v) ;
    get_root(u) ;
}

vector<pii> ke[maxN] ;

void add(int u , int v , int c) {
    ke[u].push_back({v,c}) ;
    ke[v].push_back({u,c}) ;
}

void Build_MST() {
    forinc(i,1,n) lab[i] = i ;
    forinc(i,1,m) if (get_root(Tedge[i].u) != get_root(Tedge[i].v)) {
        used[i] = true ;
        uni(Tedge[i].u , Tedge[i].v) ;
        add(Tedge[i].u, Tedge[i].v , Tedge[i].c) ;
    }
}

bool vis[maxN] ;
int f[maxN][25] , g[maxN][25] , stin[maxN] , stout[maxN] , cnt = 0 ;

void dfs(int u , int p) {
    vis[u] = true ; stin[u] = ++cnt ;
    forinc(i,1,20) f[u][i] = f[f[u][i-1]][i-1] , g[u][i] = max(g[u][i-1] , g[f[u][i-1]][i-1]) ;
    for (auto tmp : ke[u]) if (tmp.fi != p) {
        int v = tmp.fi ; f[v][0] = u ; g[v][0] = tmp.se ;
        dfs(v,u) ;
    }

    stout[u] = ++cnt ;
}

bool anc(int u , int v) {
    return stin[u] <= stin[v] && stout[u] >= stout[v] ;
}

int LCA(int u , int v) {
    if (anc(u,v)) return u ;
    if (anc(v,u)) return v ;
    fordec(i,20,0) if (!anc(f[u][i] , v)) u = f[u][i] ;
    return f[u][0] ;
}

int find_max(int u , int v) {
    int res = -ooit ;
    if (u == v) return res ;
    fordec(i,20,0) if (!anc(f[v][i],u)) maximize(res , g[v][i]) , v = f[v][i] ;
    maximize(res , g[v][0]) ;
    return res ;
}

int max_from_to(int u , int v) {
    int p = LCA(u,v) ;
    return max (find_max(p,u) , find_max(p,v));
}

void prepare () {
    Build_MST() ;
    forinc(i,1,n) if (!vis[i]) f[i][0] = i , dfs(i,-1) ;
}

void process () {
    prepare () ;

    int  res = 0  ;

    forinc(i,1,m) if (!used[i]) {
        int u = Tedge[i].u , v = Tedge[i].v , c = Tedge[i].c ; //cout << u << " " << v << " " << c << endl  ;
        maximize(res , c + max_from_to(u,v)) ;
    }

    cout << res << endl ;
}

int main () {
    freopen("BGAME.inp" , "r" , stdin) ;
    freopen("BGAME.out" , "w" , stdout) ;
    enter () ;
    process () ;
    return 0 ;
}
