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

#define maxN 100005

int n , k ;
vector<pii> ke[maxN] ;
bool import[maxN] ;

void enter () {
    cin >> n >> k ;
    forinc(i,1,k) {
        int x ; cin >> x ;
        import[x] = true ;
    }
    forinc(i,1,n-1) {
        int u , v , c ; cin >> u >> v >> c ;
        ke[u].push_back({v,c}) ;
        ke[v].push_back({u,c}) ;
    }
}

int d[maxN] ;

void bfs (int start) {
    forinc(i,1,n) d[i] = -1 ;
    queue<int> q ; q.push(start) ; d[start] = 0 ;

    while (!q.empty()) {
        int u = q.front() ; q.pop() ;
        for (auto tmp : ke[u]) if (d[tmp.fi] == -1) d[tmp.fi] = d[u] + tmp.se , q.push(tmp.fi) ;
    }
}

int max_path(int &adj) {
    forinc(i,1,n) if (import[i]) {bfs(i) ; break ; }

    int res = 0 ;
    forinc(i,1,n) if (import[i] && maximize(res,d[i])) adj = i ;

    bfs(adj) ; res = 0 ;
    forinc(i,1,n) if (import[i] && maximize(res,d[i])) adj = i ;
    return res ;

}

long long res = 0 ;
int cal(int u, int p) {
    int cre = import[u] ;
    for (auto v : ke[u]) if (v.fi != p) {
        int c = cal(v.fi,u) ;
        if (c > 0) res += v.se ;
        cre += c ;
    }
    return (cre > 0) ;
}

void process () {
    int u = 0 , sub = max_path(u) ;
    cal(u,-1) ;
    cout << res * 2 - sub << endl ;
}

int main () {
    freopen("TREE.inp" , "r" , stdin ) ;
    freopen("TREE.out" , "w" , stdout) ;
    enter () ;
    process () ;
    return 0 ;
}
