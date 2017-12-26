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
#define maxN 70001
#define maxL 17

using namespace std ;

int n , q , val[4*maxN+4] , l;
int stin[maxN+1] , stout[maxN+1] , cnt = 0 , f[maxN+1][maxL+1] ;
vector<int> ke[maxN] ;

int enter()
{
    cin >> n >> q ;
    forinc(i,1,n-1) {
        int u ,v ;
        cin >> u >> v ;
        ke[u].pb(v) ;
        ke[v].pb(u) ;
    }
    l = log2(n) ;
    return 0 ;
}

int dfs(int u , int p)
{
    stin[u] = ++cnt ;
    forinc(i,1,l) f[u][i] = f[f[u][i-1]][i-1] ;
    forv(j,ke[u]){
        int v = ke[u][j] ;
        if (v != p){
            f[v][0] = u ;
            dfs(v,u) ;
        }
    }
    stout[u] = ++cnt ;
    return 0 ;
}

bool anc(int u , int v)
{
    return (stin[u] <= stin[v] && stout[u] >= stout[v]) ;
}

int LCA(int u , int v)
{
    if (u == 0 && v == 0) return 0 ;
    else if (u == 0) return v ;
    else if (v == 0) return u ;
    if (anc(u,v)) return u ;
    if (anc(v,u)) return v ;
    fordec(i,l,0) if (!anc(f[u][i],v)) u = f[u][i] ;
    return f[u][0] ;
}

int update(int s , int l , int r , int i)
{
    if (r < i || i < l) return 0 ;
    if (l == r){
        val[s] = i ;
        return 0 ;
    }
    int mid = (l+r) / 2 ;
    update(2*s,l,mid,i) ;
    update(2*s+1,mid+1,r,i) ;
    val[s] = LCA(val[2*s],val[2*s+1]) ;
    return 0 ;
}

int get(int s , int l , int r , int u , int v)
{
    if (r < u || v < l) return 0 ;
    if (u <= l && r <= v) return val[s] ;
    int mid = (l+r) / 2 ;
    return LCA(get(2*s,l,mid,u,v) , get(2*s+1,mid+1,r,u,v)) ;
}

int prepare()
{
    f[1][0] = 1 ;
    dfs(1,-1) ;
    forinc(i,1,n) update(1,1,n,i) ;
    return 0 ;
}

int process()
{
    prepare() ;
    forinc(i,1,q){
        int u , v  ; cin >> u >> v ;
        cout << get(1,1,n,u,v) << endl ;
    }
    return 0 ;
}

int main()
{
    //freopen("VOTREE.inp" , "r" , stdin) ;
    enter() ;
    process() ;
    return 0 ;
}
