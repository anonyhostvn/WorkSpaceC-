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

int n ;

void enter () {
    cin >> n ;

    long long max_sum = n + n - 1 , p = 0 , pow10 = 1 ;
    for ( ; p * 10 + 9 <= max_sum ; p *= 10 , p += 9) pow10 *= 10 ;
    if (p == max_sum) {cout << 1 << endl ; return ; }

    long long res = 0 ;
    forinc(i,0,8) {
        if (p <= n + 1) res += (p -1) / 2 ;
        else if (p <= n + n -1) res += (2 * n - p + 1) / 2 ; else break ;
        p += pow10 ;
    }

    cout << res << endl ;
}

int main () {
    //freopen("899D.inp" , "r" , stdin) ;
    enter () ;
    return 0 ;
}
