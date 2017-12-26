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
    char c ; int res = 0 ;
    for (c = getchar() ; c < '0' || c > '9' ; c = getchar()) ;
    for ( ; c >= '0' && c <= '9' ; c = getchar()) res *= 10  , res += (int) c - (int) '0' ;
    return res ;
}

#define maxN 100005

int n , c , a[maxN] ;

void enter () {
    n = fastRead() ; c = fastRead() ;
    forinc(i,1,n) a[i] =fastRead() ;
    sort(a+1,a+1+n) ;
}

int g[maxN] , f[maxN] ;

bool check(int x) {
    int cnt = 1 , j = 1 ;
    forinc(i,2,n) if (a[i] - a[j] >= x) {
        cnt ++ ; j = i ;
    }
    return cnt >= c ;
}

void process () {
    int l = 1 , r = (a[n] - a[1]) / (c-1) + 1 , res = 0 ;
    while (l <= r) {
        int mid = (l+r) / 2 ;
        if (check(mid)) l = mid + 1 , res = mid ; else r = mid - 1 ;
    }
    printf("%d\n" , res) ;
}

int main () {
    freopen("COW.inp" , "r" , stdin) ;
    freopen("COW.out" , "w" , stdout) ;
    int t = fastRead() ;
    while (t--) enter () , process () ;
    return 0  ;
}
