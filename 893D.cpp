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

#define maxN 100005

int n , a[maxN] , d ;
long long money = 0 , sum[maxN]  ;

void enter() {
    cin >> n >> d ;
    forinc(i,1,n) cin >> a[i] ;
}

long long g[maxN] ;

void prepare() {
    forinc(i,1,n) if (a[i] == 0) sum[i] = 0 ; else sum[i] = sum[i-1] + a[i] ;
    fordec(i,n,1) if (a[i] == 0) g[i] = 0 ; else g[i] = max(g[i+1],sum[i]) ;
}

void process () {
    prepare() ;
    forinc(i,1,n) if (sum[i] > d) {cout << -1 ; return ; }
    long long money = 0 ; int res = 0 ;
    forinc(i,1,n) {
        if (a[i] == 0 && money < 0) {
        res ++ ; money = 0 ; money += d - g[i+1] ;
        } else money += a[i] ;
        if (money > d) money = d ;
    }

    cout << res << endl ;
}

int main () {
    //freopen("893D.inp" , "r" , stdin) ;
    enter() ;
    process () ;
    return 0;
}
