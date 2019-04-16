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
    for ( ; c >= '0' && c <= '9' ; c = getchar()) res *= 10 , res += c - '0' ;
    return res ;
}

void WriteInt(int x)
{
    if (x > 9) WriteInt(x / 10);
    putchar(x % 10 + '0');
}

void fastWrite(int x) {
    if (x < 0) putchar('-') ;
    WriteInt(abs(x)) ;
}

#define maxN 100005

int n , a[maxN] ;

void enter () {
    n = fastRead() ;
    forinc(i,1,n) a[i] = fastRead() ;
}

int cnt_a[maxN] , b[maxN] , cleft[maxN] ;

void prepare () {
    forinc(i,1,n) cnt_a[a[i]] = 0 ;
    forinc(i,1,n) cnt_a[a[i]] ++ ;
    forinc(i,1,n) b[i] = cnt_a[a[i]] ;
}

void process () {
    prepare () ;
    forinc(i,1,n) {
        bool ok = false ;
        forinc(j,i+1,n) if (b[j] > b[i]) {
            cout << a[j] << " " ; ok = true ;
            break ;
        }
        if (!ok) cout << -1 << " " ;
    }
    cout << endl ;
}

int main () {
    freopen("FREQUENCY.inp" , "r" , stdin) ;
    freopen("FREQUENCY_trau.out" , "w" , stdout) ;
    int t = fastRead() ;
    while (t--) enter () , process () ;
    return 0 ;
}
