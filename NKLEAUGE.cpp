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
#define maxN 1001

using namespace std ;

int a[maxN][maxN] , n = 0 , cnt , topo[maxN] ;
vector<int> ke[maxN] ;
bool vis[maxN] ;

int enter()
{
    cin >> n ; cnt = n  ;
    forinc(i,1,n) {
        string st ; cin >> st ;
        forinc(j,1,n) {
            int x = (int) st[j-1] - (int) '0' ;
            if (x == 1) ke[i].push_back(j) ;
        }
    }
    return 0 ;
}

int dfs(int u)
{
    vis[u] = true ;
    forv(j,ke[u]) {
        int v = ke[u][j] ;
        if (!vis[v]) dfs(v) ;
    }
    topo[cnt--] = u ;
    return  0 ;
}

int process()
{
    forinc(i,1,n) if (!vis[i]) dfs(i) ;
    forinc(i,1,n) cout << topo[i] << " " ;
    return 0 ;
}

int main()
{
    //freopen("NKLEAUGE.inp" , "r" , stdin) ;
    enter() ;
    process() ;
    return 0 ;
}
