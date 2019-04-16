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

#define maxN 505

int a[maxN][maxN] , n ;

void enter () {
    cin >> n ;
    forinc(i,1,n) forinc(j,1,n) cin >> a[i][j] ;
}

int d[maxN][maxN] ;

#define ooit (int) 1e9

void prepare () {
    forinc(i,1,n) forinc(j,1,n) d[i][j] = ooit ;
    forinc(k,0,n)
        forinc(i,1,n) forinc(j,1,n) if (i != j) minimize(d[k+1][j] , d[k][i] + a[i][j]) ;
}

bool operator > (const pii &a , const pii &b) {return (long long) a.fi * b.se > (long long) a.se * b.fi ; }
bool operator < (const pii &a , const pii &b) {return (long long) a.fi * b.se < (long long) a.se * b.fi ; }

void process () {
    prepare () ;

    pii res = {ooit , 1} ;
    forinc(i,1,n) {
        pii tmp = {d[n][i] - d[n-1][i] , 1} ;
        forinc(k,0,n-2) if (tmp < (pii) {d[n][i] - d[k][i] , n - k}) tmp = {d[n][i] - d[k][i] , n - k} ;
        if (res > tmp) res = tmp ;
    }

    int g = __gcd(res.fi , res.se) ;
    cout << res.fi / g << '/' << res.se / g << endl ;
}

int main () {
    freopen("GRAPHH.inp" , "r" , stdin) ;
    freopen("GRAPHH.out" , "w" , stdout) ;
    enter () ;
    process () ;
    return 0 ;
}
