#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)

using namespace std ;

int t ;

int solve(int u  , int v)
{

    if (v-u+1 >= 32) return ((v-u+1) / 16) * 16 ;

    forinc(i,u,v-1) if ((i % 16 ==0 )  || (i % 16 == 8)) return 2 ;

    return -1 ;

}

int main ()
{

    freopen("FIBVAL.inp" , "r" , stdin) ;
    freopen("FIBVAL.out" , "w" , stdout) ;

    cin >> t ;

    forinc(i,1,t)
    {

        int u , v ;

        cin >> u >> v ;

        cout << solve(u,v) << endl ;

    }

}
