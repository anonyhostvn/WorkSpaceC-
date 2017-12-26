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

#define maxN 2005

int n , c[maxN] ;
long long sum[maxN] ;

void enter () {
    cin >> n ;
    forinc(i,1,n) cin >> c[i] ;
    forinc(i,1,n) sum[i] = sum[i-1] + c[i] ;
}

long long f[maxN][maxN] , pos[maxN][maxN] ;

void process () {
    forinc(i,1,n) forinc(j,1,n) f[i][j] = ooll ;
    forinc(i,1,n) f[i][i] = c[i] , pos[i][i] = i , pos[i+1][i] = i , f[i+1][i] = 0 ;
    forinc(leng , 2 , n) forinc(i,1,n-leng+1) {
        int l = i , r = i + leng - 1 ;
        forinc(j,pos[l][r-1],pos[l+1][r])
            if (minimize(f[l][r],f[l][j-1] + f[j+1][r] + sum[r] - sum[l-1])) pos[l][r] = j ;
    }
    cout << f[1][n] << endl ;
}

int main () {
    freopen("OPTBST.inp" , "r" , stdin) ;
    freopen("OPTBST.out" , "w" , stdout) ;
    enter () ;
    process () ;
    return 0 ;
}

