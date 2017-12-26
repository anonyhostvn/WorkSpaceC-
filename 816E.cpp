#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)

using namespace std ;

int n , b , d[5001] , c[5001] , f[5001][3][5001] ;

vector<int> ke[5001] ;

int enter()
{

    cin >> n >> b ;

    cin >> d[1] >> c[1] ;

    forinc(i,2,n)
    {

        int u  ;

        cin >> d[i] >> c[i] >> u ;

        ke[i].push_back(u) ;

    }

}

int prepare()
{

    forinc(i,1,n)
    {

        forinc(j,1,n)
        {

            f[i][0][j] = 0 ;
            f[i][1][j] = d[i] - c[i] ;
            f[i][2][j] = d[i] ;

        }

    }

}

int dfs(int u , int p)
{

    int jr = 0 ;

    for (int j = 0 ; j < ke[u].size() ; j++)
    {

        int v = ke[u][j] ;

        if (v != p)
        {

            dfs(v,u) ;
            jr ++ ;

        }

    }

    forinc(j,0,jr+1)
    {
    }

}

int main()
{

}
