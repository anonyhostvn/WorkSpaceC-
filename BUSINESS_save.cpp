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

#define maxN 300005

int n , k , deg[maxN] ;
bool import[maxN] ;
vector<int> ke[maxN] ;

void enter () {
    n = fastRead() ; k = fastRead() ;
    forinc(i,1,k) {
        int x = fastRead() ; import[x] = true ;
    }

    forinc(i,1,n-1) {
        int u = fastRead() , v = fastRead() ;
        ke[u].push_back(v) ; ke[v].push_back(u) ;
        deg[u] ++ ; deg[v] ++ ;
    }
}

int solve() {
    int d[maxN] ; queue<int> q ;
    forinc(i,1,n) {
        d[i] = (import[i]) ? 0 : -1 ;
        if (import[i]) q.push(i) ;
    }

    while (!q.empty()) {
        int u = q.front() ; q.pop() ;
        for (auto v : ke[u]) if (d[v] == -1) d[v] = d[u] + 1 , q.push(v) ;
    }

    int res = 0 ;
    forinc(i,1,n) maximize(res , d[i]) ;
    return res ;
}

void sub1 () {
    int res = ooit ;
    forinc(i,1,n) if (!import[i]) {
        import[i] = true ; minimize(res , solve()) ; import[i] = false ;
    }

    cout << res << endl ;
}

bool is_remove[maxN];

void sub2 () {
    queue<int> q ; int La = -1 ;
    forinc(i,1,n) if (deg[i] == 1) q.push(i) , is_remove[i] = true ;

    while (!q.empty()) {
        int u = q.front() ; q.pop() ; La = u ;
        for (auto v : ke[u]) {
            deg[v] -- ;
            if (deg[v] == 1 && !is_remove[v]) q.push(v), is_remove[v] = true ;
        }
    }

    int d[maxN] ; forinc(i,1,n) d[i] = -1 ; d[La] = 0 ;
    q.push(La) ;

    while (!q.empty()) {
        int u = q.front() ; q.pop() ;
        for (auto v : ke[u]) if (d[v] == -1) d[v] = d[u] + 1 , q.push(v) ;
    }

    int res = 0 ; forinc(i,1,n) maximize(res , d[i]) ;
    cout << res << endl ;
}

void process () {
    if (n <= 3000) sub1 () ; else if (k == 0) sub2 () ;
}

int main () {
    freopen("BUSINESS.inp" , "r" , stdin) ;
    freopen("BUSINESS.out" , "w" , stdout) ;
    enter () ;
    process () ;
    return 0 ;
}
