#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)
#define forv(j,u) for (int j = 0 ; j < u.size() ; j++)
#define fi first
#define se second
#define pii pair<int,int>

template <class _T> bool maximize(_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize(_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

const int ooit = 2e9 ;
const long long ooll = 1e15 ;
const int base = 1000000007 ;

using namespace std ;

int fastRead() {
    char c ; int res = 0 ;
    for (c = getchar() ; c < '0' || c > '9' ; c = getchar()) ;
    for ( ; c >= '0' && c <= '9' ; c = getchar()) res*= 10 , res += c - '0' ;
    return res ;
}

#define maxN 100005

int n , a[maxN] , q ;

void enter () {
    n = fastRead() ;
    forinc(i,1,n) a[i] = fastRead() ;
    q = fastRead() ;
}

int lab[maxN] ;

int get_root(int u ) {
    return (u == lab[u]) ? lab[u] : get_root(lab[u]) ;
}

void uni(int u , int v) { lab[get_root(u)] = get_root(v) ; }

///========================================================================================================================================================
///                                             SUB 1
///========================================================================================================================================================

void solve () {
    map<int,int> f ; f.clear() ;

    forinc(i,1,n) lab[i] = i ;
    forinc(i,1,n-1) forinc(j , i + 1 , n) if ((a[i] & a[j]) > 0) uni(i , j) ;

    forinc(i,1,n) f[get_root(i)] = 0 ;
    cout << f.size() << endl ;
}

void sub1 () {
    //q = fastRead() ;

    forinc(i,1,q) {
        char c = ' ' ;
        for ( ; c != '!' && c != '?' ; c = getchar()) ;
        if (c == '!') {
            int x = fastRead() , y = fastRead() ;
            a[x] = y ;
        } else solve() ;
    }
}

///========================================================================================================================================================
///                                                SUB 2
///========================================================================================================================================================

int num0 = 0 , dd[35] ;

int get_bit(int x , int i) { return (x >> i) & 1 ; }

int Fbit (int x) {
    if (x == 0) return -1 ;
    int res = -1 ;
    forinc(i,0,30) if (get_bit(x,i)) return i ;
}
///_______________________________________________________________________________________________________________________
multiset<int> nxt[35] ;

void build(int x) {
    int t = Fbit(x) ; if (t == -1) return ;
    forinc(i,0,30) if (get_bit(x,i)) dd[i] ++ ;
    forinc(i,t + 1 , 30) if (get_bit(x,i)) nxt[t].insert(i) , nxt[i].insert(t) ;
}

void _remove(int x) {
    int t = Fbit(x) ; if (t == -1) return ;
    forinc(i,0,30) if (get_bit(x,i)) dd[i] -- ;
    forinc(i , t + 1 , 30) if (get_bit(x,i)) nxt[t].erase(nxt[t].find(i)) , nxt[i].erase(nxt[i].find(t)) ;
}

void prepare () {
    forinc(i,1,n) if (a[i] == 0) num0 ++ ; else build(a[i]) ;
}
///_______________________________________________________________________________________________________________________

int vis[35] ;

void dfs(int u) {
    vis[u] = true ;
    for (auto v : nxt[u]) if (!vis[v]) dfs(v) ;
}

int optimize_solve() {
    forinc(i,0,30) vis[i] = false ;
    int cnt = 0 ;
    forinc(i,0,30) if (dd[i] && !vis[i]) dfs(i) , ++cnt ;
    return cnt + num0 ;
}

void fix_graph(int x , int y) {
    if (a[x] == 0 && y != 0) {num0 -- ; a[x] = y ; build(a[x]) ; return ; }
    if (a[x] != 0 && y == 0) {num0 ++ ; _remove(a[x]) ; return ; }
    if (a[x] == y) return ;

    _remove(a[x]) ; a[x] = y ; build(a[x]) ;
}

///_______________________________________________________________________________________________________________________

void sub2 () {
    prepare () ;
    //q = fastRead() ;
    forinc(i,1,q) {
        char c = ' ' ; for ( ; c != '!' && c != '?' ; c = getchar()) ;
        if (c == '?') printf("%d\n" , optimize_solve()) ; else {
            int x = fastRead() , y = fastRead() ;
            fix_graph(x , y) ;
        }
    }
}

///========================================================================================================================================================
///                                             PROCESS
///========================================================================================================================================================

void process () {
    if (n <= 300 && q <= 300) sub1 () ; else sub2 () ;
}

int main () {
    freopen("AND.inp" , "r" , stdin) ;
    freopen("AND.out" , "w" , stdout) ;
    enter () ;
    process () ;
    return 0 ;
 }
