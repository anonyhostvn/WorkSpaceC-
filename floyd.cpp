#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)
#define forv(j,u) for (int j = 0 ; j < u.size() ; j++)
#define oo 1000000000

using namespace std ;

int n , m , dist[401][401] ;

int enter()
{
    cin >> n >> m ;
    forinc(i,1,n)
    forinc(j,1,n) if (i != j) dist[i][j] = oo ;
    forinc(i,1,m) {
        int u , v , c ;
        cin >> u >> v >> c ;
        dist[u][v] = c ;
    }
}

int process()
{
    forinc(i,1,n)
    forinc(u,1,n)
    forinc(v,1,n) if (dist[u][v] > dist[u][i] + dist[i][v]) dist[u][v] = dist[u][i] + dist[i][v] ;

    int q ; cin >> q ;
    forinc(i,1,q){
        int u , v ; cin >> u >> v ;
        cout << ((dist[u][v] < oo) ? (dist[u][v]) : (-1)) << endl ;
    }
}

int main()
{
    freopen("floyd.inp" , "r" , stdin) ;
    enter() ;
    process() ;
}
