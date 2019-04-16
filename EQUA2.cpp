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

#define maxN 2005

long long n , k , m ;

int fastRead() {
    char c ; int res = 0 ;
    for (c = getchar() ; c < '0' || c > '9' ; c = getchar()) ;
    for ( ; c >= '0' && c <= '9' ; c = getchar()) res = (res << 3) + (res << 1) , res += c - '0' ;
    return res ;
}

void enter () {
    n = fastRead() ; k = fastRead() ; m = fastRead() ;
    forinc(i,1,k) {
        int x = fastRead() ; n -= x ;
    }
}

bool prime[2000] ;
vector<int> sprime ;

void estharone(int n) {
    for (int i = 2 ; i * i <= n ; i ++ ) if (!prime[i])
        for (int j = i * i ; j <= n ; j += i) prime[j] = true ;
    forinc(i,2,n) if (!prime[i]) sprime.push_back(i) ;
}

map<int,int> cnt ;

void factor(int x , int p ) {
    for (int i = 0 ; sprime[i] * sprime[i] <= x ; i ++ ) if (x % sprime[i] == 0) {
        int c = 0 ; while (x % sprime[i] == 0) c ++ , x /= sprime[i] ;
        cnt[sprime[i]] += p * c ;
    }
    if (x > 1) cnt[x] += p * 1 ;
}

long long power(long long x , int n) {
    int res = 1 ;
    for ( ; n ; n >>= 1 , x *= x , x %= m) if (n & 1) res *= x , res %= m ;
    return res ;
}

long long Combinatori (long long k , long long n) {
    forinc(i,n-k+1,n) factor(i,1) ; forinc(i,2,k) factor(i,-1) ;
    long long res = 1 ;
    for (auto tmp : cnt) res *= power(tmp.fi , tmp.se) , res %= m ;
    return res ;
}

void optimize () {
    estharone((int) sqrt(2000000)) ;
    cout << Combinatori(k-1 , n + k - 1) << endl ;
}

int main () {
    freopen("EQUA2.inp" , "r" , stdin) ;
    freopen("EQUA2.out" , "w" , stdout) ;
    enter () ;
    optimize () ;
    return 0 ;
}
