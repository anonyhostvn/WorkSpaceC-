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

long long n , pos , Tmod , base ;

struct matrix {
    long long val[2][2] ;

    matrix () {
        memset(val , 0 , sizeof(val)) ;
    }

    matrix operator * (const matrix &other) {
        matrix res ;
        forinc(i,0,1)
        forinc(j,0,1) {
            res.val[i][j] = 0 ;
            forinc(k,0,1) res.val[i][j] += val[i][k] * other.val[k][j] , res.val[i][j] %= Tmod ;
        }
        return res ;
    }

    void print() {
        forinc(i,0,1) {
            forinc(j,0,1) cout << val[i][j] << " " ; cout << endl ;
        }
    }
};

matrix pow(matrix A , long long n) {
    matrix C ;
    forinc(i,0,1) C.val[i][i] = 1 ;
    for ( ; n ; n /= 2 , A = A * A) if (n % 2) C = C * A ;
    return C ;
}

void enter () {
    cin >> n >> pos >> Tmod ;
}

#define maxN 1000005

matrix A , B ;
long long f[maxN] , sum[maxN] ;

void build_fib() {
    A.val[0][0] = 0 ; A.val[0][1] = 1 ;
    B.val[0][0] = 0 ; B.val[0][1] = 1 ; B.val[1][0] = 1 ; B.val[1][1] = 1 ;
    //pos = 5 ; Tmod = 1000000007 ;
    A = A * pow(B,pos) ;
    f[1] = A.val[0][0] ; f[2] = A.val[0][1] ;
    forinc(i,3,n) f[i] = f[i-1] + f[i-2] , f[i] %= Tmod ;
    //forinc(i,1,n) cout << f[i] << " " ; cout << endl ;
    forinc(i,1,n) sum[i] = sum[i-1] + f[i] , sum[i] %= Tmod ;
}

int dd[maxN] ;

void solve(int L , int R) {
    printf("%d " , R-L+1) ;
    forinc(i,L,R) printf("%I64d " , pos + i - 1) ; printf("\n") ;
}

void process () {
    build_fib() ;

    forinc(i,0,Tmod-1) dd[i] = -1 ; dd[sum[0]] = 0 ;
    forinc(i,1,n) if (dd[sum[i]] == -1) dd[sum[i]] = i ; else {solve(dd[sum[i]] + 1 , i) ; return ; }
}

int main () {
    freopen("FIBSEQ.inp" , "r" , stdin) ;
    freopen("FIBSEQ.out" , "w" , stdout) ;
    int t = 0 ; cin >> t ;
    while (t--) enter ()  , process () ;
    return 0 ;
}
