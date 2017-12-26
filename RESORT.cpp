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
#define maxN 2005

using namespace std ;

int n , m , p , q , b , a[maxN][maxN] ;

int fastRead() {
    int res = 0 ; char c ;
    for (c = getchar() ; c < '0' || c > '9' ; c = getchar()) ;
    for ( ; c >= '0' && c <= '9' ; c = getchar()) res *= 10 , res += (int) c - (int) '0' ;
    return res ;
}

void enter() {
    //scanf("%d%d%d%d%d" , &m , &n , &p , &q , &b) ;
    //forinc(i,1,m) forinc(j,1,n) scanf("%d" , &a[i][j]) ;
    m = fastRead() ; n = fastRead() ; p = fastRead() ; q = fastRead() ; b = fastRead() ;
    forinc(i,1,m) forinc(j,1,n) a[i][j] = fastRead() ;
}

int f[maxN][maxN] , g[maxN][maxN] , pt[maxN][maxN] ;

void prepare() {
    forinc(i,1,m) forinc(j,1,n) f[i][j] = f[i-1][j] + f[i][j-1] - f[i-1][j-1] + (int) (a[i][j] < b) ,
                                g[i][j] = g[i-1][j] + g[i][j-1] - g[i-1][j-1] + (int) (a[i][j] > b) ,
                                pt[i][j] = pt[i-1][j] + pt[i][j-1] - pt[i-1][j-1] + (int) (a[i][j] == b) ;
}

inline int get_f(int x , int y , int u , int v) {return f[u][v] - f[u][y-1] - f[x-1][v] + f[x-1][y-1] ; }

inline int get_g(int x , int y , int u , int v) {return g[u][v] - g[u][y-1] - g[x-1][v] + g[x-1][y-1] ; }

inline int get_p(int x , int y , int u , int v) {return pt[u][v] - pt[u][y-1] - pt[x-1][v] + pt[x-1][y-1];}

inline bool check(int t1 , int t2) { return (t1 <= (p * q -1) / 2) && (t2 <= p * q / 2) ;}

void sub() {
    prepare() ;
    int res = 0 ;
    forinc(i,1,m-p+1) forinc(j,1,n-q+1) if (get_p(i,j,i+p-1,j+q-1) > 0) {
        int t1 = get_f(i,j,i+p-1,j+q-1) , t2 = get_g(i,j,i+p-1,j+q-1) ;
        if (check(t1,t2)) res ++ ;
    }
    printf("%d" , res) ;
}

int main() {
    freopen("RESORT.inp" , "r" , stdin) ;
    freopen("RESORT.out" , "w" , stdout) ;
    enter() ;
    sub() ;
    return 0 ;
}
