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
#define maxN 105

template <class _T> bool maximize(_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize(_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

using namespace std ;

int n , a[maxN] ;

int enter() {
    cin >> n ;
    forinc(i,1,n) cin >> a[i] ; forinc(i,1,n) ;
    int res = 0 ;
    forinc(i,1,n-1)  forinc(j,i + 1,n) res = max(res,a[i] + a[j]) ;
    int cnt = 0  ;
    forinc(i,1,n-1) forinc(j,i+1,n) if (a[i] + a[j] == res) cnt ++ ;
    cout << fixed << setprecision(8) << (long double) cnt / ((long double) n * (n-1) / 2) << endl ;
}

int main () {
    //freopen("Test.inp" , "r" , stdin) ;
    int t = 0 ; cin >> t ;
    while (t--) enter() ;
    return 0 ;
}
