#include <bits/stdc++.h>
#define oo 2000000000000
#define forinc(i,a,b) for (int i = a ; i  <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i  >= b ; i --)

using namespace std ;

int n , m , p ;
long long d[1001] ;

vector <int> ke[1001] , ts[1001] ;

int add(int u , int v , int c)
{

    ke[u].push_back(v) ;
    ts[u].push_back(c) ;

}

int enter()
{

    cin >> n >> m >> p ;

    int cnt = 0 ;

    forinc(i,1,n-1) add(i+1,i,0) ;

    forinc(i,1,m)
    {

        int u , v , c ;

        cin >> u >> v >> c ;

        add(u,v,c) ;

    }

    forinc(i,1,p)
    {

        int u ,v , c ;

        cin >> u >> v >> c ;

        add(v,u,-c) ;

    }

}

int resub()
{

    forinc(i,1,n) d[i] = oo ;

    d[1] = 0 ; int change = 0 ;

    forinc(i,1,n)
    {

        change = 0 ;

        forinc(u,1,n)
        for (int j = 0 ; j < ke[u].size() ; j++)
        {

            int v = ke[u][j] ;

            if (d[v] > (long long)d[u] + ts[u][j])
            {

                d[v] = (long long)d[u]  + ts[u][j];
                change = 1 ;

            }

        }

    }

    if (change == 1) cout << -1  ;
    else if (d[n] == oo) cout << -2 ;
    else cout << d[n] ;

}

int main ()
{

    freopen("build.inp" , "r" , stdin) ;
    freopen("build.out" , "w" , stdout) ;

    enter();
    resub() ;

}
