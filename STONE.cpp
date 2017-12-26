#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)
#define K 100
#define N 100000

using namespace std ;

int n , k , s[K] , l[2][N+1] ;

int center ()
{

    cin >> n >> k ;
    forinc(i,1,k) cin >> s[i] ;

}

int play (int player ,int stone)
{

    if (l[player][stone] != -1) return l[player][stone] ;

    int r = 0 ;

    forinc(i,1,k)
    if (stone >= s[i])
    {

        int tmp = play(1-player,stone-s[i]) ;
        if (tmp == 0)
        {

            r = 1 ;
            break ;

        }

    }

    l[player][stone] = r ;

    return r ;

}


int sub2 ()
{

    if (n % (k+1) == 0) cout << "NO" << endl ; else cout << "YES" << endl ;

}

int process()
{

    forinc(i,0,1)
    forinc(j,0,n) l[i][j] = -1 ;

    int k = play(0,n) ;

    if (k == 0) cout << "NO" << endl ; else cout << "YES" << endl ;

}

int enter ()
{

    int t = 0 ;

    cin >> t ;

    forinc(i,1,t)
    {

        center() ;
        if (n <= 100000) process() ; else sub2() ;

    }

}

int main ()
{

    freopen("STONE.inp" , "r" , stdin) ;
    freopen("STONE.out" , "w" , stdout) ;

    enter () ;

}
