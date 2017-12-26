#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)
#define forv(j,u) for (int j = 0 ; j < u.size() ; j++)

using namespace std ;

int n , d[100001] , cnt = 0 , edge[30000001][2] , lab[30000001] ;
vector<int> ke[100001] , ts[100001] ;

int enter()
{
    cin >> n  ;
    forinc(i,1,n-1){
        int u , v , t ;
        cin >> u >> v >> t ;
        ke[u].push_back(v) ;
        ts[u].push_back(t) ;
        ke[v].push_back(u) ;
        ts[v].push_back(t) ;
    }

    return 0 ;
}

int dfs(int u , int p)
{
    forv(j,ke[u]){
        int v = ke[u][j] ;
        if (v!=p) {
            d[v] = d[u] ^ ts[u][j] ;
            dfs(v,u) ;
        }
    }

    return 0 ;
}

int getbit(int x , int i)
{
    return (x >> i) & 1 ;
}

int add(int x)
{
    int u = 1 , a[31] ;
    forinc(i,0,30) a[i] = getbit(x,30-i) ;
    forinc(i,0,30){
        if (edge[u][a[i]] != 0) u = edge[u][a[i]] ;
        else {
            edge[u][a[i]] = ++cnt ;
            u = cnt ;
        }
    }
    lab[u] = x ;
    return 0 ;
}

int sfind(int x)
{
    int u = 1 , a[31] ;
    forinc(i,0,30) a[i] = getbit(x,30-i) ;
    forinc(i,0,30){
        if (edge[u][1-a[i]] != 0) u = edge[u][1-a[i]] ;
        else if (edge[u][a[i]] != 0) u = edge[u][a[i]] ;
        else return 0 ;
    }

    return lab[u] ^ x ;
}

int preset()
{
    forinc(i,1,n) {
        ke[i].clear() ;
        ts[i].clear() ;
    }
    forinc(i,1,cnt){
        edge[i][1] = 0 ;
        edge[i][0] = 0 ;
        lab[i] = 0 ;
    }

    return 0 ;
}

int process()
{
    int res = 0 ; cnt = 1 ;
    dfs(1,-1) ;
    forinc(i,1,n) add(d[i]) ;
    forinc(i,1,n) res = max(res,sfind(d[i])) ;
    cout << res << endl ;

    preset() ;

    return 0 ;
}

int main()
{
    freopen("pptree.inp" , "r" , stdin) ;
    freopen("pptree.out" , "w" , stdout) ;
    int t = 1 ;
    //cin >> t ;
    forinc(i,1,t){
        enter() ;
        process() ;
    }
    return 0 ;
}
