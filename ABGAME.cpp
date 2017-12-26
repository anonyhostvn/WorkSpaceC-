#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i--)

using namespace std ;

int a , b , dd[2][1001][1001] ;

int find_max(int x , int y)
{

    int l = 0 , r = y / x , res = 0 ;

    while (l <= r)
    {

        int mid = (l+r) / 2 ;

        if (x > y - mid * x) l = mid + 1 ;
        else
        {

            r = mid - 1 ;
            res = mid ;

        }

    }

    return res ;

}

int play(int player , int sa , int sb)
{

    if (dd[player][sa][sb] != -1) return dd[player][sa][sb] ;

    int k = find_max(sa,sb) , res = 0 ;

    int th1 = 1 ;

    if (k > 0) th1 = play(1-player,sa,sb-k*sa) ;
    int th2 = play(1-player,sb-(k+1)*sa,sa) ;

    if ((th1 == 0)  || (th2 == 0)) res = 1 ;

    dd[player][sa][sb] = res ;

    return res ;

}

int process()
{

    forinc(i,0,1)
    forinc(j,1,a)
    forinc(k,1,b) dd[i][j][k] = -1 ;

    int k = play(0,min(a,b),max(a,b)) ;

    if (k == 0) cout << "NO" << endl ; else cout << "YES" << endl ;

}

int enter ()
{

    while (cin >> a >> b)
    {

        process() ;

    }

}

int main ()
{

    freopen("ABGAME.inp" , "r" , stdin) ;
    freopen("ABGAME.out" , "w" , stdout) ;

    enter() ;

}
