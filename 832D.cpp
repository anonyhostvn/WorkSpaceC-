#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)
#define forv(j,u) for (int j = 0 ; j < u.size() ; j++)

using namespace std ;

int n , q , in , out , tin[100001] , tout[100001] , f[100001][20] , l , d[100001];

vector <int> ke[100001] ;

int enter()
{
    cin >> n >> q ;
    forinc(i,2,n){
        int u , v ;
        cin >> u ;
        ke[i].push_back(u) ;
        ke[u].push_back(i) ;
    }
    l = log2(n) ;
    return 0 ;
}

int dfs(int u , int p)
{
    tin[u] = ++in ;
    forinc(i,1,l) f[u][i] = f[f[u][i-1]][i-1] ;
    forv(j,ke[u]){
        int v = ke[u][j] ;
        if (v != p) {
            f[v][0] = u ;
            d[v] = d[u] + 1 ;
            dfs(v,u) ;
        }
    }
    tout[u] = ++out ;
    return 0 ;
}

bool anc(int u , int v)
{
    if (tin[u] <= tin[v] && tout[u] >= tout[v]) return true ;
    return false ;
}

int LCA(int u , int v)
{
    if (anc(u,v)) return u ;
    if (anc(v,u)) return v ;
    fordec(i,l,0)
        if (!anc(f[u][i],v)) u = f[u][i] ;
    return f[u][0] ;
}

int intersect(int u1 , int v1 , int u2 , int v2)
{
    int p = LCA(u1,u2) ;
    return max(0,d[p] - max(d[v1],d[v2]) ) ;
}

int solve(int s, int f , int t)
{
    int par1 = LCA(s,f) , par2 = LCA(f,t) ;
    return intersect(s,par1,f,par2) + intersect(s,par1,t,par2) + intersect(f,par1,f,par2) + intersect(f,par1,t,par2) + 1    ;
}

int process()
{
    f[1][0] = 1;
    dfs(1,-1) ;
    forinc(i,1,q){
        int a , b , c  ;
        cin >> a >> b >> c ;
        cout << max(solve(a,b,c),max(solve(b,c,a),solve(b,a,c))) << endl ;
    }
    return 0 ;
}

int main()
{
    //freopen("832D.inp" , "r" , stdin ) ;
    enter() ;
    process() ;
    return 0 ;
}
