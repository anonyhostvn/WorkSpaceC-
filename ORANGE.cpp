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

int n , a[maxN] , k ;

void enter() {
    //cin >> n ;
    scanf("%d" , &n) ;
    forinc(i,1,n) scanf("%d" , &a[i]) ;
    scanf("%d" , &k) ;
    sort(a+1 , a+1+n) ;
}

void process () {
    int j = 1 , res = 0 ;
    forinc(i,1,n) {
        while (j <= n && a[j] - a[i] <= k) j ++ ;
        maximize(res,j-i) ;
    }
    cout << res << endl ;
}

int main () {
    freopen("ORANGE.inp" , "r",  stdin) ;
    freopen("ORANGE.out" , "w" , stdout) ;
    enter () ;
    process () ;
    return 0 ;
}
