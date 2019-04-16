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

int n , m ;
vector<pii> ke[10 * maxN] ;

void add(int u , int v , int c) { ke[u].push_back({v,c}) ; }

void enter () {
    cin >> n >> m ;
    forinc(i,1,m) {
        int u , v ; cin >> u >> v ;
        add(u,v,2) ; add(v,u,2) ;
    }
}

int node(int idx , int s) {return (idx) ? 5 * n + s : n + s ; }

void build_tree (int s , int l , int r) {
    if (l == r)  {
        add(node(0,s) , l , 0) ;
        add(l , node(1,s) , 0) ;
        return ;
    }

    add(node(0,s) , node(0,2*s) , 0) ; add(node(0,s) , node(0,2*s+1) , 0) ;
    add(node(1,2*s) , node(1,s) , 0) ; add(node(1,2*s+1) , node(1,s) , 0) ;

    int mid = (l+r) / 2 ;
    build_tree(2 * s , l , mid) ;
    build_tree(2 * s + 1 , mid + 1 , r) ;
}

void add_edge(int s , int l , int r , int u , int v , int vertex){
    if (r < u || v < l) return ;
    if (u <= l && r <= v) {
        add(vertex , node(0,s) , 1) ;
        add(node(1,s) , vertex , 1) ;
        return ;
    }

    int mid = (l+r) / 2 ;
    add_edge(2 * s , l , mid , u , v  , vertex) ;
    add_edge(2 * s + 1 , mid + 1 , r , u , v , vertex) ;
}

bool spoil[10 * maxN] ;
int d[10 * maxN] , virt[maxN] ;

void dkstra(int start) {
    forinc(i,1,10 * n) d[i] = ooit ; d[start] = 0 ;
    priority_queue<pii> q ; q.push({0,start}) ;

    while (!q.empty()) {
        int u = q.top().se ; q.pop() ;
        for (auto tmp : ke[u]) if (!spoil[tmp.fi] && d[tmp.fi] > d[u] + tmp.se) {
            d[tmp.fi] = d[u] + tmp.se ;
            q.push({-d[tmp.fi] , tmp.fi}) ;
        }
    }
}

void process () {
    build_tree(1,1,n) ;

    int snode = 9 * n + 1 , id = 0 ;
    int q = 0 ; cin >> q ;
    forinc(i,1,q) {
        int query = 0 ; cin >> query ;
        if (query == 1) {
            int u , v ; cin >> u >> v ;
            add_edge(1 , 1 , n , u , v , snode) ;
            virt[++id] = snode ++ ;
        } else if (query == 2) {
            int a ; cin >> a ;
            spoil[virt[a]] = true ;
        } else {
            int a , b ; cin >> a >> b ;
            dkstra(a) ;
            cout << ((d[b] < ooit) ? d[b] / 2 : -1) << endl ;
        }
    }
}

int main () {
    freopen("SUBGRAPHS.inp" , "r" , stdin) ;
    freopen("SUBGRAPHS.out" , "w" , stdout) ;
    enter () ;
    process() ;
    return 0 ;
}
