#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)
#define forv(j,u) for (int j = 0 ; j < u.size() ; j++)

using namespace std ;

int n , m , s ;
vector<int> ke[3001] , ts[3001];
bool dd[3001] ;

int enter()
{
    cin >> n >> m ;
    forinc(i,1,m){
        int u , v , c ;  cin >> u >> v >> c ;
        ke[u].push_back(v) ;
        ts[u].push_back(c) ;
        ke[v].push_back(u) ;
        ts[v].push_back(c) ;
    }
    cin >> s ;
}

multiset<pair<int,pair<int,int> > > h ;

int process()
{
    dd[s] = true ;
    forv(j,ke[s]){
        int v = ke[s][j] ;
        h.insert(make_pair(ts[s][j],make_pair(s,v))) ;
    }
    int res = 0 ;
    while (!h.empty()){
        pair<int,pair<int,int> > tmp = *h.begin() ;
        h.erase(h.begin()) ;
        int u = tmp.second.first , v = tmp.second.second ;
        if (!dd[v]){
            res += tmp.first ;
            dd[v] = true ;
            forv(j,ke[v]){
                int vv = ke[v][j] ;
                if (!dd[vv]) h.insert(make_pair(ts[v][j],make_pair(v,vv))) ;
            }
        }
    }
    cout << res ;
}

int main()
{
    //freopen("prim.inp" , "r" , stdin) ;
    enter() ;
    process() ;
}
