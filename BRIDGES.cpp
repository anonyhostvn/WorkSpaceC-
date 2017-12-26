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

#define maxN 1000005

int n , a[maxN] ;
long long cleft[maxN] , cright [maxN] , csum[maxN] ;

void enter () {
    scanf("%d" , &n) ;
    forinc(i,1,n) scanf("%d" , &a[i]) ;
}

int Even(int x) {return (x % 2 == 0) ? x : x - 1 ; }
int Odd (int x) {return (x % 2 != 0) ? x : x - 1 ; }

void prepare () {
    cleft[1] = 0 ;
    forinc(i,2,n) cleft[i] = (a[i-1] == 1) ? 0 : cleft[i-1] + Even(a[i-1]) ;
    cright[n] = 0 ;
    fordec(i,n-1,1) cright[i] = (a[i] == 1) ? 0 : cright[i+1] + Even(a[i]) ;
    forinc(i,2,n) csum[i] = csum[i-1] + Odd(a[i-1]) ;
}

void process () {
    prepare () ;
    long long res = 0 , imax = 0 ;
    forinc(i,1,n) {
        imax = max(imax,cleft[i] - csum[i]) ;
        maximize(res,imax + cright[i] + csum[i]) ;
    }
    cout << res << endl ;
}

int main () {
    freopen("BRIDGES.inp" , "r" , stdin) ;
    freopen("BRIDGES.out" , "w" , stdout) ;
    enter () ;
    process () ;
    return 0 ;
}
