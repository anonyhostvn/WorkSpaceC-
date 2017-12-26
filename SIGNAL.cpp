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
#define maxN 200005

template <class _T> bool maximize(_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize(_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

using namespace std ;

int n , b ;
long long a[maxN] ;

void enter  () {
    scanf("%d%d" , &n , &b) ;
    forinc(i,1,n) scanf("%lld" , &a[i]) ;
}

long long f[maxN] , g[maxN] ;

void prepare () {
    forinc(i,1,n) f[i] = max(f[i-1],a[i]) ;
    fordec(i,n,1) g[i] = max(g[i+1],a[i]) ;
}

void process () {
    prepare() ;
    long long res = -1 ;
    forinc(i,2,n-1) if (f[i-1] - a[i] >= b && g[i+1] - a[i] >= b) maximize(res,f[i-1] - a[i] + g[i+1] - a[i]) ;
    if (res == -1) printf("%d\n" , -1) ; else printf("%lld\n" , res) ;
}

int main () {
    freopen("SIGNAL.inp" , "r" , stdin) ;
    freopen("SIGNAL.out" , "w" , stdout) ;
    enter () ;
    process () ;
    return 0 ;
}
