#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)
#define forv(j,u) for (int j = 0 ; j < u.size() ; j++)
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define oo 1000000000

using namespace std ;

const double esp = 0.000000001 ;

struct node{
    int tv , ts , tt ;
};

vector <node> ke[10001] ;

int n , e , step[601] ;
bool dd[601] , f[601] ;
double limit = 0 , d[601] ;

int enter()
{
    cin >> n >> e ;
    forinc(i,1,e){
        int u , v , s , t ; cin >> u >> v >> s >> t ;
        node tmp ;
        tmp.tv = v ; tmp.ts = s ; tmp.tt = t ;
        ke[u].pb(tmp) ;
        limit = max(limit,(double)s) ;
    }
    return 0 ;
}

int dfs(int u)
{
    dd[u] = true ;
    if (u == n){ f[u] = true ; return 0 ; }
    forv(j,ke[u]){
        int v = ke[u][j].tv ;
        if (!dd[v]) dfs(v) ;
        f[u] = f[v] ;
        if (f[u]) return 0 ;
    }
}

queue <int> q ;

bool check(double mid)
{
    memset(step,0,sizeof(step)) ;
    memset(dd,false,sizeof(dd)) ;
    forinc(i,1,n) d[i] = oo ;
    d[1] = 0 ; step[1] = 1  ; dd[1] = true ;
    q.push(1) ;
    while (!q.empty()) {
        int u = q.front() ; q.pop() ; dd[u] = false ;
        if (step[u] == n && f[u]) return true ;
        forv(j,ke[u]){
            int v = ke[u][j].tv , dist = ke[u][j].ts , time = ke[u][j].tt ;
            if (d[v] > d[u] + (double)dist - (double)mid * time ){
                d[v] = d[u] + (double)dist - (double)mid * time ;
                if (v == n && d[v] <= 0) return true ;
                if (step[v] < n && !dd[v]) {
                    q.push(v) ;
                    dd[v] = true ;
                    ++step[v] ;
                }
            }
        }
    }
    return false ;
}

int process()
{
    forinc(i,1,n) if (!dd[i]) dfs(i) ;
    double l = 0 , r = limit + esp , res = -1 ;
    while (l + esp <= r){
        double mid = (l+r) / 2 ;
        if (check(mid)){
            res = mid ;
            r = mid - esp  ;
        }
        else l = mid + esp ;
    }
    if (res == -1) cout << res ; else cout << fixed << setprecision(6) << res ;
    return 0 ;
}

int main()
{
    //freopen("VMSPEED.inp" , "r" , stdin) ;
    enter() ;
    process() ;
    return 0 ;
}
