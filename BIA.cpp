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

template <class _T> bool maximize(_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize(_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

using namespace std ;

const long double pi = 3.141592654 ;

long long a , b , s , m , n ;

void enter () {
    if (a == 0 && b == 0 && s == 0 && m == 0 && n == 0) return ;
    long double res_1 = atan(((long double) (n * b)) / ((long double) m * a)) ;
    res_1 *= (long double) 180 / pi ;
    long double res_2 = sqrt(n * b * n * b + m * a * m * a)  ;
    res_2 /= (long double) s ;
    cout << fixed <<setprecision(2) << res_1 << " " << res_2 << endl ;
}

int main () {
    freopen("BIA.inp" , "r" , stdin) ;
    freopen("BIA.out" , "w" , stdout) ;
    while (cin >> a >> b >> s >> m >> n ) enter () ;
    return 0 ;
}

