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

template <class _T> bool maximize(_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize(_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

const int ooit = 2e9 ;
const long long ooll = 1e15 ;

using namespace std ;

#define maxM 3005

int n , m , a[maxM] ;
string st ;

void enter () {
    cin >> n ;
    cin >> st ;
    m = st.length() ;
    forinc(i,1,m) a[i] = (int) st[i-1] - (int) 'a' ;
}

#define maxN 3005

int f[maxN] , ans[maxN] ;

void process () {
    forinc(len,1,m) {
        f[0] = 0 ;
        for (int i = 1 ; i + len <= m ; i ++ ) {
            f[i] = f[i-1] + (a[i] != a[i+len]) ;
            if (i >= len) maximize(ans[f[i] - f[i-len]] , len) ;
        }
    }

    forinc(i,1,m) maximize(ans[i] , ans[i-1]) ;
    forinc(i,1,n) {
        int k ; cin >> k ; cout << ans[k] << endl ;
    }
}

int main () {
    freopen("VIRUS.inp" , "r" , stdin) ;
    freopen("VIRUS.out" , "w" , stdout) ;
    enter () ;
    process () ;
    return 0 ;
}
