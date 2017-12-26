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

const int base = 1000000007 ;

#define maxMN (1 << 24) + 5

int n , m , q ;
bool denie[maxMN] ;

void enter () {
    cin >> n >> m >> q ; m ++ ; n ++ ;
    forinc(i,1,q) {
        int x , y ; cin >> x >> y ;
        denie[x * m + y] = true ;
    }
}

int f[maxMN] ;

int on_bit(int x , int i) {
    return x | (1 << i) ;
}

int get_bit(int x , int i) {
    return (x >> i) & 1 ;
}

void process () {
    f[0] = 1 ;

    forinc(i,0,m * n -1) if (f[i]) {
        int x = i / m , y = i % m ;
        forinc(j,0,24) {
            if (on_bit(x,j) <= n && get_bit(x,j) == 0) {
                int nx = on_bit(x,j) ;
                if (!denie[nx*m+y]) f[nx * m + y] += f[i] ; f[nx * m + y] %= base ;
            }
            if (on_bit(y,j) <= m && get_bit(y,j) == 0) {
                int ny = on_bit(y,j) ;
                if (!denie[x*m+ny]) f[x * m + ny] += f[i] ; f[x * m + ny] %= base ;
            }
        }
    }

    cout << f[m * n - 1] << endl ;
}

int main () {
    freopen("SUBMASK.inp" , "r" , stdin) ;
    //freopen("SUBMASK.out" , "w" , stdout) ;

    enter () ;
    process ()  ;

    return 0 ;
}
