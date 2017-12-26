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

int n , s ;

void enter() {
    cin >> n >> s ;
    long long sum = (long long) n * (n+1) / 2 ;
    if (s > sum) {cout << 0 << endl ; return ; }
    if (abs(sum) % 2 != abs(s) % 2 ) {cout << 0 << endl ; return ; }
    cout << 1 << endl ;
}

int main () {
    freopen("operator.inp" , "r" , stdin) ;
    freopen("operator.out" , "w" , stdout) ;
    int t = 0 ; cin >> t ;
    while (t--) enter () ;
    return 0 ;
}
