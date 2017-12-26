#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)
#define forv(i,u) for (int j = 0 ; j < u.size() ; j++)

using namespace std ;

int n , f[10001] , t[10001] , res ;
vector <int> ke[10001] ;

int enter()
{
    cin >> n ;
    forinc(i,1,n-1){
        int u , v ;
        cin >> u >> v ;
        ke[u].push_back(v) ;
        ke[v].push_back(u) ;
    }
}

int dfs(int u , int p)
{
    int nt[3] , cnt = 0 , d = 0 ;
    memset(nt,0,sizeof(nt)) ;

    forv(j,ke[u]){
        int v = ke[u][j] ;
        if (v != p){
            dfs(v,u) ;
            d ++ ;
            cnt += f[v] ;
            nt[t[v]] ++ ;
        }
    }

    if (d == 0){
        f[u] = 0 ;
        t[u] = 2 ;
        return 0 ;
    }

    if (nt[0] == 0){
        if (nt[2] != 0) {
            f[u] = cnt + 1 ;
            t[u] = 0 ;
        }
        else {
            f[u] = cnt ;
            t[u] = 2 ;
        }
    }
    else {
        f[u] = cnt - nt[0] / 2 ;
        if (nt[0] % 2 == 0) t[u] = 1 ; else t[u] = 0 ;
    }
}

int process()
{
    memset(f,0,sizeof(f)) ;
    dfs(0,-1) ;
    cout << f[0] << endl ;
    forinc(i,0,n) ke[i].clear() ;
}

int main()
{
    //freopen("roads.inp" , "r" , stdin) ;
    //freopen("roads.out" , "w" , stdout) ;

    int t = 0 ;
    cin >> t ;
    forinc(i,1,t)
    {
        enter() ;
        process() ;
    }
}
