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

#define maxN 500005

int n ;
vector<int> ke[maxN] ;

void enter () {
    n = fastRead() ;
    forinc(i,1,n-1) {
        int u = fastRead() , v = fastRead() ;
        ke[u].push_back(v) ; ke[v].push_back(u) ;
    }
}

pii f[maxN][3] ;
int T[maxN] ;

void change_max_1 (int u , pii x) { swap(f[u][2] , f[u][1]) ; swap(f[u][1],f[u][0]) ; f[u][0] = x ; }

void change_max_2(int u , pii x) {swap(f[u][2],f[u][1]) ; f[u][1] = x ; }

void change_max_3(int u , pii x) {f[u][2] = x ; }

void update(int u , int v) {
    if (f[v][0].se > -1 && f[v][0].se + 1 > f[u][0].se) {change_max_1(u , {v,f[v][0].se + 1}) ; return ; }
    else if (f[v][0].se > -1 && f[v][0].se + 1 > f[u][1].se) {change_max_2(u, {v,f[v][0].se + 1}) ;return  ; }
    else if (f[v][0].se > -1 && f[v][0].se + 1 > f[u][2].se) {change_max_3(u, {v,f[v][0].se + 1}) ;return ;}

    if (f[v][1].se > -1 && f[v][1].se + 1 > f[u][1].se) {change_max_2(u, {v,f[v][1].se + 1}) ;return ;}
    else if (f[v][1].se > -1 && f[v][1].se + 1 > f[u][2].se ) {change_max_3(u , {v,f[v][1].se + 1}) ;return ;}

    if (f[v][2].se > -1 && f[v][2].se + 1 > f[u][2].se) {change_max_3(u , {v,f[v][2].se + 1}) ;return ;}
}

void dfs(int u , int p) {
    f[u][0] = { u , 0 } ;

    for (auto v : ke[u]) if ( v != p) {
        T[u] ++ ; dfs(v,u) ;
        update(u,v) ;
    }
}

int g[maxN] , Fout[maxN] ;

int find_max_without(int u , int v) {
    if (T[u] <= 1) return 0 ;
    int res = 0 ;
    forinc(i,0,2) if (f[u][i].fi != v)
        maximize(res , f[u][i].se) ;
    return res ;
}

int find_max2_without(int u , int v) {
    if (T[u] <= 2) return 0 ;
    int res = 0 , cnt = 0 ;
    forinc(i,0,2) if (f[u][i].fi != v) {
        res += f[u][i].se ;
        cnt ++ ; if (cnt == 2) break ;
    }
    return res ;
}

void dfs_(int u , int p) {
    if (p != -1) {
        g[u] = max(g[p] + 1 , find_max_without(p,u) + 1) , Fout[u] = Fout[p] ;
        if (T[p] >= 3) maximize(Fout[u] , find_max2_without(p,u)) ;
        if (T[p] >= 2) maximize(Fout[u] , g[p] + find_max_without(p,u)) ;
    }

    for (auto v : ke[u]) if (v != p) dfs_(v,u) ;
}

int ans[maxN] ;

void process () {
    memset(f , -1 , sizeof(f)) ;

    dfs(1,-1) ;
    dfs_(1,-1) ;
    forinc(i,1,n) if (T[i] == 1) ans[i] = f[i][0].se ; else if (T[i] >= 2) ans[i] = f[i][0].se + f[i][1].se ;

    int res = 0 ;
    forinc(i,2,n) maximize(res , Fout[i] + ans[i] + 1) ;

    cout << res << endl ;
}

int main () {
    freopen("DIAMETER.inp" , "r" , stdin) ;
    freopen("DIAMETER.out" , "w" , stdout) ;
    enter () ;
    process () ;
    return 0 ;
}
