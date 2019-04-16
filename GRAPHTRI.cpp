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

#define maxN 100005

int n , m1 , m2 , m3 ;
vector<pii> edge ;
vector<int> ke[maxN] ;
map<int,int> f[maxN] ;

void enter () {
    n = fastRead() ;
    m1 = fastRead() ;
    forinc(i,1,m1) {
        int u = fastRead() , v = fastRead() ;
        edge.push_back({u,v}) ;
    }
    m2 = fastRead() ;
    forinc(i,1,m2) {
        int u = fastRead() , v = fastRead() ;
        ke[u].push_back(v) ; ke[v].push_back(u) ;
    }
    m3 = fastRead() ;
    forinc(i,1,m3) {
        int u = fastRead() , v = fastRead() ;
        f[u][v] = 0 ;
        f[v][u] = 0 ;
    }
}

void process () {
    int res = 0 ;

    for (auto tmp : edge) {
        int a = tmp.fi , b = tmp.se ;
        for (auto c : ke[b]) if (c != a && f[c].find(a) != f[c].end()) res ++ ;
        swap(a,b) ;
        for (auto c : ke[b]) if (c != a && f[c].find(a) != f[c].end()) res ++ ;
    }

    cout << res << endl ;
}

int main () {
    freopen("GRAPHTRI.inp" , "r" , stdin) ;
    freopen("GRAPHTRI.out" , "w" , stdout) ;
    enter () ;
    process () ;
    return 0 ;
}
