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
    char c ; int res = 0 ;
    for (c = getchar() ; c < '0' || c > '9' ; c = getchar()) ;
    for ( ; c >= '0' && c <= '9' ; c = getchar()) res*= 10 , res += c - '0' ;
    return res ;
}

int R , C , XTop , XBot , YLeft , YRight , n ;

void enter () {
    XTop = ooit ; XBot = -ooit ; YLeft = ooit ; YRight = -ooit ;
    R = fastRead() ; C = fastRead() ; n = fastRead() ;
    forinc(i,1,n) {
        int u = fastRead() , v = fastRead() ;
        minimize(XTop,u) ; maximize(XBot,u) ;
        minimize(YLeft,v) ; maximize(YRight,v) ;
    }
}

#define maxN 3005
#define base 1000000007

long long gt[maxN] ;

void prepare () {
    gt[0] = 1 ;
    forinc(i,1,3000) gt[i] = gt[i-1] * i , gt[i] %= base ;

    //forinc(i,1,10) cout << gt[i] << endl ;
}

long long g[maxN][maxN] ;

void combinatories () {
    g[0][0] = 1 ;
    g[1][0] = 1 ; g[1][1] = 1 ;
    forinc(i,2,3000) {
        g[i][0] = 1 ; g[i][i] = 1 ;
        forinc(j,1,i-1) g[i][j] = g[i-1][j-1] + g[i-1][j] , g[i][j] %= base ;
    }

    //forinc(i,1,10) {
    //    forinc(j,0,i) cout << g[i][j] << " " ; cout << endl ;
    //}
}

long long f[maxN][maxN] ;

void process () {
    prepare () ; combinatories() ;
    int h = XBot - XTop + 1 , l = YRight - YLeft + 1 , S = h * l ;
    f[h][l] = gt[S - n] ;

    forinc(i,h,R) forinc(j,l,C) if (f[i][j] > 0) {
        if (i + 1 <= R) f[i+1][j] = (f[i][j] * gt[j]) , f[i+1][j] %= base ;
        if (j + 1 <= C) f[i][j+1] = (f[i][j] * gt[i]) , f[i][j+1] %= base ;
    }

    long long res = f[R][C] ; res *= g[R-h][XTop-1] ; res %= base ; res *= g[C-l][YLeft-1] ;
    cout << res << endl ;
}

int main () {
    freopen("LANDS.inp" , "r" , stdin) ;
    freopen("LANDS.out" , "w" , stdout) ;
    enter () ;
    process() ;
    return 0 ;
}
