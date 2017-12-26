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
#define maxN 100005

template <class _T> bool maximize(_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize(_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

using namespace std ;

struct Coord {
    int x , y , c ;
};

int n ;
Coord a[maxN] ;

void enter () {
    cin >> n ;
    forinc(i,1,n) cin >> a[i].x >> a[i].y >> a[i].c ;
}

int d[405][405] ;

void prepare () {
    forinc(i,1,n) d[a[i].x + 200][a[i].y + 200] = a[i].c ;
}

long long cnt[5][5] ;

void process () {
    prepare() ;
    long long res = 0 ;
    forinc(i,0,399) forinc(j,i+1,400) {
        memset(cnt , 0 , sizeof(cnt)) ;
        forinc(k,0,400) cnt[d[i][k]][d[j][k]] ++ , cnt[d[j][k]][d[i][k]] ++ ;
        res += cnt[1][2] * cnt[3][4]  + cnt[1][3] * cnt[2][4] + cnt[1][4] * cnt[2][3] ;
    }
    cout << res << endl ;
}

int main () {
    freopen("RECTANGLE.inp" , "r" , stdin) ;
    freopen("RECTANGLE.out" , "w" , stdout) ;
    enter() ;
    process () ;
    return 0 ;
}
