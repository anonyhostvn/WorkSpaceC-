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

void enter () {
    int m = fastRead() ;
    forinc(query,1,m) {
        int n  , sum = 0 , res = 0 ; n = fastRead() ;
        if (n == 1) {cout << 1 << endl ; continue ; }
        forinc(i,2,45) {
            sum += i ;
            if (sum > n) {sum -= i ; res = i - 1 ; break ; }
        }
        cout << res - 1 << endl ;
    }
}

int main () {
    freopen("parliament.inp" , "r" , stdin) ;
    freopen("parliament.out" , "w" , stdout) ;
    enter () ;
    return 0  ;
}
