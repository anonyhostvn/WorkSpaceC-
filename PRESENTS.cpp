#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)
#define forv(j,u) for (int j = 0 ; j < u.size() ; j++)
#define fi first
#define se second
#define pii pair<int,int>

template <class _T> bool maximize(_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize(_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

const int ooit = 2e9 ;
const long long ooll = 1e15 ;
const int base = 1000000007 ;

using namespace std ;

int fastRead() {
    char c ; int res = 0 ;
    for (c = getchar() ; c < '0' || c > '9' ; c = getchar()) ;
    for ( ; c >= '0' && c <= '9' ; c = getchar()) res*= 10 , res += c - '0' ;
    return res ;
}

#define maxN 205

int n , a[maxN] , b[maxN] ;

void enter () {
    n = fastRead() ;
    forinc(i,1,n) a[i] = fastRead() ;
    forinc(i,1,n) b[i] = fastRead() ;
}

///========================================================================================================================================================
///                                     SUB 1
///========================================================================================================================================================

int get_bit(int x , int i) {return (x >> i) & 1 ; }

void sub1 () {
    int status = (1 << n) - 1 ;

    forinc(s , 0 , status) {
        int suma_1 = 0 , suma_2 = 0 , sumb_1 = 0 , sumb_2 = 0 ;
        forinc(i,1,n) if (get_bit(s , i-1)) suma_1 += a[i] , sumb_1 += b[i] ; else suma_2 += a[i] , sumb_2 += b[i] ;
        if (suma_1 > suma_2 && sumb_1 < sumb_2) {
            cout << "YES" << endl ;
            forinc(i,1,n) if (get_bit(s , i-1)) cout << i << " " ; cout << endl ;
            forinc(i,1,n) if (!get_bit(s , i-1)) cout << i << " " ; cout << endl;
            return ;
        }
    }

    cout << "NO" << endl ;
}

///========================================================================================================================================================
///                                 SUB 2
///========================================================================================================================================================

#define maxS 40005

int f[maxN][2 * maxS] , trc[maxN][2 * maxS] ;
vector<int> X , Y ;

void trace(int i , int sum) {
    if (i == 0) return ;
    if (trc[i][sum] == 1) X.push_back(i) , trace(i-1 , sum - a[i]); else Y.push_back(i) , trace(i-1 , sum + a[i]) ;
}

void sub2 () {
    forinc(i,0,n) forinc(j,0,80000) f[i][j] = ooit ;
    f[0][40000]  = 0 ;

    forinc(i,0,n-1) forinc(s , 0 , 80000) if (f[i][s] < ooit) {
        if (minimize(f[i+1][s + a[i+1]] , f[i][s] + b[i+1])) trc[i+1][s + a[i+1]] = 1 ;
        if (minimize(f[i+1][s - a[i+1]] , f[i][s] - b[i+1])) trc[i+1][s - a[i+1]] = -1 ;
    }

    bool ok = false ;
    forinc(i,40001 , 80000) if (f[n][i] < 0) {trace(n,i) ; ok = true ; break ; }

    if (!ok) cout << "NO" << endl ; else {
        cout << "YES" << endl ;
        sort(X.begin() , X.end()) ; sort(Y.begin() , Y.end()) ;
        for (auto tmp : X) cout << tmp << " " ; cout << endl ;
        for (auto tmp : Y) cout << tmp << " " ; cout << endl ;
    }
}

///========================================================================================================================================================
///                                         PROCESS
///========================================================================================================================================================

void process () {
    if (n <= 20) sub1 () ; else sub2 () ;
    //sub2 () ;
}

int main () {
    //freopen("Test.inp" , "r" , stdin) ;
    freopen("PRESENTS.inp" , "r" , stdin) ;
    freopen("PRESENTS.out" , "w"  , stdout) ;
    enter () ;
    process () ;
    return 0 ;
}
