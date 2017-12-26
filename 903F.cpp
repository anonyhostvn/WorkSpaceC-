#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; ++i )
#define fordec(i,a,b) for (int i = a ; i >= b ; --i )
#define forv(j,u) for (int j = 0 ; j < u.size() ; ++j)
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define mk make_pair
#define pii pair<int,int>
#define ooit (int) 1e9

template <class _T> bool maximize(_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize(_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

using namespace std ;

#define maxN 1010
#define maxR 5

int n , a[maxR] ;
char c[maxR][maxN] ;

void enter () {
    cin >> n ;
    forinc(i,1,4) cin >> a[i] ;
    forinc(i,1,4) forinc(j,1,n) cin >> c[i][j] ;
}

int on_bit(int x , int i) {return (1 << i) | x ; }
int get_bit(int x , int i) {return (x >> i) & 1 ;}

int cbit[maxR][maxR] , b[maxN] , status ;

void prepare () {
    status = (1 << 12) - 1 ;

    int cnt = 0 ;
    forinc(i,1,3) forinc(j,1,4) cbit[j][i] = cnt ++ ;

    forinc(j , 1 , n) {
        int stt = 0 ;
        forinc(i,1,4) stt = (c[i][j] == '.') ? on_bit(stt , i-1) : stt ;
        b[j] = stt ;
    }
}

#define maxS 4100

int f[maxN][maxS] ;

void init() {
    forinc(i,1,n) forinc(j,0,status) f[i][j] = ooit ;

    int stt = b[1] | (b[2] << 4) | (b[3] << 8) ;

    f[3][stt] = 0 ;
}

bool c1_check(int stt) {
    return get_bit(stt,0) && get_bit(stt,1) && get_bit(stt,2) && get_bit(stt,3) ;
}

int _include (int stt , int substt) {
    int res = (stt >> 4) | (substt << 8) ;
    return res ;
}

int change_sta(int st , int row , int col , int change) {
    forinc(u , row , row + change - 1)
        forinc(v , col , col + change - 1) st = on_bit(st , cbit[u][v]) ;
    return st ;
}

void process () {
    prepare () ;

    init() ;

    forinc(i,3,n) forinc(s , 0 , status) if (f[i][s] < ooit) {
        if (c1_check(s))
            minimize(f[i+1][_include(s,b[i+1])] , f[i][s]) ; /// khong ap dung phep bien doi nao ca

        minimize(f[i+1][status] , f[i][s] + a[4]) ; /// ap dung phep bien doi 4

        forinc(row,1,4) forinc(t , 1 , 3) if (row + t - 1 <= 4)
            minimize(f[i][change_sta(s , row , 1 , t) ] , f[i][s] + a[t]) ;
    }

    forinc(s , 0 , status) if (f[n][s] < ooit) {
        forinc(row , 1 , 4) forinc(col , 1 , 3) forinc(change , 1 , 3) if (row + change - 1 <= 4 && col + change - 1 <= 3)
            minimize(f[n][change_sta(s,row,col,change)] , f[n][s] + a[change]) ;
    }

    cout << f[n][status] << endl ;
}

int main () {
    //freopen("903F.inp" , "r" , stdin) ;
    enter () ;
    process () ;
    return 0 ;
}
