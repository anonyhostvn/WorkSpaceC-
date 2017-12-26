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
#define oo (int) 1e9
#define maxN 1005

using namespace std ;

int n , m , c[maxN][maxN] , t , k , Tmin[maxN] , Cmin = oo  , f[maxN][maxN] ;
bool dd[maxN][maxN] ;
vector<pii> ke[2][maxN]  ;

void enter()
{
    cin >> n >> m >> t >> k  ;
    forinc(i,1,m) {
        int u , v , w ; cin >> u >> v >> w ;
        c[u][v] = w ;
        ke[1][v].push_back(mk(u,w)) ;
        ke[0][u].push_back(mk(v,w)) ;
        Cmin = min(Cmin,w) ;
    }
}

priority_queue<pii> q ;

void dkstra()
{
    forinc(i,1,n) Tmin[i] = oo ;
    Tmin[t] = 0 ;
    q.push(mk(0,t)) ;
    while (!q.empty()){
        pii tmp = q.top() ; q.pop() ;
        int u = tmp.se ;
        forv(i,ke[1][u]) {
            int v = ke[1][u][i].fi , w = ke[1][u][i].se ;
            if (Tmin[v] > Tmin[u] + w) Tmin[v] = Tmin[u] + w , q.push(mk(-Tmin[v],v)) ;
        }
    }
}

int cal(int u , int L)
{
    if (L < 0) return 0 ;
    if (dd[u][L]) return f[u][L] ;
    dd[u][L] = true ;
    if (u == t) { f[u][L] = 1 ; return 1 ;}
    int res = 0 ;
    forv(i,ke[0][u]) {
        int v = ke[0][u][i].fi , w = ke[0][u][i].se ;
        int tmp = cal(v,L+Tmin[u]-w-Tmin[v]) ;
        if (res > oo - tmp) res = oo + 1 ; else res += tmp ;
    }
    f[u][L] = res ;
    return res ;
}

vector<int> ans ;

void solve(int u , int L,int lexico)
{
    ans.push_back(u) ;
    if (u == t) return ;
    forinc(i,1,n) if (c[u][i] > 0) {
        int tmp = L + Tmin[u] - c[u][i] - Tmin[i] ;
        if (tmp < 0) continue ;
        if (lexico > f[i][tmp]) lexico -= f[i][tmp] ;
            else {solve(i,tmp,lexico) ; break  ; }
    }
}

void process()
{
    dkstra() ;
    cal(1,Cmin) ;
    solve(1,Cmin,k) ;
    if (ans.back() != t) cout << -1 ; else {
        cout << ans.size() << endl ;
        forv(i,ans) cout << ans[i] << " " ; cout << endl ;
    }
}

int main()
{
    freopen("QOS.inp" , "r" , stdin) ;
    enter() ;
    process() ;
    return  0 ;
}
