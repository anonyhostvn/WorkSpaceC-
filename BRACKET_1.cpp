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

#define maxN 1000005

int fastRead() {
    char c ; int res = 0 ;
    for (c = getchar() ; c < '0' || c > '9' ; c = getchar()) ;
    for ( ; c >= '0' && c <= '9' ; c = getchar()) res*= 10 , res += c - '0' ;
    return res ;
}

const int base = 1000000007 ;

int n , m ;
bool ok = true ;
int dd[maxN] ;

struct query {
    int x , y ;
} q[maxN] ;

void enter () {
    n = fastRead() ;  m = fastRead() ;
    forinc(i,1,m) {
        int x = fastRead() , y = fastRead() ;
        dd[x] = 1 ; dd[y] = 2 ; q[i].x = x ; q[i].y = y ;
    }
    //forinc(i,1,n) cout << dd[i] << " " ; cout << endl ;
}

///===========================================================================================================================================================

///===========================================================================================================================================================


int get_bit(int x , int i) { return (x >> i) & 1 ; }

bool check(int x) {
    forinc(i,1,n) {
        if (dd[i] == 1 && get_bit(x,i-1) == 1) return false ;
        if (dd[i] == 2 && get_bit(x,i-1) == 0) return false ;
    }

    int sum = 0 ;
    forinc(i,1,n) {
        sum += (get_bit(x,i-1) == 0) ? 1 : -1 ;
        if (sum < 0) return false ;
    }
    if (sum != 0) return false ;

    forinc(i,1,m) {
        int sum = 0 ;
        forinc(j,q[i].x,q[i].y) {
            sum += get_bit(x,j-1) == 0 ? 1 : -1;
            if (j < q[i].y && sum <= 0) return false ;
        }
        if (sum != 0) return false ;
    }

    //forinc(i,1,n) if (get_bit(x,i-1)) cout << ')' ; else cout << '(' ; cout << endl ;
    return true ;
}

void sub1 () {
    int k = (1 << n) - 1 , cnt = 0 ;

    forinc(s,0,k) if (check(s)) cnt ++ ;
    cnt %= base ;
    cout << cnt << endl ;
}

///===========================================================================================================================================================

///===========================================================================================================================================================


#define maxn 5005

long long f[maxn][maxn] ;

void dp() {
    f[0][0] = 1 ;
    forinc(i,0,n) forinc(j,0,i) if (f[i][j] > 0){
        f[i+1][j+1] += f[i][j] ; f[i+1][j+1] %= base ;
        if (j - 1 >= 0) f[i+1][j-1] += f[i][j] ; f[i+1][j-1] %= base ;
    }
}

void sub2() {
    dp () ;

    int len = n ; long long res = 1 ;

    forinc(i,1,m) if (q[i].x != q[i-1].x && q[i].y != q[i-1].y) {
        res *= f[q[i].y - q[i].x - 1][0] ; res %= base ;
        len -= q[i].y - q[i].x + 1 ;
    }

    res *= f[len][0] ; res %= base ;
    cout << res << endl ;
}

///===========================================================================================================================================================

///===========================================================================================================================================================


bool check_query () {
    sort(q + 1 , q + 1 + m , [] (query a , query b) {
         return (a.x < b.x) || (a.x == b.x && a.y < b.y) ;
         }) ;
    forinc(i,2,m)
        if (q[i].x == q[i].y) return false ;
        else if (q[i].x == q[i-1].x && q[i].y != q[i-1].y) return false ;
        else if (q[i].x <= q[i-1].y) return false ;

    return true ;
}

void process () {
    if (!check_query()) {cout << 0 << endl ; return ; }
    if (n <= 20) sub1 () ; else sub2 () ;
    //sub1 () ; sub2 () ;
}

int main () {
    freopen("BRACKET.inp" , "r" , stdin) ;
    freopen("BRACKET.out" , "w"  , stdout) ;
    enter () ;
    process () ;
    return 0 ;
}

