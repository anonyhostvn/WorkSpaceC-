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

int n ;
long long a[maxN] ;

void enter () {
    //cin >> n ;
    scanf("%d" , &n) ;
    forinc(i,1,n)  scanf("%lld" , &a[i]) ;
    //cin >> a[i] ;
}

int get_bit(int s , int i) { return (s >> i) & 1 ; }

void sub1() {
    int k = (1 << n) - 1 , res = 0 ;
    forinc(s,0,k) {
        long long Tlast = -1 ; int cnt = 0 ;
        forinc(i,1,n) if (get_bit(s , i-1) && (Tlast == -1 || (a[i] > Tlast && __gcd(Tlast,a[i]) == 1)) ) Tlast = a[i] , cnt ++ ;
        maximize(res , cnt) ;
    }
    cout << res << endl ;
}

int dp[maxN] ;

void sub2 () {
    forinc(i,1,n) dp[i] = -1 ; dp[0] = 0 ;
    forinc(i,0,n) if (dp[i] > -1)
        forinc(j, i + 1 , n) if (i == 0 || (a[j] > a[i] && __gcd(a[j] , a[i]) == 1)) maximize(dp[j] , dp[i] + 1) ;
    int res = 0 ;
    forinc(i,1,n) maximize(res , dp[i]) ;
    cout << res << endl ;
}

///===========================================================================================================================================================
///                                                     Sub 3
///===========================================================================================================================================================

vector<int> prime ;

void build() {
    prime.push_back(2) ; prime.push_back(3) ;prime.push_back(5) ; prime.push_back(7) ; prime.push_back(11) ;
}

int on_bit(int x , int i) { return (1 << i) | x ; }

int get_sta(long long x) {
    int res = 0 ;
    forv(i,prime) if (x % prime[i] == 0) res = on_bit(res , i) ;
    return res ;
}

int stt[maxN] ;

void prepare () {
    map<int,int> p ; p.clear() ;
    forinc(i,1,n) stt[i] = get_sta(a[i]) , p[a[i]] = 0 ;
    //forinc(i,1,n) cout << stt[i] << " " ; cout << endl ;
    int cnt = 0 ;  for (auto& tmp : p) tmp.se = ++cnt ;
    forinc(i,1,n) a[i] = p[a[i]] ;

    //forinc(i,1,n) cout << stt[i] << " " ; cout << endl ;
}

struct TBIT_tree {
    int val[maxN] ;

    void update(int i , int x) {
        for ( ; i <= n ; i += i & -i) maximize(val[i] , x) ;
    }

    int get(int i) {
        int res = 0 ;
        for ( ; i > 0 ; i -= i & -i) maximize(res , val[i]) ;
        return res ;
    }
} tree[40] ;

int f[maxN] ;

void sub3() {
    build() ; prepare () ;

    int s = (1 << 5) - 1 ;

    forinc(i,1,n) {
        forinc(j , 0 , s) if ((stt[i] & j) == 0) {
            int tmp = tree[j].get(a[i]-1) ;
            maximize(f[i] , tmp + 1) ;
        }
        tree[stt[i]].update(a[i] , f[i]) ;
    }

    int res  = 0 ;
    forinc(i,1,n) maximize(res , f[i]) ;
    cout << res << endl ;
}

///===========================================================================================================================================================
///===========================================================================================================================================================

void process () {
    if (n <= 20) sub1 () ; else if (n <= 5000) sub2 () ; else sub3 () ;
}

int main () {
    //freopen("Test.inp" , "r" , stdin) ;
    freopen("COPRIME.inp" , "r" , stdin) ;
    freopen("COPRIME.out" , "w" , stdout) ;
    enter () ;
    process () ;
    return 0 ;
}
