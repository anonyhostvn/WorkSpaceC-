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
#define maxN 300005

template <class _T> bool maximize(_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize(_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

using namespace std ;

int n , a ,b ;
pii c[maxN] ;

void enter() {
    cin >> n >> a >> b ;
    forinc(i,1,n) cin >> c[i].fi >> c[i].se ;
}

int f[maxN] ,  g[maxN] ;

void process () {
    sort(c+1,c+1+n) ;
    forinc(i,1,n) f[i] = f[i-1] + (c[i].se == 1) ,g[i] = g[i-1] + (c[i].se == 2) ;
    int j = 1 , res = ooit ;
    forinc(i,1,n) {
        while (j <= n && (f[j] - f[i-1] < a || g[j] - g[i-1] < b)) j ++ ;
        if (j <= n) res = min(res,c[j].fi - c[i].fi) ; else break ;
    }
    cout << (res == ooit ? -1 : res) << endl ;
}

int main() {
    freopen("MINROAD.inp" , "r" , stdin) ;
    freopen("MINROAD.out" , "w" , stdout) ;
    enter() ;
    process () ;
    return 0 ;
}
