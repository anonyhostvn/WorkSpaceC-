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
#define base 1000000007

int n , lab[maxN] ;

int get_root(int u) {
    if (u == lab[u]) return u ;
    lab[u] = get_root(lab[u]) ;
    return lab[u] ;
}

void _union(int u , int v) {
    if (get_root(u) == get_root(v)) return ;
    lab[get_root(u)] = get_root(v) ;
    get_root(u) ;
}

void enter () {
    cin >> n ;
    forinc(i,1,n) lab[i] = i ;

    forinc(i,1,n-1) {
        int u , v ; char c ; cin >> u >> v >> c ;
        if (c == 'b') _union(u,v) ;
    }
}

int _cnt[maxN] , m = 0 ;
long long f[maxN] , f2[maxN] , g[maxN] ;
vector<int> comp ;

void build_arr() {
    f[0] = comp[0] ; forinc(i,1,m-1) f[i] = f[i-1] + comp[i] ;
    forinc(i,0,m-1) f2[i] = (f[m-1] - f[i]) * comp[i] , f2[i] %= base ;
    g[m-1] = f2[m-1] ; fordec(i,m-2,0) g[i] = g[i+1] + f2[i] , g[i] %= base ;
}

void prepare () {
    forinc(i,1,n) _cnt[get_root(i)] ++ ;
    forinc(i,1,n) if (_cnt[i] > 0) comp.push_back(_cnt[i]) ;
    m = comp.size() ;
    build_arr() ;
}

void process () {
    prepare () ;
    long long res = 0 ;
    forinc(i,0,m-3) res += comp[i] * g[i+1] , res %= base ;
    cout << res << endl ;
}

int main () {
    freopen("TREECOLOR.inp" , "r" , stdin) ;
    freopen("TREECOLOR.out" , "w" , stdout) ;
    enter () ;
    process () ;
    return 0 ;
}
