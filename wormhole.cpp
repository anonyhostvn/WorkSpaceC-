#include <bits/stdc++.h>
#define oo 200000000
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)

using namespace std ;

int n , m , w ;

vector <int> ke[501] , ts[501] ;

long long d[501] ;

int add(int u , int v , int c)
{

    ke[u].push_back(v) ;
    ts[u].push_back(c) ;

}

int process()
{

    forinc(i,1,n) d[i] = oo ;

    d[1] = 0 ;

    int change = 0 ;

    forinc(i,1,n)
    {

        change = 0 ;

        forinc(u,1,n)
        for (int j = 0 ; j < ke[u].size() ; j ++)
        {

            int v = ke[u][j] ;

            if (d[v] > d[u] + ts[u][j])
            {

                d[v] = d[u] + ts[u][j] ;

                change = 1 ;

            }

        }

    }

    if (change == 1) cout << "YES" << endl ;
    else cout << "NO" << endl ;

}

int enter()
{

    int f ;

    cin >> f ;

    forinc(test,1,f)
    {

        cin >> n >> m >> w ;

        int u , v , c ;

        forinc(i,1,m)
        {

            cin >> u >> v >> c ;

            add(u,v,c) ;
            add(v,u,c) ;

        }

        forinc(i,1,w)
        {

            cin >> u >> v >> c ;

            add(u,v,-c) ;

        }

        process();

        forinc(i,1,n)
        {

            while (!ke[i].empty()) ke[i].pop_back() ;
            while (!ts[i].empty()) ts[i].pop_back() ;

        }

    }

}

int main()
{

    freopen("wormhole.inp" , "r" , stdin) ;
    freopen("wormhole.out" , "w" , stdout) ;

    enter() ;

}
