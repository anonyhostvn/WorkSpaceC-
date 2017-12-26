#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)
#define forv(j,u) for (int j = 0 ; j < u.size() ; j++)
#define pb push_back
#define pf push_front
#define fi first
#define se second

using namespace std ;

int n , m , s , d[200001] ;
vector <int> ke[200001] ;

int enter()
{
    cin >> n >> m ;
    forinc(i,1,m) {
        int u , v ;
        cin >> u >> v ;
        ke[u].push_back(v) ;
        ke[v].push_back(u) ;
    }
    cin >> s;
}

queue <int> q ;
set<int> l1 , l2 ;
set<int> :: iterator it ;
bool vis[200001] ;
int process()
{
    memset(vis,false,sizeof(vis)) ;
    memset(d,0,sizeof(d)) ;
    q.push(s) ;
    vis[s] = true ;
    forinc(i,1,n) if (i != s) l1.insert(i) ;
    while (!q.empty()){
        int u = q.front() ; q.pop() ;
        forv(j,ke[u]){
            int v = ke[u][j] ;
            if (!vis[v]){
                l1.erase(v) ;
                l2.insert(v) ;
            }
        }
        for (it = l1.begin() ; it != l1.end() ; it ++){
            vis[*it] = true ;
            d[*it] = d[u] + 1 ;
            q.push(*it) ;
        }
        l1 = l2 ;
        l2.clear() ;
    }
    forinc(i,1,n) if (i != s) cout << d[i] << " " ; cout << endl ;
    forinc(i,1,n) ke[i].clear() ;
}

int main()
{
    //freopen("bfs.inp" , "r" , stdin) ;
    //freopen("bfs.out" , "w" , stdout) ;
    int t ; cin >> t ;
    forinc(i,1,t){
        enter() ;
        process() ;
    }
}
