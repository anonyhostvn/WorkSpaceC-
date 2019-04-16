#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)
#define forv(j,u) for (int j = 0 ; j < u.size() ; j++)
#define fi first
#define se second
#define pii pair<int,int>
#define pli pair<long long , int>

template <class _T> bool maximize(_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize(_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

const int ooit = 2e9 ;
const long long ooll = 1e15 ;

using namespace std ;

long long n , k ;

int main () {
    cin >> n >> k ;

    if (k == 1) { cout << n << endl ; return 0 ; }

    long long tmp = 0 ;
    for ( ; ((long long) 1 << (tmp + 1)) <= n ; tmp ++) ;

    long long res = ((long long) 1 << (tmp + 1)) - 1 ;
    cout << res << endl ;

    return 0 ;
}
