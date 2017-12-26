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
#define oo 1000000000

using namespace std ;

int n , k , a[maxN+1] , top , scut = 0 , val = 0 ;
long long f[maxN+1] , b[maxN+1] ;
vector<int> ke[maxN+1] ;

int enter()
{
    cin >> n >> k ;
    forinc(i,1,n) {cin >> a[i] ; val = max(val,a[i]) ; }
    forinc(i,1,n-1){
        int u , v ; cin >> u >> v ;
        ke[u].pb(v) ;
        ke[v].pb(u) ;
    }
    return 0 ;
}

int dfs(int u , int p , int wei)
{
    int cnt = 0 ,  select = 0 , scon = 0 ;
    long long sumwei = a[u] ;
    forv(j,ke[u]){
        int v = ke[u][j] ;
        if (v != p) {
            ++scon ;
            dfs(v,u,wei) ;
        }
    }
    forv(j,ke[u]) if (ke[u][j] != p) b[++cnt] = f[ke[u][j]] ;
    sort(b+1,b+1+cnt) ;
    forinc(i,1,cnt) if (sumwei + b[i] <= wei){
        sumwei += b[i] ;
        select ++ ;
    } else break ;
    scut += scon - select ;
    f[u] = sumwei ;
    return 0 ;
}

bool possible(int x)
{
    scut = 0 ;
    dfs(1,-1,x) ;
    return scut <= k ;
}

int process()
{
    int l = val , r = oo , res = 0 ;
    while (l <= r){
        int mid = (l+r) / 2 ;
        if (possible(mid)) {
            r = mid - 1 ;
            res = mid ;
        }
        else l = mid + 1 ;
    }
    cout << res ;
    return 0 ;
}

int main()
{
    freopen("VMCUT2.inp", "r" , stdin) ;
    enter() ;
    process() ;
    return 0 ;
}
