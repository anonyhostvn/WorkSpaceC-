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

int x , y ;

void enter () {
    cin >> x >> y ;
}

#define base 1000000007
#define maxDiv 2005

int m = 0 ;
vector<int> divsor ;
long long g[maxDiv] ;

long long power(int x , int i) {
    if (i == 0) return 1 ;
    if (i == 1) return x ;
    long long tmp = power(x , i / 2) ; tmp *= tmp ; tmp %= base ;
    if (i % 2 == 0) return tmp ; return (tmp * x) % base ;
}

void factor(int x) {
    for (int i = 1 ; i * i <= x ; ++i) if (x % i == 0) {
        divsor.push_back(i) ;
        if (i != x/i) divsor.push_back(x/i) ;
    }
    sort(divsor.begin() , divsor.end()) ;
    m = divsor.size()  ;
    forinc(i,0,m-1) g[i] = power(2,divsor[i]-1) ;
}

void sub(long long &x , long long y) {
    x -= y ; x %= base ;
    x += base ; x %= base ;
}

long long f[maxDiv] ;

long long cal (int i) {
    if (f[i] > -1) return f[i] ;
    if (i == 0) {f[i] = 1 ; return 1 ; }

    long long res = g[i] ;
    fordec(j,i-1,0) if (divsor[i] % divsor[j] == 0) sub(res,cal(j)) ; f[i] = res ;

    return res ;
}

void process () {
    if (y % x != 0) {cout << 0 << endl ; return ; }
    y /= x ; factor(y) ;

    memset(f , -1 , sizeof(f)) ;
    cout << cal(divsor.size() - 1) << endl ;
}

int main ()  {
    //freopen("900D.inp" , "r" , stdin) ;
    enter () ;
    process () ;
    return 0 ;
}
