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
const long long ooll = 2e18 ;

using namespace std ;

#define maxN 35

const int maxA = 1000000000 ;

int n , L ;
long long f[maxN] , c[maxN] , g[maxN] ;

int get_bit(int x , int i) {
    return (x >> i) & 1 ;
}

int main () {
    //freopen("913.inp" , "r" , stdin) ;

    forinc(i,0,30) c[i] = ooll ;

    cin >> n >> L ;
    forinc(i,1,n) cin >> c[i-1] ;

    f[0] = c[0] ;
    forinc(i,1,30) f[i] = min(c[i] , f[i-1] + f[i-1]) ;
    forinc(i,0,30) g[i] = ooll ;

    g[0] = (get_bit(L,0)) ? f[0] : 0 ;
    forinc(i,0,29) if (g[i] < ooll) {
        if (!get_bit(L,i+1)) minimize(g[i+1] , min(g[i] , f[i+1])) ;
        else minimize(g[i+1] , g[i] + f[i+1]) ;
    }

    cout << g[30] << endl ;

    return 0 ;
}
