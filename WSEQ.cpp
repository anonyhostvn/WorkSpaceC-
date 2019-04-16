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

#define maxN 505

int n , m , k ;
long long a[maxN] ;

void enter () {
    cin >> n >> m >> k ;
    forinc(i,1,n) cin >> a[i] ;
}

int get_bit(int x , int i) {
    return (x >> i) & 1 ;
}

int count_bit(int x) {
    int cnt = 0 ;
    while (x > 0) cnt += (x % 2) , x /= 2 ;
    return cnt ;
}

void sub1 () {
    long long sum = 0 , res = ooll ;
    forinc(i,1,n) sum += a[i] ;

    int st = (1 << n) - 1 ;
    forinc(status,0,st) if (count_bit(status) >= n - m) {
        vector<int> num  ;
        forinc(i,0,n-1) if (get_bit(status,i)) num.push_back(i) ;
        forinc(i,0,n-1) if (!get_bit(status,i)) num.push_back(i) ;
        //for (auto tmp : num) cout << tmp << " " ; cout << endl ;
        long long sub = 0 ;
        forinc(i,1,n) if (i % k == 0) sub += a[num[i-1]+1] ;
        minimize(res , sum - sub) ;
    }

    cout << res << endl ;
}

long long f[maxN][maxN] ;

void sub2 () {
    long long sub = -ooll ;

    forinc(snum , 0 , m) {
        forinc(i,0,n) forinc(j,0,n) f[i][j] = -ooll ; f[0][0] = 0 ;
        forinc(i,0,n-1) forinc(j,0,min(i,snum)) if (f[i][j] > -ooll) {
            maximize(f[i+1][j] , f[i][j] + ( ((i-j+1) % k == 0) ? a[i+1] : (long long) 0) );
            if (j < snum) maximize(f[i+1][j+1] , f[i][j] + ( ((n-snum+j+1) % k == 0) ? a[i+1] : (long long) 0 ) );
        }
        maximize(sub , f[n][snum]) ;
    }

    long long res = -sub ;
    forinc(i,1,n) res += a[i] ;
    cout << res << endl ;
}

void process () {
    if (n <= 20) sub1 () ; else sub2 () ;
}

int main () {
    freopen("WSEQ.inp" , "r"  , stdin) ;
    freopen("WSEQ.out" , "w" , stdout) ;
    enter () ;
    process () ;
    return 0 ;
}
