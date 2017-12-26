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
#define maxN 150001

using namespace std ;

int n , m , lab[maxN] , num[maxN] , low[maxN] , cnt = 0 , ingre = 0  , degout_rev[maxN] , degout[maxN]  ,total = 0 ,
    vis[maxN] , number[maxN] , topo[maxN] , id[maxN] ;
vector<int> ke[maxN] , nxt[maxN] , setlab[maxN] , re_nxt[maxN] ;

int enter()
{
    cin >> n >> m ;
    forinc(i,1,m) {
        int u , v ; cin >> u >> v ;
        ke[u].push_back(v) ;
    }
    return 0 ;
}

stack<int> st ;

int dfs_recycle(int u)
{
    st.push(u) ;
    num[u] = ++cnt ; low[u] = cnt ;
    forv(j,ke[u]){
        int v = ke[u][j] ;
        if (lab[v] != 0) continue ;
        if (num[v] == 0){
            dfs_recycle(v) ;
            low[u] = min(low[u],low[v]) ;
        } else low[u] = min(low[u],num[v]) ;
    }
    if (num[u] == low[u]) {
        ingre ++ ; int v = -1 , cnt = 0 ;
        while (v != u) {
            v = st.top() ;
            st.pop() ; ++cnt ;
            lab[v] = ingre ;
            setlab[ingre].push_back(v) ;
        }
        number[ingre] = cnt ;
    }
    return 0 ;
}

int make_DAG()
{
    forinc(i,1,n) if (num[i] == 0) dfs_recycle(i) ;
    forinc(u,1,n)
    forv(j,ke[u]) {
        int v = ke[u][j] ;
        if (lab[v] != lab[u]) {
            nxt[lab[u]].push_back(lab[v]) ;
            re_nxt[lab[v]].push_back(lab[u]) ;
        }
    }
    return 0 ;
}

int stp(int u)
{
    vis[u] = true ;
    forv(j,nxt[u]){
        int v = nxt[u][j] ;
        if (!vis[v]) stp(v)  ;
    }
    topo[total] = u ;
    id[u] = total-- ;
    return 0 ;
}

int f[maxN] ;

int prepare()
{
    make_DAG() ;
    total = ingre ;
    forinc(i,1,ingre) if (!vis[i]) stp(i) ;
    return 0 ;
}

int process()
{
    prepare() ;
    int cnt = 0 ;
    forinc(i,2,ingre){
        int u = topo[i] ;
        forv(j,re_nxt[u]) {
            int v = re_nxt[u][j] ;
            degout_rev[v] ++ ;
            if (degout_rev[v] == 1) ++cnt ;
        }
        f[u] += cnt ;
    }
    cnt = 0 ;
    fordec(i,ingre-1,1) {
        int u = topo[i] ;
        forv(j,nxt[u]) {
            int v = nxt[u][j] ;
            degout[v] ++ ;
            if (degout[v] == 1) ++cnt ;
        }
        f[u] += cnt ;
    }

    int res = 0 ;
    forinc(i,1,n) if (f[lab[i]] == ingre-1) res ++ ;
    cout << res << endl ;
    forinc(i,1,n) if (f[lab[i]] == ingre-1) cout << i << " " ;
    return 0 ;
}

int main()
{
    freopen("TPCPPLAR.inp" , "r" , stdin) ;
    enter() ;
    process() ;
    return 0 ;
}
