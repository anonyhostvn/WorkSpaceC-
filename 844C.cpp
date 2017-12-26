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

using namespace std ;

int n , cnt ;
pii a[100001] ;
bool vis[100001] ;
vector<int> ke[100001] , ans[1000001] ;

int enter()
{
    cin >> n ;
    forinc(i,1,n) {
        cin >> a[i].fi ;
        a[i].se = i ;
    }
    return 0 ;
}

int add(int u , int v)
{
    ke[u].pb(v) ;
    return 0 ;
}

int dfs(int u , int cnt)
{
    vis[u] = true ;
    ans[cnt].pb(u) ;
    forv(j,ke[u]){
        int v = ke[u][j] ;
        if (!vis[v]) dfs(v,cnt) ;
    }
    return 0 ;
}

int process()
{
    int cnt = 0 ;
    sort(a+1,a+1+n) ;
    forinc(i,1,n) add(i,a[i].se) ;
    forinc(i,1,n) if (!vis[i]) dfs(i,++cnt) ;
    cout << cnt << endl ;
    forinc(i,1,cnt) {
        cout << ans[i].size() << " " ;
        forv(j,ans[i]) cout << ans[i][j] << " " ; cout << endl ;
    }
    return 0 ;
}

int main()
{
    //freopen("844C.inp" , "r" , stdin) ;
    enter() ;
    process() ;
    return 0 ;
}
