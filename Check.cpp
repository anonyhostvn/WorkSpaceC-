#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)
#define forv(j,u) for (int j = 0 ; j < u.size() ; j++)
#define fi first
#define se second
#define pii pair<int,int>

template <class _T> bool maximize(_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize(_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

const int ooit = 2e9 ;
const long long ooll = 1e15 ;
const int base = 1000000007 ;

using namespace std ;

#define maxN 100005

int n , a[maxN] , b[maxN] ;

int main () {
    freopen("PRESENT.inp" , "r" , stdin) ;
    cin >> n ;
    forinc(i,1,n) cin >> a[i] ;
    forinc(i,1,n) cin >> b[i] ;

    freopen("PRESENT.out" , "r" , stdin) ;

    string st ; cin >> st ;
    if (st == "NO") return 0 ;
    vector<int> X , Y ;

    return 0 ;
}
