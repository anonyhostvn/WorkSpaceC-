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

#define maxN 100005

int n , a[maxN] ;
vector<int> ke[maxN] ;
bool sub2 = true ;

void enter () {
    cin >> n ;
    forinc(i,1,n) {
        cin >> a[i] ;
        if (a[i] != a[1]) sub2 = false ;
    }
    forinc(i,1,n-1) {
        int u , v ; cin >> u >> v ;
        ke[u].push_back(v) ; ke[v].push_back(u) ;
    }
}

map<int,int> f ;

long long res = 0 ;

void dfs(int u , int p) {
    f[a[u]] ++ ;
    res += f.size() ;
    for (auto v : ke[u]) if (v != p) dfs(v,u) ;

    f[a[u]] -- ;
    if (f[a[u]] == 0) f.erase(a[u]) ;
}

void sub1() {
    res = 0 ;

    forinc(i,1,n) {
        res = 0 ; f.clear() ;
        dfs(i,-1) ;
        cout << res << endl ;
    }
}

void tsub2() {
    forinc(i,1,n) cout << n << endl ;
}


///======================================================================================================================================================
///                                                               Lam sub3
///======================================================================================================================================================

int S[maxN] , T[maxN] ;

void visit(int u , int p){
    S[u] = 1 ;
    for (auto v : ke[u]) if (v != p) visit(v,u) , S[u] += S[v] ;
    T[u] = n - S[u] ;
}

long long fs[maxN] , gt[maxN] ;

void dp(int u , int p) {
    fs[u] = 1 ;
    for (auto v : ke[u]) if (v != p) dp(v,u) , fs[u] += fs[v] + S[v] ;

}

void dp2(int u , int p) {
    if (p > 1) gt[u] += gt[p] + T[p] ;
    if (p > -1) gt[u] += fs[p] - (fs[u] + S[u])  + n - T[p] - S[u] ;
    for (auto v : ke[u]) if (v != p) dp2(v,u) ;
}

void tsub3 () {
    visit(1,-1) ;
    dp(1,-1) ;
    dp2(1,-1) ;
    forinc(i,1,n) {
        cout << fs[i] + gt[i] << endl ;
    }
}


///======================================================================================================================================================
///                                                               Xu Ly
///======================================================================================================================================================

void process () {
    if (n <= 5000) sub1() ; else if (sub2) tsub2() ; else tsub3() ;
}


int main () {
    freopen("COLORGRAPH.inp" , "r" , stdin) ;
    freopen("COLORGRAPH.out" , "w" , stdout) ;
    enter () ;
    process () ;
    return 0 ;
}
