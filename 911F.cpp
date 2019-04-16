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
#define pli pair<long long , int>

template <class _T> bool maximize(_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize(_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

const int ooit = 2e9 ;
const long long ooll = 1e15 ;

using namespace std ;

#define maxN 200005

int n , deg[maxN] ;
vector<int> ke[maxN] ;

void enter () {
    cin >> n ;
    forinc(i,1,n-1) {
        int u , v ; cin >> u >> v;
        ke[u].push_back(v) ; ke[v].push_back(u) ;
        deg[u] ++ ; deg[v] ++ ;
    }
}

struct Algorithm_on_tree {
    int d[maxN] ;
    void bfs(int root) {
        queue<int> q ; forinc(i,1,n) d[i] = -1 ;
        d[root] = 0 ; q.push(root) ;

        while (!q.empty()) {
            int u  = q.front() ; q.pop() ;
            for (auto v : ke[u]) if (d[v] == -1) d[v] = d[u] + 1 , q.push(v) ;
        }
    }
} bfs[10] ;

void find_diametter (int &adj_1 , int &adj_2) {
    bfs[0].bfs(1) ; int max_len = 0 ;
    forinc(i,1,n) if (maximize(max_len , bfs[0].d[i])) adj_1 = i ;

    bfs[0].bfs(adj_1) ; max_len = 0 ;
    forinc(i,1,n) if (maximize(max_len , bfs[0].d[i])) adj_2 = i ;

    //cout << adj_1 << " " << adj_2 << endl ;
}

struct node {
    int x , y , v ;
} ;

vector<node> ans ;
bool _remove[maxN] ;
long long res = 0 ;

void Remove_Leaf (int adj_1 , int adj_2) {
    queue<int> q ; forinc(i,1,n) if (deg[i] == 1 && i != adj_1 && i != adj_2) q.push(i) ;
    while (!q.empty()) {
        int u = q.front() ; q.pop() ; _remove[u] = true ;
        if (bfs[0].d[u] > bfs[1].d[u]) ans.push_back({u , adj_1 , u}) ; else ans.push_back({u,adj_2,u}) ;
        res += max(bfs[0].d[u] , bfs[1].d[u]) ;
        for (auto v : ke[u]) {
            deg[v] -- ; deg[u] -- ;
            if (deg[v] == 1 && !_remove[v]) q.push(v) ;
        }
    }
}

void Remove_diametter (int adj_1 , int adj_2) {
    queue<int> q ; q.push(adj_1) ;
    while (!q.empty()) {
        int u = q.front() ; q.pop() ; _remove[u] = true ;
        if (u == adj_2) return ;
        ans.push_back({u , adj_2 , u}) ; res += bfs[1].d[u] ;
        for (auto v : ke[u]) if (!_remove[v]) q.push(v) ;
    }
}

void process () {
    int adj_1 = 0 , adj_2 = 0 ;
    find_diametter(adj_1 , adj_2) ;

    bfs[0].bfs(adj_1) ; bfs[1].bfs(adj_2) ;

    Remove_Leaf(adj_1 , adj_2) ;
    Remove_diametter(adj_1 , adj_2) ;

    cout << res << endl ;
    for (auto tmp : ans) cout << tmp.x << " " << tmp.y << " " << tmp.v << endl ;
}

int main () {
    //freopen("911F.inp" , "r" , stdin) ;
    enter () ;
    process () ;
    return 0 ;
}
