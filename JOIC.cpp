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
#define maxN 100005

template <class _T> bool maximize(_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize(_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

using namespace std ;

int n  ,  a[2 * maxN]  ;
long long s[2 * maxN] ;

void enter() {
    scanf("%d" , &n);
    forinc(i,1,n) scanf("%d" , &a[i])  ;
    forinc(i,1,n) a[i+n] = a[i] ;
    forinc(i,1,2 * n) s[i] = s[i-1] + a[i] ;
}

bool check(long long x) {
    int j = 1 , k = 1 ;
    forinc(i,1,n) {
        j = max(j,i) ; while (j - i + 1 <= n && s[j] - s[i-1] < x) j ++ ; if (j - i + 1 >= n) continue ;
        k = max(k,j+1) ; while (k - i + 1 <= n && s[k] - s[j] < x) k ++ ; if (k - i + 1 >= n) continue ;
        if (s[i + n - 1] - s[k] < x) continue ; return true ;
    }
    return false ;
}

void process () {
    long long l = 0 , r = s[n] , res = 0 ;
    while (l <= r) {
        long long mid = (l+r)  / 2 ;
        if (check(mid)) l = mid + 1 , res = mid ; else r = mid - 1 ;
    }
    cout << res << endl ;
}

int main () {
    freopen("JOIC.inp" , "r" , stdin) ;
    freopen("JOIC.out" , "w" , stdout) ;
    enter() ;
    process() ;
    return 0 ;
}
