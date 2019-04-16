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

int n , m ;

int main () {
    //freopen("913.inp" , "r" , stdin) ;
    cin >> n >> m ;

    int cnt = 1 ;
    for ( ; (1 << (cnt + 1)) <= m ; cnt ++ ) ;
    if (cnt < n) cout << m << endl ;
    else cout << m % (int) (1 << n) << endl ;

    return 0 ;
}
