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

#define maxM 1000005
#define maxN 100005

int n , m , a , b ;
pii e[maxM] ;
vector<int> ke[maxN] ;

void enter () {
    n = fastRead()  ; m = fastRead() ;
    forinc(i,1,m) {
        int u = fastRead() , v= fastRead() ;
        e[i].fi = u ; e[i].se =v ;
        ke[u].push_back(i) ; ke[v].push_back(-i) ;
    }

    a = fastRead() ; b = fastRead() ;
}

int d[maxN] ;

void bfs(int start) {
    forinc(i,1,n) d[i] = -1 ;
    queue<int> q ; d[start] = 0 ; q.push(start) ;

    while (!q.empty()) {
        int u = q.front() ; q.pop() ;
        for (auto tmp : ke[u]) {
            int v = (tmp > 0) ? e[tmp].se : e[-tmp].fi ;
            if (d[v] == -1) d[v] = d[u] + 1 , q.push(v) ;
        }
    }
}

int da[maxN] , db[maxN] , min_path = 0 ;
bool in_min_path[maxN] ;

void prepare () {
    bfs(a) ; forinc(i,1,n) da[i] = d[i] ;
    bfs(b) ; forinc(i,1,n) db[i] = d[i] ;
    min_path = d[a] ;

    forinc(i,1,n) if (da[i] + db[i] == min_path) in_min_path[i] = true ;
}

int cnt_path[maxM] ;

void process () {
    prepare () ;

    forinc(i,1,n) if (in_min_path[i] && i != a && i != b) {
        if (cnt_path[da[i]] == 0) cnt_path[da[i]] = i ; else cnt_path[da[i]] = -1 ;
    }

    int ans = ooit ;
    forinc(i,1,n) if (cnt_path[i] > 0) minimize(ans,cnt_path[i]) ;
    cout << ((ans < ooit) ? ans : -1) << endl ;
}

int main () {
    freopen("GRAPHG.inp" , "r" , stdin) ;
    freopen("GRAPHG.out" , "w" , stdout) ;
    enter () ;
    process () ;
    return 0 ;
}
