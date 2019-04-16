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
#define pli pair<long long , int>

template <class _T> bool maximize(_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize(_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

const int ooit = 2e9 ;
const long long ooll = 1e15 ;

using namespace std ;

long long k , pa , pb ;

void enter () {
    cin >>  k >> pa >> pb ;
}

#define base 1000000007

long long qpower(long long x , int n) {
    if (n == 0) return x ;
    long long res = 1 ;
    for ( ; n ; n >>= 1 , x *= x , x %= base) if (n & 1) res *= x , res %= base;
    return res % base ;
}

#define maxN 1005

long long f[maxN][maxN] ;

void process () {
    long long inv = qpower(pa + pb , base - 2)  , res = 0 ;
    f[1][0] = 1 ;

    forinc(i,1,k) forinc(j,0,k) if (f[i][j]) {
        if (i + j >= k) res += f[i][j] * (i + j + pa * qpower(pb , base - 2) % base) % base , res %= base ;
        else {
            f[i+1][j] += ((f[i][j] * pa) % base * inv) % base ; f[i+1][j] %= base ;
            f[i][i+j] += ((f[i][j] * pb) % base * inv) % base ; f[i][i+j] %= base ;
        }
    }

    cout << res << endl ;
}

int main ()  {
    //freopen("908D.inp" , "r" , stdin) ;
    enter () ;
    process () ;
    return 0 ;
}
