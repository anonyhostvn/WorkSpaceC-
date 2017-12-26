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

const int base = 1000000007 ;

#define maxA 100005

int n , q ;
int g[maxA] ;

void factories(int x){
    for (int i = 2 ; i <= (int) sqrt(x) ; i ++) if (x % i == 0) {
        int cnt = 0 ;
        while (x % i == 0) cnt ++ , x /= i ;
        g[i] += cnt ;
    }
    if (x > 1) g[x] ++ ;
}

void enter () {
    cin >> n >> q ;
    if (n > 5000) exit(0) ;
    forinc(i,1,n) {
        int x ; cin >> x ;
        factories(x) ;
    }
}

vector<pii> a ;
int m ;

void prepare () {
    a.emplace_back(1,1) ;
    forinc(i,2,100000)
        if (g[i] > 0) a.emplace_back(i,g[i]) ;
    m = a.size() - 1 ;
}

#define maxN 5005

long long f[maxN][maxN] ;

long long power(int x , int n) {
    if (n == 0) return 1 ;
    if (n == 1) return x ;
    long long tmp = power(x , n / 2) ;
    if (n % 2 == 0) return (tmp * tmp) % base ; return (((tmp * tmp) % base) * x) % base ;
}

void DP_trau() {
    f[0][0] = 1 ;
    forinc(i,0,m-1) forinc(j,0,200) if (f[i][j])
        forinc(k,0,a[i+1].se)
            if (j + k <= 200)
                f[i+1][j+k] += (f[i][j] * (power(a[i+1].fi,k))) , f[i+1][j+k] %= base ; else break ;
}

void process () {
    prepare () ; DP_trau () ;
    forinc(i,1,q) {
        int y = 0 ; cin >> y ;
        cout << f[m][y] << endl ;
    }
}

int main () {
    //freopen("PRODUCT.inp" , "r" , stdin) ;
    //freopen("PRODUCT.out" , "w" , stdout) ;

    enter () ;
    if (n > 5000) return 0 ;
    process () ;

    return 0 ;
}
