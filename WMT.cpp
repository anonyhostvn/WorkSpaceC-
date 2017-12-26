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
#define maxN 1005

template <class _T> bool maximize(_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize(_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

using namespace std ;

int n , m , a[maxN][maxN] ;

void enter () {
    scanf("%d%d" , &m , &n) ;
    forinc(i,1,m) forinc(j,1,n) scanf("%d" , &a[i][j]) ;
}

long long f[maxN][maxN] ;

void prepare () {
    forinc(i,1,m) sort(a[i] + 1 , a[i] + 1 + n) ;
    forinc(i,1,m) forinc(j,1,n) f[i][j] = f[i][j-1] + a[i][j] ;
}

long long solve(int r1 , int r2) {
    if (n == 1) return abs(a[r1][1] - a[r2][1]) ;
    int l = 1 , r = n , res = 0  ;
    while (l <= r) {
        int mid = (l+r) / 2 ;
        if (mid == n) break ;
        if (a[r1][mid + 1] < a[r2][n-mid]) l = mid + 1 ;
        else if (a[r2][n-mid+1] < a[r1][mid]) r = mid - 1 ;
        else {res = mid  ; break ; }
    }

    int median = max(a[r1][res] , a[r2][n-res]) ;

    long long sum = (long long) res * median - f[r1][res] - (long long) (n - res) * median + f[r1][n] - f[r1][res] ;
    sum += (long long) (n-res) * median - f[r2][n-res] - (long long) res * median + f[r2][n] - f[r2][n-res] ;
    return sum ;
}

void process () {
    prepare () ;
    long long res = 0 ;
    forinc(i,1,m-1) forinc(j,i+1,m)
    res += solve(i,j) ;

    cout << res << endl ;
}

int main () {
    freopen("WMT.inp" , "r" , stdin) ;
    freopen("WMT.out" , "w" , stdout) ;
    enter () ;
    process () ;
    return 0  ;
}
