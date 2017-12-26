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
#define maxN 100000

using namespace std ;

int n , m , dist[maxN+5] , c[maxN+5][10] ;
bool vis[maxN+5][10] , dd[maxN+5] ;
vector<pii> ke[maxN+5] ;

int enter()
{
    cin >> n >> m ;
    forinc(i,1,m) {
        int u , v , w ; cin >> u >> v >> w ;
        w %= 10 ;
        ke[u].pb(mk(v,w)) ;
        ke[v].pb(mk(u,-w)) ;
    }
    return 0 ;
}

queue<pii> q ;

int bfs(int xroot)
{
    vector<int> a ;
    q.push(mk(xroot,0)) ;
    vis[xroot][0] = true ;
    while (!q.empty()){
        pii tmp = q.front() ; q.pop() ;
        int u = tmp.fi , recent = tmp.se ;
        if (!dd[u]) {
            a.pb(u) ;
            dd[u] =  true ;
        }
        dist[u] = recent ;
        c[xroot][recent] ++ ;
        forv(j,ke[u]) {
            int v = ke[u][j].fi , nxt = (recent + ke[u][j].se + 10) % 10 ;
            if (!vis[v][nxt]){
                vis[v][nxt] = true ;
                q.push(mk(v,nxt)) ;
            }
        }
    }

    forv(j,a){
        int u = a[j] ;
        forinc(i,0,9)
            c[u][i] = c[xroot][(i + dist[u]) % 10] ;
    }
    return 0 ;
}

int process()
{
    forinc(i,1,n) if (!dd[i]) bfs(i) ;
    forinc(digit,0,9) {
        long long ans = 0 ;
        forinc(i,1,n) ans += c[i][digit] - (int) vis[i][(digit + dist[i]) % 10] ;
        cout << ans << endl ;
    }
    return 0 ;
}

int main()
{
    freopen("digits.inp" , "r" , stdin) ;
    enter() ;
    process() ;
    return  0 ;
}
