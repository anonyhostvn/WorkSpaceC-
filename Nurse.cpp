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
#define maxN 1005

template <class _T> bool maximize(_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize(_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

using namespace std ;

const int base = 1000000007 ;

int n , k1 , k2 ;
long long f[maxN][2] ;

void enter() {
    cin >> n >> k1 >> k2 ;
    f[1][0] = 1 ;
    forinc(i,k1,k2) f[i][1] = 1 ;

    forinc(i,1,n) forinc(j,0,1) if (f[i][j] > 0) {
        if (j == 0) {forinc(t,k1,k2) if (i + t <= n) f[i+t][1] += f[i][j] , f[i+t][1] %= base ; }
        else f[i+1][0] += f[i][j] , f[i+1][0] %= base ;
    }

    cout << (f[n][0] + f[n][1]) % base << endl ;
}

int main () {
    freopen("NURSE.inp" , "r" , stdin) ;
    freopen("NURSE.out" , "w" , stdout) ;
    enter () ;
    return 0 ;
}
