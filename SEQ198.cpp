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
#define maxN 2005

template <class _T> bool maximize(_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize(_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

using namespace std ;

int n , a[maxN] , m ;

void enter() {
    cin >> n ;
    forinc(i,1,n) cin >> a[i] ;
}

vector<pii> b ;

void prepare () {
    sort(a+1,a+1+n) ;
    b.push_back({0,0}) ; b.push_back({a[1],1}) ;
    forinc(i,2,n) if (a[i] != a[i-1]) b.push_back({a[i],1}) ; else b.back().se ++ ;
    m = b.size() - 1 ;
}

int get_bit(int x , int i) {return   (x >> i) & 1 ; }
int on_bit(int x , int i) {return (1 << i) | x ; }
int off_bit(int x , int i) {return x & (~(1 << i)) ; }

#define maxS 1030

int s = 0  , f[maxN][maxS];

int swap_status (int stt , int select) { return ( ((stt << 1) | select) & s) ; }

bool check(int stt , int id) {
    forinc(i,0,8) if (get_bit(stt,i) && (id - i - 1 >= 1)) {
        int tmp = abs(b[id].fi - b[id-1-i].fi) ;
        if (tmp == 1 || tmp == 8 || tmp == 9) return false ;
    }
    return true ;
}

void process () {
    s = (1 << 10) - 1 ;
    prepare () ;
    forinc(i,0,m) forinc(j,0,s) f[i][j] = ooit ;
    f[0][0] = 0 ;
    forinc(i,0,m) forinc(j,0,s) if (f[i][j] < ooit) {
        if (check(j,i+1)) minimize(f[i+1][swap_status(j,1)],f[i][j]) ;
        minimize(f[i+1][swap_status(j,0)],f[i][j] + b[i+1].se) ;
    }
    int res = ooit ;
    forinc(i,0,s) res = min(res,f[m][i]) ;
    cout << res << endl ;
}

int main () {
    freopen("SEQ198.inp" , "r" , stdin) ;
    freopen("SEQ198.out" , "w" , stdout) ;
    enter() ;
    process() ;
    return 0 ;
}

