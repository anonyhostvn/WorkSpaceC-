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

#define maxN 1005

int n , a[maxN] ;

void enter () {
    cin >> n ;
    forinc(i,1,n) cin >> a[i] ;
}

long long f[maxN][maxN] ;

long long cal(int i , int j) {
    if (i > j) return 0 ;
    if (f[i][j] > 0) return f[i][j] ;
    if (i == j) {f[i][j] = a[i] ; return f[i][j] ; }

    long long res = 0 ;

    maximize(res,a[i] + cal(i + 1 , j)) ;
    maximize(res,a[j] + cal(i , j - 1)) ;
    maximize(res,(long long) a[i] * a[i+1] + cal(i+2,j)) ;
    maximize(res,(long long) a[j-1] * a[j] + cal(i,j-2)) ;

    f[i][j] = res ;
    return res ;
}

void process () {
    cout << cal(1,n) << endl ;
}

int main () {
    freopen("MAXSUM.inp" , "r" , stdin) ;
    freopen("MAXSUM.out" , "w" , stdout) ;
    enter () ;
    process () ;
    return 0 ;
}
