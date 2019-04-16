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

#define maxN 25
#define maxS (long long) 1e12

string st ;
long long val[maxN][maxN] , n = 0 ;

void prepare () {
    forinc(i,1,n) forinc(j,1,n) val[i][j] = -1 ;

    forinc(i,1,n) if (st[i-1] != '0') {
        long long num = 0 ;
        forinc(j,i,n) {
            num *= 10 ; num += st[j-1] - '0' ;
            if (num <= maxS) val[i][j] = num ; else break ;
        }
    } else val[i][i] = 0 ;
}

long long f[maxN][5] ;

void reset() {
    forinc(i,0,n) forinc(j,0,4) f[i][j] = -1 ;
}

void process () {
    cin >> st ; n = st.length() ;
    prepare () ; reset() ;

    f[0][0] = 0 ;
    forinc(i,0,n) forinc(j,0,3) if (f[i][j] > -1)
        forinc(k,i+1,n) if (val[i+1][k] > -1)
            maximize(f[k][j+1] , f[i][j] + val[i+1][k]) ; else break ;

    if (f[n][4] > -1) cout << f[n][4] ; else cout << "unlucky" ; cout << endl ;
}

int main () {
    freopen("HOMEWORK.inp" , "r" , stdin) ;
    freopen("HOMEWORK.out" , "w" , stdout) ;
    int t ; cin >> t ;
    while (t--) process () ;
    return 0 ;
}
