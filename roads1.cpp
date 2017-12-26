#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)
#define forv(j,u) for (int j = 0 ; j < u.size() ; j++)

using namespace std ;

int n , m , lab[100001] , f[100001]  ;
long long a[500001] ;
vector<pair <int,int> > ke[100001] ;
pair <int,pair<int,int> > list_edge[200001] ;

int enter()
{
    cin >> n >> m ;
    forinc(i,1,m) {
        int u , v , c  ; cin >> u >> v >> c ;
        list_edge[i].first = c ;
        list_edge[i].second.first = u ;
        list_edge[i].second.second = v ;
    }
    sort(list_edge+1,list_edge+m+1) ;
}

int getroot(int u)
{
    if (lab[u] == u) return u ;
    lab[u] = getroot(lab[u]) ;
    return lab[u] ;
}

int prepare()
{
    forinc(i,1,n) lab[i] = i ;
    forinc(i,1,m){
        bool ok = false ;
        int u = list_edge[i].second.first , v = list_edge[i].second.second ,dist = list_edge[i].first ;
        if (getroot(u) != getroot(v)) {
            lab[lab[u]] = lab[v] ;
            ok = true ;
        }
        if (ok){
            ke[u].push_back(make_pair(v,dist)) ;
            ke[v].push_back(make_pair(u,dist)) ;
        }
    }
}

int dfs(int u , int p)
{
    f[u] = 1 ;
    forv(j,ke[u]){
        int v = ke[u][j].first , dist = ke[u][j].second ;
        if (v != p){
            dfs(v,u) ;
            f[u] += f[v] ;
            a[dist] +=  (long long) f[v] * (n-f[v]) ;
        }
    }
}

int process()
{
    prepare() ;
    dfs(1,-1) ;
    forinc(i,0,500000) if (a[i] > 0) {
        a[i+1] += a[i] / 2 ;
        a[i] %= 2 ;
    }
    bool ok = false ;
    fordec(i,500000,0) if ((a[i] == 1) || ok){
        cout << a[i] ;
        ok = true ;
    }
}

int main()
{
    freopen("roads1.inp" , "r" , stdin) ;
    enter() ;
    process() ;
}
