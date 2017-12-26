#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)
#define forv(j,u) for (int j = 0 ; j < u.size() ; j++)
#define pb push_back
#define pf push_front
#define fi first
#define se second

using namespace std ;

int n , f[401] ;
vector<int> ke[401] ;

int enter()
{
    cin >> n ;
    int u ;
    while (cin >> u) {
        int m ; cin >> m ;
        forinc(j,1,m){
            int v ; cin >> v ;
            ke[u].push_back(v) ;
            ke[v].push_back(u) ;
        }
    }
    return 0 ;
}

int dfs(int u , int p)
{
    int scon = 0 , a[401]  ;
    forv(j,ke[u]){
        int v = ke[u][j] ;
        if (v != p){
            dfs(v,u) ;
            a[++scon] = f[v] ;
        }
    }
    if (scon == 0) { f[u] = 1 ; return 0 ;}
    sort(a+1,a+1+scon,greater<int>() ) ;
    int recent = a[1] - 1 , res = a[1] ;
    forinc(i,2,scon){
        if (recent >= a[i]) recent -- ;
        else res ++ ;
    }
    f[u] = res ;
    return 0 ;
}

int process()
{
    dfs(1,-1) ;
    cout << f[1] ;
    return 0 ;
}

int main()
{
    //  freopen("STONE1.inp" , "r" , stdin) ;
    enter() ;
    process() ;
    return 0 ;
}
