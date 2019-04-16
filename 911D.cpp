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

#define maxN 1505

int n , a[maxN] , m ;

void enter () {
    cin >> n ;
    forinc(i,1,n) cin >> a[i] ;
}

int inversion() {
    int res = 0 ;
    forinc(i,1,n) forinc(j,1,i-1) if (a[j]> a[i]) res ++ ;
    return res ;
}

void process () {
    int res = inversion () % 2 ;
    cin >> m ;
    forinc(i,1,m) {
        int x , y ; cin >> x >> y ;
        int Tswap = (y-x+1) / 2 ;
        if (Tswap % 2 != 0) res = 1 - res ;
        cout << (!res ? "even" : "odd") << endl ;
    }
}

int main () {
    //freopen("911D.inp" , "r" , stdin) ;
    enter () ;
    process () ;
    return 0 ;
}
