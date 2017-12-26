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
#define ooll (long long) 1e15
#define ooit (int) 2e9
#define maxN 100005

using namespace std ;

int n ;
pii a[maxN] ;
vector<int> ke[maxN] ;

void enter() {
    cin >> n ;
    forinc(i,1,n) cin >> a[i].fi ;
    forinc(i,1,n) a[i].se = i ;
    forinc(v,2,n) {
        int u ; cin >> u ;
        ke[u].push_back(v) ;
    }
}

int id[maxN] , f[maxN]  , cnt = 0 ;

void dfs(int u , int p) {
    f[u] = 1 ; id[u] = ++ cnt ;
    for (auto v : ke[u]) if (v != p) dfs(v,u) , f[u] += f[v] ;
}

int BIT[maxN] ;

void update(int i , int x) {for ( ; i <= n ; i += i & -i ) BIT[i] += x ; }

int get(int i) {int res = 0 ; for ( ; i > 0 ; i -= i & -i) res += BIT[i] ; return res ; }

int ans[maxN] ;

void solve(int l , int r) {
    forinc(i,l,r) ans[a[i].se] = get(id[a[i].se] + f[a[i].se] - 1) - get(id[a[i].se]) ;
    forinc(i,l,r) update(id[a[i].se],1) ;
}

bool cmp(pii a , pii b) {return a.fi > b.fi ; }

void process() {
    dfs(1,-1) ;
    sort(a+1,a+1+n,cmp) ;
    int j = 1 ;
    forinc(i,2,n) if (a[i].fi != a[i-1].fi) solve(j,i-1) , j = i ;
    solve(j,n) ;
    forinc(i,1,n) cout << ans[i] << endl ;
}

int main () {
    freopen("promote.in" , "r" , stdin) ;
    freopen("promote.out" , "w" , stdout) ;
    enter() ;
    process() ;
    return 0 ;
}
