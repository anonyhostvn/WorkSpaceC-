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

int fastRead() {
    char c ; int res = 0 ;
    for (c = getchar() ; c < '0' || c > '9' ; c = getchar()) ;
    for ( ; c >= '0' && c <= '9' ; c = getchar()) res *= 10  , res += (int) c - (int) '0' ;
    return res ;
}

#define maxN 1000005

int n , m , a[maxN] ;

void enter () {
    n = fastRead() ;
    m = fastRead() ;
    forinc(i,1,n) a[i] = fastRead() ;
    sort(a+1,a+1+n,greater<int>() ) ;
}

long long sum[maxN] , scnt[maxN] ;
vector<pii> b ;

void prepare () {
    b.push_back({a[1],1}) ;
    forinc(i,2,n) if (a[i] == a[i-1]) b.back().se ++ ; else b.push_back({a[i],1}) ;
    sum[0] = (long long) b[0].fi * b[0].se ;
    forinc(i,1,b.size()-1) sum[i] = sum[i-1] + (long long) b[i].fi * b[i].se ;
    scnt[0] = b[0].se ;
    forinc(i,1,b.size()-1) scnt[i] = scnt[i-1] + b[i].se ;
}

void process () {
    prepare () ;

    int cleft = b.size() ;
    forinc(i,1,b.size()-1) if (sum[i-1] - (long long) scnt[i-1] * b[i].fi >= m) {cleft = i; break ; }
    cleft -- ;

    long long res = (cleft == 0) ? 0 : sum[cleft-1] - (long long) scnt[cleft-1] * b[cleft].fi ;
    int ans = ceil((long double) (m - res) / (scnt[cleft])) ;

    cout << b[cleft].fi - ans ;
}

int main () {
    freopen("blade.inp" , "r" , stdin) ;
    freopen("blade.out" , "w" , stdout) ;
    enter ()  ;
    process () ;
    return 0 ;
}
