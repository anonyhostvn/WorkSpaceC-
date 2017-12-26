#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)
#define forv(i,u) for (int j = 0 ; j < u.size() ; j++)
#define base 1000000007
#define oo 100000000

using namespace std ;

int n, f[100001][2][2][2] , def[100001] ;
vector <int> ke[100001] ;

int enter()
{
    cin >> n ;

    forinc(i,1,n)
    {
        int u , v ;

        cin >> u >> v ;

        ke[u].push_back(v) ;
        ke[v].push_back(u) ;
    }

    return 0 ;
}

int setnode(int u)
{
    forinc(i,0,1)
    forinc(j,0,1)
    forinc(k,0,1) f[u][i][j][k] = 1 ;

    return 0 ;
}

int dfs(int u , int p)
{
    int scon = 0 ;
    def[u] = oo ;

    setnode(u) ;

    forv(j,ke[u])
    {
        int v = ke[u][j] ;
        if (v !=p)
        {
            scon ++ ;
            def[u] = min(def[u],def[v]+1) ;
            dfs(v,u) ;
            forinc(col,0,1)
            {
                f[u][col][col][col] = (f[u][col][col][col] * (f[v][col][col][0] + f[v][col][col][1])) ;
                f[u][col][col][1-col] = (f[u][col][col][1-col] * f[v][col][1-col][1-col]) ;
                f[u][col][1-col][1-col] = (f[u][col][1-col][1-col] * f[v][1-col][1-col][1-col]) ;
            }
        }
    }

    if (scon == 0) def[u] = 0 ;
    if (def[u] == 2)
    {
        forinc(i,0,1)
        {
            f[u][i][i][i] = 1 ;
            f[u][i][1-i][1-i] = 1 ;
        }
    }
}

int print()
{
    long long res = 0 ;
    forinc(i,0,1) res+= f[1][i][i][i] + f[1][i][i][1-i] + f[1][i][1-i][1-i] ;

    cout << res ;

    cout << def[1] ;
}

int main()
{
    freopen("hkr.inp" , "r" , stdin) ;
    enter() ;
    dfs(1,-1) ;
    print() ;

    return 0 ;
}
