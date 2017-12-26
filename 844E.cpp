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
#define maxN 200001

using namespace std ;

int n , sz[maxN] , pal[maxN] , parent[maxN] ;
vector<int> ke[maxN] ;
struct ians{
    int vx , vu , vy ;
    ians (int a , int b , int c){
        vx = a ; vu = b ; vy = c ;
    }
};
vector<ians> ans ;

int enter()
{
    cin >> n ;
    forinc(i,1,n-1) {
        int u , v ;
        cin >> u >> v ;
        ke[u].push_back(v) ;
        ke[v].push_back(u) ;
    }
    return 0 ;
}

int dfs(int u , int par)
{
    sz[u] =  1 ;
    forv(j,ke[u]) {
        int v = ke[u][j] ;
        if (v != par){
            dfs(v,u) ;
            sz[u] += sz[v] ;
            pal[u] = max(pal[u],sz[v]) ;
        }
    }
    return 0 ;
}

vector<int> centroids , vertex ;

int explore(int u , int par)
{
    vertex.push_back(u) ;
    forv(j,ke[u]){
        int v = ke[u][j] ;
        if (v != par) {
            explore(v,u) ;
            parent[v] = u ;
        }
    }
    return 0 ;
}

int solve(int x , int par)
{
    forv(j,ke[x]){
        vertex.clear() ;
        int u = ke[x][j] ;
        if (u == par) continue ;
        explore(u,x) ;
        int cur_center = u ;
        forv(i,vertex){
            int v = vertex[i] ;
            if (v != u && parent[v] != u) ans.push_back(ians(v,parent[v],u)) ;
        }
    }
    return 0 ;
}

int process()
{
    dfs(1,-1) ;
    forinc(i,1,n) {
        pal[i] = max(pal[i],n-sz[i]) ;
        if (pal[i] <= n / 2) centroids.push_back(i) ;
    }
    if (centroids.size() == 1) solve(centroids[0],-1) ;
    else {
        solve(centroids[0],centroids[1]) ;
        solve(centroids[1],centroids[0]) ;
    }
    cout << ans.size() << endl ;
    forv(i,ans) cout << ans[i].vx << " " << ans[i].vu << " " << ans[i].vy << endl ;
    return 0 ;
}

int main()
{
    //freopen("844E.inp" , "r" , stdin) ;
    enter() ;
    process() ;
    return 0 ;
}
