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
#define maxM 250005

using namespace std ;

int n , m ;
vector<pii> ke[maxN] ;
pii edge[maxM] ;

void enter() {
    scanf("%d%d" , &n , &m) ;
    forinc(i,1,m) {
        int u , v ; scanf("%d%d" , &u , &v) ;
        ke[u].push_back({v,i}) ; ke[v].push_back({u,i}) ;
        edge[i].fi = u ; edge[i].se = v ;
    }
}

int cnt = 0 , col[maxM];
bool vis[maxN] ;

void dfs(int u) {
    vis[u] = true ;
    forv(i,ke[u]) {
        int v = ke[u][i].fi , j = ke[u][i].se ;
        if (!col[j]) col[j] = ++cnt ;
        if (!vis[v]) dfs(v) ;
    }
}

void process() {
    dfs(1) ;
    forinc(i,1,m) printf("%d %d %d\n" , edge[i].fi , edge[i].se , col[i]) ;
}

int main() {
    freopen("ONEGCD.inp" , "r" , stdin) ;
    freopen("ONEGCD.out" , "w" , stdout) ;
    enter() ;
    process() ;
    return 0 ;
}
