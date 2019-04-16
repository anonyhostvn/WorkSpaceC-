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
    for ( ; c >= '0' && c <= '9' ; c = getchar()) res*= 10 , res += c - '0' ;
    return res ;
}

#define maxM 10005
#define maxN 1005

struct edge {
    int u , v ,c  ;
} e[maxM] ;

int n , m ;

void enter () {
    n = fastRead() ; m = fastRead() ;
    forinc(i,1,m) e[i] = {fastRead() , fastRead() , fastRead()} ;
}

int lab[maxN] , tlab[maxN] ;

int get_root(int u) {
    if (u == lab[u]) return lab[u] ;
    lab[u] = get_root(lab[u]) ;
    return lab[u] ;
}

void uni(int u , int v) {
    lab[get_root(u)] = get_root(v) ;
    get_root(u) ;
}

bool select[maxM] ;

void prepare () {
    forinc(i,1,n) lab[i] = i ;
    forinc(i,1,m) if (e[i].c == 3 && get_root(e[i].u) != get_root(e[i].v)) uni(e[i].u , e[i].v) , select[i] = true ;
    forinc(i,1,n) tlab[i] = get_root(i) ;
}

int solve (int idx) {
    forinc(i,1,m) if (e[i].c == idx && get_root(e[i].u) != get_root(e[i].v)) uni(e[i].u , e[i].v) , select[i] = true ;
    forinc(i,1,n)
        if (get_root(i) != get_root(1))
            return -1 ;
    return 0 ;
}

void process () {
    prepare () ;

    if (solve(1) == -1) {
        cout << -1 << endl ;
        return ;
    }

    forinc(i,1,n) lab[i] = tlab[i] ;
    if (solve(2) == -1) {
        cout << -1 << endl ;
        return ;
    }

    int ans = 0 ;
    forinc(i,1,m) ans += (int) (!select[i]) ;
    cout << ans << endl ;
}

int main () {
    freopen("GRAPHTYPE.inp" , "r" , stdin) ;
    freopen("GRAPHTYPE.out" , "w" , stdout) ;
    enter () ;
    process () ;
    return 0 ;
}
