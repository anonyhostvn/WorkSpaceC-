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

int n , m , k ;

void enter () {
    cin >> m >> n >> k ;
}

void sub_1() {
    long long res = 0 ;
    for (int i = 0 ; k * i <= m + n ; i ++ ) {
        int sum = k * i ;
        res += min(n,sum) - max(0,(sum - min(m,sum))) + 1 ;
    }
    cout << res << endl ;
}

int cnt[2][1005] ;

void sub_2() {
    forinc(i,0,k-1) cnt[0][i] = (m / k) + ((m % k < i) ? 0 : 1) , cnt[1][i] = (n / k) + ((n % k < i) ? 0 : 1) ;
    long long res = 0 ;
    forinc(i,0,k-1) res += (long long) cnt[0][i] * cnt[1][(k-i + k) % k] ;
    cout << res << endl ;
}

void process () {
    if (k > 1000) sub_1() ; else sub_2() ;
}

int main () {
    freopen("CPAIRS.inp" , "r" , stdin) ;
    freopen("CPAIRS.out" , "w" , stdout) ;
    enter () ;
    process () ;
    return 0 ;
}
