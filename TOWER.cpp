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
    int res = 0  ; char c ;
    for (c = getchar() ; c < '0' || c > '9' ; c = getchar() ) ;
    for ( ; c >= '0' && c <= '9' ; c = getchar()) res *= 10 , res += c - '0' ;
    return res ;
}

void WriteInt(int x)
{
    if (x > 9) WriteInt(x / 10);
    putchar(x % 10 + '0');
}

#define maxN 1000005

int n , a[maxN] ;

void enter () {
    n = fastRead() ;
    forinc(i,1,n) a[i] = fastRead() ;
}

int cleft[maxN] ;

void prepare () {
    a[0] = ooit ; stack<int> st ; st.push(0) ;
    forinc(i,1,n) {
        while (!st.empty() && a[i] >= a[st.top()]) st.pop() ;
        cleft[i] = st.top() ;
        st.push(i) ;
    }
}

void process () {
    prepare () ;
    forinc(i,1,n) WriteInt(i - cleft[i]) , putchar(' ') ; putchar('\n') ;
}

void trau () {
    forinc(i,1,n) {
        int cnt = 1 ;
        fordec(j,i-1,1) if (a[j] <= a[i]) ++cnt ; else break ;
        cout << cnt << " " ;
    }
    cout << endl ;
}

int main () {
    freopen("TOWER.inp" , "r" , stdin) ;
    freopen("TOWER.out" , "w" , stdout) ;
    int t = fastRead() ;
    while (t--) enter () , process () ;
    return 0 ;
}

