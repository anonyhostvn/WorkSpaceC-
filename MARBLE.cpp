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

int fastRead() {
    int res = 0 ; char c ;
    for (c = getchar() ; c < '0' || c > '9' ; c = getchar()) ;
    for ( ; c >= '0' && c <= '9' ; c = getchar()) res *= 10 , res += (int) c - (int) '0' ;
    return res ;
}

#define maxN 205
#define maxM 605

int w , h , n ;
pii a[maxN] ;

void enter () {
    w = fastRead() ; h = fastRead() ; n = fastRead();
    forinc(i,1,n) a[i].fi = fastRead() , a[i].se = fastRead() ;
}

int f[maxM][maxM] ;

int cal(int x , int y) {
    if (f[x][y] < ooit) return f[x][y] ;
    forinc(i,1,n) if (a[i].fi == x && a[i].se == y) {f[x][y] = 0 ; return 0 ; }

    int res = x * y  ;
    forinc(i,1,n)  {
        if (a[i].fi < x) minimize(res,cal(a[i].fi,y) + cal(x - a[i].fi, y)) ;
        if (a[i].se < y) minimize(res,cal(x,a[i].se) + cal(x ,y - a[i].se)) ;
    }

    f[x][y] = res ;
    return res ;
}

void process () {
    forinc(i,1,w) forinc(j,1,h) f[i][j] = ooit ;
    cout << cal(w,h) << endl ;
}

int main () {
    freopen("MARBLE.inp" , "r" , stdin) ;
    freopen("MARBLE.out", "w" , stdout) ;
    enter () ;
    process () ;
    return 0 ;
}
