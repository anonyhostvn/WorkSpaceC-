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

int n , m , d ;

int fastRead() {
    char c ; int res = 0 ;
    for (c = getchar() ; c < '0' || c > '9' ; c = getchar()) ;
    for ( ; c >= '0' && c <= '9' ; c = getchar()) res *= 10  , res += (int) c - (int) '0' ;
    return res ;
}

void enter () {
    m = fastRead() ; n = fastRead() ; d = fastRead() ;
}

void Ext_Euclid (int a , int b , int& x , int& y) {
    int m = a , n = b , xm = 1 , xn = 0 ;
    while (n > 0) {
        int q = m / n , r = m - q * n , xr = xm - q * xn ;
        m = n ; xm = xn ;
        n = r ; xn = xr ;
    }
    x = xm ; y = (m - xm * a) / b ;
}

int solve (int x , int y) {
    int bot_1 = 0 , bot_2 = 0 , cnt_1 = 0 , cnt_2 = 0 , quanty_1 = 0 , quanty_2 = 0 , csum_1 = 0 , csum_2 = 0 , res = 0  ;
    if (x > 0) bot_1 = m , cnt_1 = x , bot_2 = n , cnt_2 = abs(y) ; else bot_1 = n , cnt_1 = y , bot_2 = m , cnt_2 = abs(x) ;
    while (quanty_1 != d && quanty_2 != d) {
        if (quanty_1 == 0 && csum_1 < cnt_1) quanty_1 += bot_1 , csum_1 ++ , res ++ ;
        else if (quanty_2 == bot_2 && csum_2 < cnt_2) quanty_2 = 0 , csum_2 ++ , res ++ ;
        else {
                int w = min(bot_2-quanty_2,quanty_1) ;
                quanty_2 += w , quanty_1 -= w , res ++ ;
        }
    }


    //return 2 * abs(x) + abs(y) - 1 + min(bot_2,(bot_1 * cnt_1 / bot_2)) ;

    return res ;
}

void process () {
    if (d % __gcd(m,n) != 0 || d > max(m,n)) {cout << -1 << endl ; return ; }
    int x = 0 , y = 0 , p = n / __gcd(m,n) , q = m / __gcd(m,n) ; Ext_Euclid(m,n,x,y) ;
    x *= d / __gcd(m,n) ; y *= d / __gcd(m,n) ;

    int l = -ooit , r = ooit , res = 0 ;
    while (l <= r) {
        int mid = (l + r) / 2 ;
        if ((long long) x + (long long) p * mid <= 0)
            l = mid + 1 , res = mid ; else r = mid - 1 ;
    }

    int ans =  min(solve(x + res * p , y - res * q) , solve(x + (res + 1) * p , y - (res + 1) * q)) ;
    if (ans == ooit) cout << -1 ; else cout << ans ; cout << endl ;
}

int main () {
    freopen("WATERJUG.inp" , "r" , stdin) ;
    freopen("WATERJUG.out" , "w" , stdout) ;
    int t = fastRead() ;
    while (t -- ) enter () , process () ;
    return 0 ;
}
