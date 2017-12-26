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

#define maxN 1000005
#define base 1000000007

long long n , m , p[maxN] ;
int a[maxN] , cnt ;

void prepare () {
    p[0] = 1 ;
    forinc(i,1,1000000) p[i] = p[i-1] * 2 , p[i] %= base ;
}

long long fastRead() {
    long long res = 0 ;    char c ;
    for (c = getchar() ; c < '0' || c > '9' ; c = getchar()) ;
    for ( ; c >= '0' && c <= '9' ; c = getchar()) res *= 10 , res += (int) c - (int) '0';
    return res ;
}

void enter () {
    cnt = 0 ;
    //cin >> n >> m ;
    n = fastRead() ; m = fastRead() ;

    long long l = 0  , r = m+1 , res = 0 ;
    while (l <= r) {
        long long mid = (l+r) / 2;
        if ((long double) mid / 2  >= (long double) m / (mid -1) ) res = mid ,  r = mid - 1 ; else l = mid + 1 ;
    }

    forinc(i,1,n-res) a[++cnt] = i ;
    int num = n - ((long long) ((res-1) * res) / 2 - m) ; a[++cnt] = num ;
    fordec(i,n,n-res+1) if (i != num) a[++cnt] = i ;

    res = 0 ;
    forinc(i,1,n) res += ((long long) a[i] * p[i-1]) , res %= base ;
    cout << res << endl ;
}

int main (){
    freopen("INVERSION.inp" , "r" , stdin) ;
    freopen("INVERSION.out" , "w" , stdout) ;
    prepare () ;
    int t = fastRead()  ; //cin >> t ;
    while (t -- ) enter () ;
    return 0 ;
}
