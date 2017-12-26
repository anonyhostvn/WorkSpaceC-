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

int n  , k ;

int main () {
    freopen("PARTY.inp" , "r" , stdin) ;
    freopen("PARTY.out" , "w" , stdout) ;
    cin >> n >> k ;
    long long res = 0 ;
    if (n % 2 == 1) {
        if (k >= n) res = n ; else res = k + 1 ;
    } else {
        if (k >= n / 2) res = n / 2 ; else res = k + 1 ;
    }
    cout << res << endl ;
}
