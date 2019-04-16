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

#define maxN 1005

int n , r , a[maxN] ;

void enter () {
    cin >> n >> r ;
    forinc(i,1,n) cin >> a[i] ;
}

long double res[maxN] ;

void solve(int id) {
    long double maxY = -1 ;
    forinc(i,1,id-1) if (4 * r * r >= (a[id] - a[i]) * (a[id] - a[i])) maximize(maxY , sqrt(4*r*r - (a[id] - a[i]) * (a[id] - a[i])) + res[i]) ;
    if (maxY == -1) res[id] = r ; else res[id] = maxY ;
}

void process () {
    forinc(i,1,n) solve(i) ;
    forinc(i,1,n) cout << fixed << setprecision(10) << res[i] << " " ;
}

int main () {
    //freopen("908.inp" , "r" , stdin ) ;
    enter () ;
    process () ;
    return 0 ;
}
