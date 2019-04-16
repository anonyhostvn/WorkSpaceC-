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

int fastRead() {
    int res = 0 ; char c ;
    for (c = getchar () ; c < '0' || c > '9' ; c = getchar()) ;
    for ( ; c >= '0' && c <= '9' ; c = getchar()) res *= 10 , res += c - '0' ;
    return res ;
}

#define maxN 3005
#define base 1000000007

int r , c , n , a[maxN][maxN] ;
long long gt[maxN * maxN] ;

void pre_build() {
    gt[0] = 1 ;
    forinc(i,1,3000 * 3000) gt[i] = gt[i-1] * i , gt[i] %= base ;
}

void enter () {
    r = fastRead() ; c = fastRead() ; n = fastRead() ;

    forinc(i,1,n) {
        int x = fastRead() , y = fastRead()  ;
        a[x][y] = 1 ;
    }
}

void sub1() {
    cout << gt[r * c - 2] << endl ;
}

void find_two_pos(int &xTOP , int &xBOT , int &yLEFT , int &yRIGHT) {
    xTOP = ooit ; xBOT = 0 ; yLEFT = ooit ; yRIGHT = 0 ;
    forinc(i,1,r) forinc(j,1,c) if (a[i][j] == 1) minimize(xTOP , i) , maximize(xBOT,i) , minimize(yLEFT,j) , maximize(yRIGHT,j) ;
}

long long f[55][55][55][55] ;

long long cal(int xTOP , int xBOT , int yLEFT , int yRIGHT) {
    if (f[xTOP][xBOT][yLEFT][yRIGHT] > -1) return f[xTOP][xBOT][yLEFT][yRIGHT] ;
    if (xTOP == 1 && xBOT == r && yLEFT == 1 && yRIGHT == c) return 1 ;
    long long res = 0 ;
    if (xTOP > 1) res += cal(xTOP-1 , xBOT , yLEFT , yRIGHT) * gt[yRIGHT-yLEFT+1] , res %= base ;
    if (xBOT < r) res += cal(xTOP , xBOT + 1 , yLEFT , yRIGHT) * gt[yRIGHT-yLEFT+1] , res %= base ;
    if (yLEFT > 1) res += cal(xTOP , xBOT , yLEFT-1 , yRIGHT) * gt[xBOT-xTOP+1] , res %= base ;
    if (yRIGHT < c) res += cal(xTOP , xBOT , yLEFT , yRIGHT + 1) * gt[xBOT-xTOP+1] , res %= base;

    f[xTOP][xBOT][yLEFT][yRIGHT] = res ;
    return res ;
}

void sub2() {
    int xTOP = 0 , xBOT = 0 , yLEFT = 0 , yRIGHT = 0 ;
    find_two_pos(xTOP , xBOT , yLEFT , yRIGHT) ;
    memset(f , -1 , sizeof(f)) ;

    int S = (xBOT-xTOP+1) * (yRIGHT-yLEFT+1) ;
    long long res = gt[S-n] ;
    res *= cal(xTOP,xBOT,yLEFT,yRIGHT) ; res %= base ;

    cout << res << endl ;
}

int g[maxN][maxN] ;

void sub3() {
    int xTOP = 0 , xBOT = 0 , yLEFT = 0 , yRIGHT = 0 ;
    find_two_pos(xTOP , xBOT , yLEFT , yRIGHT) ;
    int irow = xBOT - xTOP + 1 , icol = yRIGHT - yLEFT +1 , S = irow * icol ;
    g[irow][icol] = 1 ;

    forinc(i,irow,r) forinc(j,icol,c) if (g[i][j] > 0) {
        if (i < r) g[i+1][j] += g[i][j] * gt[j] , g[i+1][j] %= base ;
        if (j < c) g[i][j+1] += g[i][j] * gt[i] , g[i][j+1] %= base ;
    }

    long long res = g[r][c] ; res *= gt[r-irow] ; res %= base ; res *= gt[c-icol] ; res %= base ;
    res *= gt[S-n] ; res %= base ;

    cout << res << endl ;
}

void process () {
    pre_build() ;
    if (n == 2 && a[1][1] == 1 && a[r][c] == 1) sub1() ; else if (r <= 50 && c <= 50) sub2() ; else sub3() ;
}

int main () {
    freopen("LANDS.inp" , "r" , stdin) ;
    freopen("LANDS.out" , "w" , stdout) ;
    enter () ;
    process () ;
    return 0 ;
}
