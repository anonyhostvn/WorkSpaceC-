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

#define maxN 105

int n , k , a[maxN] , f[maxN] ;

int main () {
    //freopen("910A.inp" , "r" , stdin) ;
    cin >> n >> k ;
    forinc(i,1,n) {
        char c ; cin >> c ;
        a[i] = c - '0' ;
    }

    forinc(i,1,n) f[i]  = ooit ; f[1] = 0 ;

    forinc(i,1,n) if (f[i] < ooit) forinc(j,1,k) if (i + j <= n && a[i+j] == 1) minimize(f[i+j] , f[i] + 1) ;
    cout << (f[n] < ooit ? f[n] : -1) << endl ;
    return 0 ;
}
