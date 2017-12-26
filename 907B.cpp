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

#define maxN 20

int x , y ;
char a[maxN][maxN] ;

char read() {
    char c ;
    for (c = getchar() ; c != '.' && c != 'o' && c != 'x' ; c = getchar()) ;
    return c ;
}

void enter () {
    forinc(i,1,9) forinc(j,1,9) cin >> a[i][j] ;
    cin >> x >> y ;
}

int b[maxN][maxN] , c[maxN][maxN] ;

void prepare () {
    forinc(i,1,3) {
        forinc(j,1,3) b[i][j] = 1 ;
        forinc(j,4,6) b[i][j] = 2 ;
        forinc(j,7,9) b[i][j] = 3 ;
        int p = 0 ;
        if (i == 1) p = 1 ; else if (i == 2) p = 4 ; else p = 7 ;
        forinc(j,0,8) c[i][j+1] = (j % 3) + p ;
    }

    forinc(i,4,6) {
        forinc(j,1,3) b[i][j] = 4 , c[i][j] = j ;
        forinc(j,4,6) b[i][j] = 5 , c[i][j] = j;
        forinc(j,7,9) b[i][j] = 6 , c[i][j] = j;
        forinc(j,1,9) c[i][j] = (j % 3) + i ;
        int p = 0 ;
        if (i == 4) p = 1 ; else if (i == 5) p = 4 ; else p = 7 ;
        forinc(j,0,8) c[i][j+1] = (j % 3) + p ;
    }

    forinc(i,7,9) {
        forinc(j,1,3) b[i][j] = 7 , c[i][j] = j;
        forinc(j,4,6) b[i][j] = 8 , c[i][j] = j;
        forinc(j,7,9) b[i][j] = 9 , c[i][j] = j;
        int p = 0 ;
        if (i == 7) p = 1 ; else if (i == 8) p = 4 ; else p = 7 ;
        forinc(j,0,8) c[i][j+1] = (j % 3) + p ;
    }


}

void process () {
    prepare() ;
    int id = c[x][y] , cnt = 0 ;
    forinc(i,1,9) forinc(j,1,9) if (b[i][j] == id && a[i][j] == '.') cnt ++ , a[i][j] = '!' ;
    if (cnt == 0) forinc(i,1,9) forinc(j,1,9) if (a[i][j] == '.') a[i][j] = '!' ;
    forinc(i,1,9) {
        forinc(j,1,9) {
            cout << a[i][j] ;
            if (j % 3 == 0) cout << " " ;
        }cout << endl ;
        if (i % 3 == 0) cout << endl ;
    }
}

int main () {
    //freopen("907.inp" , "r" , stdin) ;
    enter () ;
    process () ;
    return 0;
}
