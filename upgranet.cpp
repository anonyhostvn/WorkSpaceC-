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
#define maxM 100000
#define maxL 20
#define oo 1000000000

using namespace std ;

int n , m , lab[maxN+1] , far[maxN+1][maxL+1] ,l , stin[maxN+1] ,stout[maxN+1] , cnt = 0 , dmin[maxN+1][maxL+1] ;
pair<int  , pii> edge[maxM+1] ;
vector<pii> ke[maxN+1] ;
vector<int> bade ;

int enter()
{
    cin >> n >> m ;
    forinc(i,1,m) cin >> edge[i].se.fi >> edge[i].se.se >> edge[i].fi ;
    sort(edge+1,edge+1+m) ;
    l = log2(n) ;
    return 0 ;
}

int getroot(int u)
{
    if (u == lab[u]) return u ;
    lab[u] = getroot(lab[u]) ;
    return lab[u] ;
}

int dfs(int u , int p)
{
    stin[u] = ++cnt ;
    forinc(i,1,l) far[u][i] = far[far[u][i-1]][i-1] ;
    forinc(i,1,l) dmin[u][i] = min(dmin[u][i-1],dmin[far[u][i-1]][i-1]) ;
    forv(j,ke[u]){
        int v = ke[u][j].fi ;
        if (v != p){
            far[v][0] = u ;
            dmin[v][0] = ke[u][j].se ;
            dfs(v,u) ;
        }
    }
    stout[u] = ++cnt ;
    return 0 ;
}

int anc(int u , int v)
{
    return (stin[u] <= stin[v] && stout[u] >= stout[v]) ;
}

int LCA(int u , int v)
{
    if (anc(u,v)) return u ;
    if (anc(v,u)) return v ;
    fordec(i,l,0) if (!anc(far[u][i],v)) u = far[u][i] ;
    return far[u][0] ;
}

int getmin(int u , int v)
{
    if (!anc(u,v) && !anc(v,u)) {
        int p = LCA(u,v) ;
        return min(getmin(p,u),getmin(p,v)) ;
    }
    if (anc(v,u)) swap(u,v) ;
    int res = oo ;
    fordec(i,l,0) if (!anc(far[v][i],u)) {
        res = min(res,dmin[v][i]) ;
        v = far[v][i] ;
    }
    res = min(res,dmin[v][0]) ;
    return res ;
}

int prepare()
{
    forinc(i,1,n) lab[i] = i ;
    fordec(i,m,1) {
        int u = edge[i].se.fi , v = edge[i].se.se , dist = edge[i].fi ;
        if (getroot(u) != getroot(v)){
            lab[lab[u]] = lab[v] ;
            ke[u].pb(mk(v,dist)) ;
            ke[v].pb(mk(u,dist)) ;
        }
        else bade.pb(i) ;
    }
    dmin[1][0] = oo ;
    far[1][0] = 1 ;
    dfs(1,-1) ;
    return 0 ;
}

int process()
{
    prepare() ;
    long long res = 0 ;
    forv(j,bade){
        int i = bade[j] , w = edge[i].fi , u = edge[i].se.fi , v = edge[i].se.se ;
        res += getmin(u,v) - w ;
    }
    cout << res ;
    return 0 ;
}

int main()
{
    //freopen("upgranet.inp" , "r" , stdin) ;
    enter() ;
    process() ;
    return 0 ;
}
