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

#define maxN 100005

int n , m , a[maxN] ;

void enter () {
    cin >> n ;
    forinc(i,1,n) {
        char c ; cin >> c ; a[i] = (c == '?') ? 2 : (int) c - (int) 'a' ;
    }
    cin >> m ;
}

int b[2][maxN] ;

void Build_standard_string() {
    forinc(i,1,n) b[0][i] = (i % 2) , b[1][i] = (i+1) % 2 ;
}

int f[3][maxN] ;

void prepare () {
    Build_standard_string() ;
    forinc(i,1,n) {
        f[0][i] = f[0][i-1] + ((a[i] == 2 || a[i] == b[0][i]) ? 0 : 1) ;
        f[1][i] = f[1][i-1] + ((a[i] == 2 || a[i] == b[1][i]) ? 0 : 1) ;
        f[2][i] = f[2][i-1] + (int) (a[i] == 2) ;
    }
}

int check(int i) {
    if (f[i % 2][i+m-1] - f[i % 2][i-1] > 0) return -1 ;
    return f[2][i+m-1] - f[2][i-1] ;
}

int dp[maxN] ;

int solve_dp() {
    memset(dp , -1 , sizeof(dp)) ; dp[0] = 0 ;
    forinc(i,0,n) if (dp[i] > -1) {
        if (i + 1 <= n) maximize(dp[i+1] , dp[i]) ;
        if (i + m <= n && check(i+1) > -1) maximize(dp[i+m] , dp[i] + 1) ;
    }
}

int cp[maxN] ;

int cal(int i) {
    if (cp[i] < ooit) return cp[i] ;
    if (i == 0) {cp[i] = 0 ; return 0 ; }

    int res = ooit ;
    if (dp[i-1] == dp[i]) minimize(res , cal(i-1)) ;
    if (i >= m && check(i-m+1) > -1 &&  dp[i-m] + 1 == dp[i]) minimize(res , cal(i-m) + check(i-m+1)) ;
    cp[i] = res ;
    return res ;
}

void process () {
    prepare () ;
    solve_dp() ;

    forinc(i,0,n+1) cp[i] = ooit ;
    cout << cal(n) << endl ;
}

int main () {
    //freopen("900E.inp" , "r" , stdin) ;
    enter () ;
    process () ;
    return 0 ;
}
