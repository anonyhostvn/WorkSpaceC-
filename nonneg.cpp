#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i--)
#define oo 10000000000

using namespace std ;

int n , m , p , s ;

vector <int> ke[25001] , ts[25001] , diff[25001] ;

int add(int u , int v , int c , int type)
{

    ke[u].push_back(v) ;
    ts[u].push_back(c) ;
    diff[u].push_back(type) ;

}

int enter()
{

    cin >>  n >> m >> p >> s ;

    forinc(i,1,m)
    {

        int u , v , c ;

        cin >> u >> v >> c ;

        add(u,v,c,2) ;
        add(v,u,c,2) ;

    }

    forinc(i,1,p)
    {

        int u ,v , c ;

        cin >> u >> v >> c ;

        add(u,v,c,1) ;

    }

}

//___________________________________________________________________________________________________________________________________

bool lab[25001] , topo[25001] , fre[25001] ;
struct node
{

    int sto , su ;
    long long dist ;

};

struct cmp
{

    bool operator() (node a , node b)
    {

        return (a.sto < b.sto) || (a.dist < b.dist) ;

    }

};

node adj[25001] ;

multiset <node , cmp> proset ;
multiset <node , cmp> :: iterator it ;

bool inset[25001] ;

int dfs(int u , int label)
{

    lab[u] = label ;

    for (int j = 0 ; j < ke[u].size() ; j++)
        if ((diff[u][j] == 2) && (lab[ke[u][j]] == 0))  dfs(ke[u][j],label) ;

}

int dfs1(int u , int stop)
{

    fre[u] = true ;
    topo[lab[u]] = stop ;

    for (int j = 0 ; j < ke[u].size() ; j++)
        if ((diff[u][j] == 1) && (!fre[ke[u][j]])) dfs(ke[u][j],stop+1) ;
        else dfs(ke[u][j],stop) ;

}

int prepare()
{

    int cnt = 0 ;

    forinc(i,1,n)
    if (lab[i] == 0)
    {

        cnt ++ ;

        dfs(i,cnt) ;

    }

    dfs1(s,1) ;

    forinc(i,1,n)
    {

        adj[i].su = i ;

        adj[i].sto = topo[lab[i]] ;

    }

}

int dkstra ()
{

    forinc(i,1,n) adj[i].dist = oo ;

    adj[s].dist = 0 ;

    proset.insert(adj[s]) ;
    inset[s] = true ;

    while (!proset.empty())
    {

        node tmp = (*(proset.begin())) ;
        proset.erase(proset.begin()) ;

        int u = tmp.su , type = tmp.sto  ;
        long long sd = tmp.dist ;

        for (int j = 0 ; j < ke[u].size() ; j++)
        {

            int v = ke[u][j] ;

            if (adj[v].dist > adj[u].dist + ts[u][j])
            {

                node backup = adj[v] ;

                adj[v].dist = adj[u].dist + ts[u][j] ;

                if (inset[v]) proset.erase(proset.find(backup)) ;

                proset.insert(adj[v]) ;

            }

        }

    }

}

int process()
{

    prepare() ;

    dkstra() ;

    forinc(i,1,n)
    if (adj[i].dist == oo) cout << "NO PATH" << endl ;
    else cout << adj[i].dist << endl ;

}

int main()
{

    freopen("nonneg.inp" , "r" , stdin) ;
    freopen("nonneg.out" , "w" , stdout) ;

    enter() ;
    process() ;

}
