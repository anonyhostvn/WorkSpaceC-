#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)
#define N 500
#define M 500

using namespace std ;

int m , n , f[M+1][N+1] , a[M+1][N+1] , dd[2][N+1][M+1][2][2] ;

int build_arr()
{

    forinc(i,1,m)
    forinc(j,1,n) f[i][j] = (f[i-1][j] + f[i][j-1] - f[i-1][j-1] + a[i][j]) % 2 ;

}

int sum(int x , int y , int u , int v)
{

    return (f[u][v] - f[x-1][v] - f[u][y-1] + f[x-1][y-1]) % 2 ;

}

int center ()
{

    cin >> m >> n;

    forinc(i,1,m)
    forinc(j,1,n) cin >> a[i][j] ;

}



int playex(int player , int r , int c , int roc , int t)
{

    if (dd[player][r][c][roc][t] != -1) return dd[player][r][c][roc][t] ;

    int res = 0 ;

    if (roc == 0)
    {

        int tmp = (t + sum(r,1,r,c)) % 2 ;

        if (tmp == 0)
        {

            int th1 = playex(1-player,r-1,c,0,0) ,
                th2 = playex(1-player,r-1,c,1,0) ;

            if ((th1 == 0) && (th2 == 0))
            {

                dd[player][r][c][roc][t] = 1 ;
                return 1 ;

            }

        }

        int th = playex(player,r-1,c,roc,tmp) ;

        if (th == 1)
        {

            dd[player][r][c][roc][t] = 1 ;
            return 1 ;

        }

    }

    if (roc == 1)
    {

        int tmp = (t + sum(1,c,r,c)) % 2 ;

        if (tmp == 0)
        {

            int th1 = playex(1-player,r,c-1,0,0) ;
            int th2 = playex(1-player,r,c-1,1,0) ;

            if ((th1 == 0) && (th2 == 0))
             {

                dd[player][r][c][roc][t] = 1 ;
                return 1 ;

            }

        }

        int th = playex(player,r,c-1,roc,tmp) ;

        if (th == 1)
         {

                dd[player][r][c][roc][t] = 1 ;
                return 1 ;

        }
    }


    dd[player][r][c][roc][t] = res ;

    return res ;

}

int process()
{

    forinc(i,0,1)
    forinc(j,1,m)
    forinc(k,1,n)
    forinc(o,0,1)
    forinc(p,0,1) dd[i][j][k][o][p] = -1 ;

    build_arr() ;

    int tmp = playex(0,m,n,0,0)
        , tmp1 = playex(0,m,n,1,0);

    if ((tmp == 0) && (tmp1 == 0)) cout << "FALSE" << endl ; else cout << "TRUE" << endl ;

}

int enter ()
{

    int t ;

    cin >> t ;

    forinc(i,1,t)
    {

        center () ;
        process() ;

    }

}

int main ()
{

    freopen("PARIGAME.inp" , "r" , stdin);
    freopen("PARIGAME.out" , "w" , stdout) ;

    enter () ;

}
