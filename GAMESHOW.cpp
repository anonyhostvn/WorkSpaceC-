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
#define maxN 5005

template <class _T> bool maximize(_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize(_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

using namespace std ;

int n , a[maxN] , T ;

void enter () {
    cin >>  n  >> T ;
    forinc(i,1,n) cin >> a[i] ;
}

long long f[maxN][maxN] ;

void process () {
    forinc(i,1,n) forinc(j,1,n) f[i][j] = -ooll ;
    f[1][1] = a[1] ;
    forinc(i,1,n) forinc(j,1,i) if (f[i][j] >= 0) {
        if (i + 1 < n) maximize(f[i+1][j],f[i][j] - T) ;
        maximize(f[i+1][j+1],f[i][j] + a[i+1]) ;
    }

    forinc(i,1,n) if (f[n][i] >= 0) { cout << i << endl ; return ;
    } cout << -1 << endl ;
}

int main () {
    freopen("GAMESHOW.inp" , "r" , stdin) ;
    freopen("GAMESHOW.out" , "w" , stdout) ;
    enter () ;
    process () ;
    return 0 ;
}
