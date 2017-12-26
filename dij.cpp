#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)
#define forv(j,u) for (int j = 0 ; j < u.size() ; j++)
#define oo 2000000000000

using namespace std ;

int n , m , s  ;
long long d[3001] ;
vector<int> ke[3001] ,ts[3001] ;

int enter()
{
    cin >> n >> m ;
    forinc(i,1,m){
        int u , v , c ; cin >> u >> v >> c ;
        ke[u].push_back(v) ;
        ts[u].push_back(c) ;
        ke[v].push_back(u) ;
        ts[v].push_back(c) ;
    }
    cin >> s ;
}

priority_queue <pair<long long,int> > heap ;

int dkstra()
{
    forinc(i,1,n) d[i] = oo ;
    d[s] = 0 ;
    heap.push(make_pair(0,s)) ;
    while (!heap.empty()){
        pair<long long,int> tmp = heap.top() ;
        heap.pop() ;
        int u = tmp.second ;
        forv(j,ke[u]){
            int v = ke[u][j] ;
            if (d[v] > (long long)d[u] + ts[u][j]) {
                d[v] = (long long)d[u] + ts[u][j] ;
                heap.push(make_pair(d[v],v)) ;
            }
        }
    }
}

int process()
{
    dkstra() ;
    forinc(i,1,n) if (i!=s) if (d[i] < oo) cout << d[i] << " " ; else cout << -1 << " " ;  cout << endl ;
    forinc(i,1,n) {
        ke[i].clear() ;
        ts[i].clear() ;
    }
}

int main()
{
    //freopen("dij.inp" , "r" , stdin) ;
    int t ; cin >> t ;
    forinc(i,1,t) {
        enter();
        process() ;
    }
}
