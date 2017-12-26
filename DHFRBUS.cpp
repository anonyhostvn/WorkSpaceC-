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
#define maxK 5
#define ll long long

using namespace std ;

const ll oo = 2000000000000 ;
int n , m , k , s , t  ;
long long f[maxN+1][maxK+1] ;
vector<pair<int , ll> > ke[maxN+1] ;

int enter()
{
    cin >>  n >> m >> k >> s >> t ;
    forinc(i,1,m) {
        int u , v ; ll w ; cin >> u  >> v >> w ;
        ke[u].pb(mk(v,w)) ;
        ke[v].pb(mk(u,w)) ;
    }
}

priority_queue <pair<ll,pii> > heap ;

int dkstra()
{
    forinc(i,1,n)
    forinc(j,0,k) f[i][j] = oo ;
    f[s][0] = 0 ;
    heap.push(mk(0,mk(s,0))) ;
    while (!heap.empty()){
        pair<long long,pii> tmp = heap.top() ; heap.pop() ;
        int u = tmp.se.fi , tk = tmp.se.se ;
        forv(j,ke[u]){
            pii e = ke[u][j] ;
            int v = e.fi ; ll dist = e.se ;
            if (tk < k && f[v][tk+1] > f[u][tk]){
                f[v][tk+1] = f[u][tk] ;
                heap.push(mk(-f[v][tk+1],mk(v,tk+1))) ;
            }
            if (f[v][tk] > f[u][tk] + dist){
                f[v][tk] = f[u][tk] + dist ;
                heap.push(mk(-f[v][tk],mk(v,tk))) ;
            }
        }
    }
}

int process()
{
    dkstra() ;
    cout << f[t][k] ;
}

int main()
{
    //freopen("dhfrbus.inp" , "r" , stdin) ;
    enter() ;
    process() ;
}
