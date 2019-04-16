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

int n , a , b ;

void enter () {
    cin >> n >> a >> b ;
}

#define maxN 1005
#define maxA 10
#define maxB 10
int f[maxA][maxB][maxN] ;

void process () {
    forinc(i,0,4) forinc(j,0,2) forinc(k,0,n) f[i][j][k] = ooit ;
    f[0][0][0] = 0 ;

    forinc(sa,0,4) forinc(sb,0,2) forinc(len,0,n) if (f[sa][sb][len] < ooit) {
        if (sa < 4) { if (len < a) minimize(f[sa+1][sb][n-a] , f[sa][sb][len] + 1) ; else minimize(f[sa+1][sb][len-a] , f[sa][sb][len]) ; }
        if (sb < 2) { if (len < b) minimize(f[sa][sb+1][n-b] , f[sa][sb][len] + 1) ; else minimize(f[sa][sb+1][len-b] , f[sa][sb][len]) ; }
    }

    int res = ooit  ;
    forinc(i,0,n) minimize(res , f[4][2][i]) ;
    cout << res << endl ;
}


int main () {
    //freopen("910B.inp" , "r" , stdin) ;
    enter () ;
    process () ;
    return 0 ;
}
