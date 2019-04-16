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

#define maxN 1005

int n , m , a[maxN][maxN] , tplusX = 0 ;

void enter () {
    cin >> m >> n ;
    forinc(i,1,m) forinc(j,1,n) {
        char c ; cin >> c ;
        a[i][j] = (c == '*') ? 1 : 0 ;
    }
    tplusX = abs(1-n) ;
}

int Ttype (int x , int y) {
    return (x % 2 == y % 2) ;
}

bool the_same(int x , int y , int u , int v) {
    return (Ttype(x,y) == Ttype(u,v)) ;
}

void swap_Coord(int x , int y , int &u , int &v) {
    u = x - y + tplusX ; v = x + y ;
}

int b[2][2 * maxN][2 * maxN] , f[2][2 * maxN][2 * maxN] ;

void Rotate () {
    forinc(i,1,m) forinc(j,1,n) b[Ttype(i,j)][i-j+tplusX][i+j] = a[i][j] ;
    forinc(t,0,1) forinc(i,0,m + n) forinc(j,0,m + n) f[t][i][j] = f[t][i-1][j] + f[t][i][j-1] - f[t][i-1][j-1] + b[t][i][j] ;
}

int min_to_edge(int x , int y){ return min(min(abs(x-1) , abs(y-1)) , min(abs(m-x) , abs(n-y))) ; }

int go_left(int x , int y) {return the_same(x,1,x,y) ? y - 1 : y - 2 ; }
int go_right(int x , int y) {return the_same(x,n,x,y) ? n - y : n-1-y ;}
int go_up(int x , int y) {return the_same(x,y,1,y) ? y - 1 : y - 2 ; }
int go_down(int x , int y) {return the_same(x,y,m,y) ? m - x : x-1-y ; }
int

int select(int i , int j) {
    if (min_to_edge(i,j) < 2) return a[i][j] ;
}

int not_select(int i , int j) {
}

void process () {
    Rotate() ;

    int res = 0 ;
    forinc(i,1,n) forinc(j,1,m) maximize(res , max(select(i,j) , not_select(i,j)) )  ;
    cout << res << endl ;
}

int main () {
    return 0 ;
}
