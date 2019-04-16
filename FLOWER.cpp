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
const long long ooll = 1e17 ;

using namespace std ;

typedef long long TCoord ;

int n ;

#define maxN 205

 struct node {
     TCoord x , y ;
 } a[maxN] , b[maxN] ;

void enter () {
    cin >> n ;
    forinc(i,1,n) cin >> a[i].x >> a[i].y ;
}

int get_bit(int x , int i) {
    return (x >> i) & 1 ;
}

void sub1() {
    int k = (1 << n) -1 ;
    TCoord res = ooit ;

    forinc(stt,0,k) {
        TCoord maxX = -ooit , maxY = -ooit , minX = ooit , minY = ooit ;
        forinc(i,1,n)
            if (get_bit(stt,i-1) == 1) maximize(maxX , a[i].x) , minimize(minX,a[i].x) ;
            else maximize(maxY,a[i].y) , minimize(minY,a[i].y);
        TCoord maxLeng = -ooll ;
        if (maxX > -ooit) maximize(maxLeng,(maxX-minX) * (maxX - minX)) ;
        if (maxY > -ooit) maximize(maxLeng,(maxY-minY) * (maxY - minY)) ;
        if (maxX > -ooit && maxY > -ooit) {
            maximize(maxLeng,maxX * maxX + maxY * maxY) ;
            maximize(maxLeng,maxX * maxX + minY * minY) ;
            maximize(maxLeng,minX * minX + maxY * maxY) ;
            maximize(maxLeng,minX * minX + minY * minY) ;
        }

        minimize(res , maxLeng) ;
    }

    cout << res << endl ;
}

long long f[2][maxN], g[2][maxN] ;

void prepare() {
    f[0][0] = ooit ; f[1][0] = -ooit ; g[0][n+1] = ooit ; g[1][n+1] = -ooit ;
    f[0][1] = a[1].y ; f[1][1] = a[1].y ; g[0][n] = a[n].y ; g[1][n] = a[n].y ;
    forinc(i,2,n) f[0][i] = min(f[0][i-1] , a[i].y) , f[1][i] = max(f[1][i-1] , a[i].y) ;
    fordec(i,n-1,1) g[0][i] = min(g[0][i+1] , a[i].y) , g[1][i] = max(g[1][i+1] , a[i].y) ;
}

bool check(long long mid) {
    TCoord maxY = f[1][n] , minY = f[0][n] ;
    if ((maxY - minY) * (maxY - minY) <= mid) return true ;

    int j = 1 ;
    forinc(i,1,n) {
        while (j <= i && (a[i].x - a[j].x) * (a[i].x - a[j].x) > mid) j ++ ;
        TCoord maxX = a[i].x , minX = a[j].x , maxY = max(f[1][j-1] , g[1][i+1]) , minY = min(f[0][j-1] , g[0][i+1]) ;
        long long maxLeng = -ooll ;
        maximize(maxLeng , (maxX - minX) * (maxX - minX)) ;
        if (maxY > -ooit) {
            maximize(maxLeng , (maxY - minY) * (maxY - minY)) ;
            maximize(maxLeng , maxX * maxX + maxY * maxY) ;
            maximize(maxLeng , maxX * maxX + minY * minY) ;
            maximize(maxLeng , minX * minX + maxY * maxY) ;
            maximize(maxLeng , minX * minX + minY * minY) ;
        }
        if (maxLeng <= mid) return true ;
    }
    return false ;
}

void sub2() {
    sort(a + 1 , a + 1 + n , [] (node a , node b) {
         return a.x < b.x ;
         }) ;
    prepare () ;

    long long res = -1 , l = 0 , r = ooll ;
    while (l <= r) {
        long long mid = (l+r) / 2 ;
        if (check(mid)) r = mid - 1, res = mid ; else l = mid + 1 ;
    }

    cout << res << endl ;
}

void process () {
    if (n <= 20) sub1() ; else sub2() ;
}

int main () {
    //freopen("FLOWER.inp" , "r" , stdin) ;
    freopen("FLOWER.out" , "w" , stdout) ;
    enter () ;
    process () ;
    return 0 ;
}
