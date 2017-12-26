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
#define ooll (long long) 1e15
#define ooit (int) 2e9
#define maxN 100005

using namespace std ;

struct node {
    int u , v , c ;
};

int n , m1 , m2 ;
vector<int> ke[maxN] ;
vector<node> edge ;

void enter() {
    cin >> n ;
    cin >> m1 ;
    forinc(i,1,m1) {
        int u , v ; cin >> u >> v ;
        ke[u].push_back(v) ;
    }
    cin >> m2 ;
    forinc(i,1,m2) {
        int u ,  v , c; cin >> u >> v >>  c ;
        edge.push_back({u,v,c}) ;
    }
}

int num[maxN] , low[maxN] , cnt = 0 , s_connect = 0 , lab[maxN] ;
stack<int> st ;

void dfs(int u) {
    st.push(u) ; num[u] = low[u] = ++cnt ;
    for (int v : ke[u])
        if (lab[v] == 0) {
            if (num[v]) low[u] = min(low[u],num[v]) ;
            else dfs(v) , low[u] = min(low[u],low[v]) ;
        }
    if (num[u] == low[u]) {
        s_connect ++ ;
        while (st.top() != u) lab[st.top()] = s_connect , st.pop() ;
        lab[st.top()] = s_connect ; st.pop() ;
    }
}

int deg_in[maxN],deg_out[maxN] , start = 0 , finish = 0 ;

void prepare() {
    forinc(i,1,n) if (num[i] == 0) dfs(i) ;
    forinc(u,1,n)
        for (int v : ke[u]) if (lab[u] != lab[v])
            deg_out[lab[u]] ++ , deg_in[lab[v]] ++ ;
}

vector<pii> nxt [maxN] ;

void add(int u , int v , int c) { nxt[u].push_back({v,c}) ; }

void Build_New_graph() {
    for (auto tmp : edge)  if (lab[tmp.u] != lab[tmp.v])
        add(lab[tmp.u] , lab[tmp.v] , tmp.c) ;
    forinc(i,1,s_connect) { if (deg_in[i] == 0) finish = i ; if (deg_out[i] == 0) start = i ; }
}

int d[maxN] ;

void dkstra() {
    priority_queue<pii> q ;
    forinc(i,1,n) d[i] = ooit ; d[start] = 0 ; q.push({0,start}) ;
    while (!q.empty()) {
        int u = q.top().se ; q.pop() ;
        for (auto x : nxt[u]) if (d[x.fi] > d[u] + x.se) {
            d[x.fi] = d[u] + x.se ;
            q.push({-d[x.fi],x.fi}) ;
        }
    }
}

void process()  {
    prepare() ;
    Build_New_graph() ;
    dkstra() ;
    if (d[finish] == ooit) cout << "NO" ; else cout << "YES" << endl << d[finish] << endl ;
}

int main () {
    freopen("EDGES.inp" , "r" , stdin) ;
    //freopen("EDGES.out" , "w" , stdout) ;
    enter() ;
    process() ;
    return 0 ;
}
