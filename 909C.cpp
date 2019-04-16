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

#define maxN 5005

int n ;
char c[maxN] ;
const int base = 1000000007 ;

void enter () {
    cin >> n ;
    forinc(i,1,n) cin >> c[i] ;
}

long long f[maxN][maxN] , g[maxN] ;

void process () {
    f[0][0] = 1 ; forinc(i,0,n) g[i] = 1 ;
    forinc(i,1,n) {

        forinc(j,0,i)
            if (c[i] == 'f') f[i][j]  += ((j == 0) ? 0 : f[i-1][j-1]) , f[i][j] %= base ;
            else {
                f[i][j] += f[i-1][j] ; f[i][j] %= base  ;
                if (j + 1 <= i - 1) f[i][j] += (g[i-1] - g[j] + base) % base  ,  f[i][j] %= base ;
            }

        forinc(j,0,n) g[j] = ( (j == 0) ? f[i][j] : g[j-1] + f[i][j] ) , g[j] %= base ;
    }

    cout << f[n][0] << endl ;
}

int main () {
    //freopen("909C.inp" , "r" , stdin) ;
    enter () ;
    process ()  ;
    return 0 ;
}
