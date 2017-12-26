#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)
#define forv(j,u) for (int j = 0 ; j < u.size() ; j++)

using namespace std ;

int n , m , a , b  , trc[1001] ;
bool d[1001][2001] ;
vector<pair<int,int> > ke[1001] ;

int enter()
{
    cin >> n >> m ;
    forinc(i,1,m){
        int u , v , c ; cin >> u >> v >> c ;
        ke[u].push_back(make_pair(v,c)) ;
        ke[v].push_back(make_pair(u,c)) ;
    }
    cin >> a >> b ;
}
queue <pair<int,int> > h ;

int dkstra()
{
    d[a][0] = true ;
    h.push(make_pair(a,0)) ;
    while (!h.empty()){
        pair<int,int> tmp = h.front() ;
        h.pop() ;
        int u = tmp.first , recent = tmp.second ;
        forv(j,ke[u]){
            int v = ke[u][j].first , dist = ke[u][j].second ;
            if (!d[v][recent | dist]){
                d[v][recent | dist] = true ;
                trc[v] = u ;
                h.push(make_pair(v,recent | dist)) ;
            }
        }
    }
}

int process()
{
    dkstra() ;
    forinc(i,0,2000) if (d[b][i]) {
        cout << i << endl ;
        return 0 ;
    }
    cout << -1 ;
    //trace(b) ;
}

int main()
{
    //freopen("path.inp" , "r" , stdin) ;
    enter() ;
    process() ;
}
