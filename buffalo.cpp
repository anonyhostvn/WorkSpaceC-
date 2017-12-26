#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i--)
#define base 1000000007

using namespace std ;

long long c[1001][1001] ;

int n , k ;

int prepare()
{

    forinc(i,1,1000)
    {

        c[i][i] = 1 ;
        c[0][i] = 1 ;

    }

    c[1][1] = 1 ;

    forinc(i,2,1000)
    forinc(j,1,i)
    c[j][i] = (c[j-1][i-1] + c[j][i-1]) % base ;

}

int f(int x, int y , int sw)
{

    return ((long long)(c[min(x,sw)][x] * c[min(sw,y)][y]) % base ) ;

}

int main()
{

    freopen("buffalo.inp" , "r" , stdin) ;
    //freopen("buffalo.out" , "w" , stdout) ;

    prepare() ;

    while (cin >> n >> k)
    {

        long long res = 0 ;

        forinc(i,0,n)
        forinc(sw,0,k)
        res = (res + f(i,n-i,sw)) % base ;

        cout << res  << endl ;
    }

}
