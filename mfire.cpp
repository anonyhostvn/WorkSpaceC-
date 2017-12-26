#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)
#define forv(i,u) for (int j = 0 ; j < ke[u].size() ; j++)

using namespace std ;

int n , m ,k , root[100001] , d[100001] ;
vector <int> ke[100001] ;

int enter()
{
    cin >> n >> m >> k ;
    forinc(i,1,k) cin >> root[i] ;
    forinc(i,1,m){
        int u , v ;
        cin >> u >> v ;
        ke[u].push_back(v) ;
        ke[v].push_back(u) ;
    }
}

queue <int> q ;

int process()
{
    forinc(i,1,k) {
        q.push(root[i]) ;
        d[root[i]] = 1 ;
    }

    while (!q.empty()){
        int u = q.front() ;
        q.pop() ;
        forv(j,u){
            int v = ke[u][j] ;
            if (d[v] == 0) {
                d[v] = d[u] + 1 ;
                q.push(v) ;
            }
        }
    }

    forinc(i,1,n) cout << d[i] - 1 << endl ;
}

int main()
{
    freopen("mfire.inp" , "r" , stdin) ;
    freopen("mfire.out" , "w" , stdout) ;

    enter() ;
    process() ;
}
