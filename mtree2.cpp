#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)
#define forv(j,u) for (int j = 0 ; j < u.size() ; j++)

using namespace std ;

int n , m , cnt = 0 , num[100001] , fc[100001] , it[400001] , rem[400001] , val[400001] ;
vector<int> ke[100001] ;

int enter()
{
    cin >> n >> m ;
    forinc(i,1,n-1){
        int u , v ;
        cin >> u >> v ;
        ke[u].push_back(v) ;
        ke[v].push_back(u) ;
    }

    return 0 ;
}

int dfs(int u, int p)
{
    fc[u] = 1 ;
    num[u] = ++cnt ;
    forv(j,ke[u]){
        int v = ke[u][j] ;
        if (v != p) {
            dfs(v,u) ;
            fc[u] += fc[v] ;
        }
    }

    return 0 ;
}

int trans(int s , int l , int r)
{
    if (rem[s] == 0) return 0 ;
    rem[2*s] = rem[s] ;
    rem[2*s+1] = rem[s] ;
    it[2*s+1] = rem[s] ; it[2*s] = rem[s] ;
    rem[s] = 0 ;

    return 0 ;
}

int update1(int s , int l , int r , int u, int v , int k)
{
    if (v < l || r < u) return 0 ;
    if (u <= l && v >= r){
        rem[s] = k ;
        it[s] = k ;
        return 0  ;
    }

    int mid = (l+r) / 2 ;
    trans(s,l,r) ;
    update1(2*s,l,mid,u,v,k) ;
    update1(2*s+1,mid+1,r,u,v,k) ;

    return 0 ;
}

int get1(int s , int l , int r , int u)
{
    if (u < l || r < u) return 0 ;
    if (l == r) return it[s] ;
    int mid = (l+r) / 2 ;
    trans(s,l,r) ;
    return max(get1(2*s,l,mid,u),get1(2*s+1,mid+1,r,u)) ;
}

int update2(int s , int l , int r , int u ,int k)
{
    if (u < l || r < u) return 0 ;
    if (l == r){
        val[s] = k ;
        return 0 ;
    }

    int mid = (l + r) / 2 ;
    update2(2*s,l,mid,u,k) ;
    update2(2*s+1,mid+1,r,u,k) ;
    val[s] = max(val[2*s],val[2*s+1]) ;

    return 0  ;
}

int get2(int s , int l , int r , int u , int v)
{
    if (r < u || v < l) return 0 ;
    if (u <= l && r <= v) return val[s] ;
    int mid = (l+r) / 2 ;
    return max(get2(2*s,l,mid,u,v),get2(2*s+1,mid+1,r,u,v)) ;
}

int solve(int v)
{
    int t1 = get1(1,1,n,num[v]) , t2 = get2(1,1,n,num[v],num[v]+fc[v]-1) ;
    //cout << t1 << " " << t2 << endl ;
    if (t1 > t2) cout << 1 << endl ; else cout << 0 << endl ;
}

int process()
{
    dfs(1,-1) ;
    forinc(i,1,m){
        int query = 0 , v ;
        cin >> query >> v ;
        if (query == 1) update1(1,1,n,num[v],num[v]+fc[v]-1,i) ;
        else if (query == 2) update2(1,1,n,num[v],i) ;
        else solve(v) ;
    }
}

int main()
{
    freopen("mtree2.inp" , "r" , stdin) ;
    freopen("mtree2.out" , "w" , stdout) ;

    enter() ;
    process() ;

    return 0 ;
}
