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
#define maxN 1005

template <class _T> bool maximize(_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize(_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

using namespace std ;

int n , m , d , f[maxN][maxN]  ;

void enter () {
    cin >> m >> n >> d ;
}

queue<pii> q ;

inline void bfs() {
    forinc(i,0,m) forinc(j,0,n) f[i][j] = ooit ;
    f[0][0] = 0 ; q.push({0,0}) ;

    while (!q.empty()) {
        auto tmp = q.front() ; q.pop() ;
        int u = tmp.fi , v = tmp.se ;
        if (f[0][v] == ooit) f[0][v] = f[u][v] + 1 , q.push({0,v}) ;
        if (f[u][0] == ooit) f[u][0] = f[u][v] + 1 , q.push({u,0}) ;
        if (f[m][v] == ooit) f[m][v] = f[u][v] + 1 , q.push({m,v}) ;
        if (f[u][n] == ooit) f[u][n] = f[u][v] + 1 , q.push({u,n}) ;
        if (u < m) {
            int w = min(m-u,v) ;
            if (f[u+w][v-w] == ooit) f[u+w][v-w] = f[u][v] + 1 , q.push({u+w,v-w}) ;
        }
        if (v < n) {
            int w = min(n-v,u) ;
            if (f[u-w][v+w] == ooit) f[u-w][v+w] = f[u][v] + 1 , q.push({u-w,v+w}) ;
        }
    }
}

void sub_1() {
    bfs() ;

    int res = ooit ;
    if (n >= d) forinc(i,0,m) minimize(res,f[i][d]) ;
    if (m >= d) forinc(i,0,n) minimize(res,f[d][i]) ;

    if (res < ooit) cout << res << endl ; else cout << -1 << endl ;
}

int main () {
    freopen("waterjug.inp" , "r" , stdin) ;
    //freopen("waterjug.out" , "w" , stdout) ;
    int t =0  ; cin >> t ;
    while (t--) enter () , sub_1() ;
    return 0 ;
}
