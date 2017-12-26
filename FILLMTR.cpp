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
#define maxN 1000001

using namespace std ;

int n , q ;
pair<pii,int> a[maxN] ;

int enter()
{
    cin >> n >> q ;
    forinc(i,1,q) cin >> a[i].fi.fi >> a[i].fi.se >> a[i].se ;
    return 0 ;
}

vector<int> ke[maxN] , ts[maxN] ;
vector<pair<pii,int> > redmun ;
bool vis[maxN] ;
int color[maxN] , lab[maxN] ;

int add(int u , int v , int w)
{
    ke[u].push_back(v) ;
    ke[v].push_back(u) ;
    ts[u].push_back(w) ;
    ts[v].push_back(w) ;
    return 0 ;
}

int getroot(int u)
{
    if (u == lab[u]) return u ;
    lab[u] = getroot(lab[u]) ;
    return lab[u] ;
}

int connect(int u, int v)
{
    lab[lab[u]] = lab[v] ;
    return 0 ;
}

int build_graph()
{
    forinc(i,1,n) lab[i] = i ;
    redmun.clear() ;
    forinc(i,1,q) if (getroot(a[i].fi.fi) != getroot(a[i].fi.se)) {
        add(a[i].fi.fi,a[i].fi.se,a[i].se) ;
        connect(a[i].fi.fi,a[i].fi.se) ;
    } else redmun.push_back(a[i]) ;
    return 0 ;
}

int dfs(int u)
{
    vis[u] = true ;
    forv(j,ke[u]) {
        int v = ke[u][j] , w = ts[u][j] ;
        if (!vis[v]) {
            if (w == 0) color[v] = color[u] ; else color[v] = 1 - color[u] ;
            dfs(v) ;
        }
    }
    return 0 ;
}

int reset()
{
    forinc(i,1,n) {
        ke[i].clear() ;
        vis[i] = false ;
        color[i] = 0 ;
        ts[i].clear() ;
    }
    return 0 ;
}

int process()
{
    build_graph() ;
    forinc(i,1,n) if (!vis[i]) dfs(i) ;
    forv(i,redmun) {
        int u = redmun[i].fi.fi , v = redmun[i].fi.se , w = redmun[i].se ;
        if (w == 0 && color[u] == color[v]) continue ;
        if (w == 1 && color[u] != color[v]) continue ;
        cout << "no" << endl ;
        return 0 ;
    }
    cout << "yes" << endl ;
    return 0 ;
}

int main()
{
    //freopen("FILLMTR.inp" , "r" , stdin) ;
    int t ; cin >> t ;
    while (t --) {
        enter() ;
        process() ;
        reset() ;
    }
    return 0 ;
}
