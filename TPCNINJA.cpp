#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++ )
#define fordec(i,a,b) for (int i  = a ; i >= b ; i-- )
#define oo 1000000000


using namespace std ;

int n,k,m ;
long long f[101][101][101],dp[1001][1001],g[1001][1001] ;

int sub1()
{

    int tres = n / k + 1 ;

    forinc(i,0,n)
    forinc(j,0,k)
    forinc(t,0,tres)
    f[i][j][t] = 0 ;

    f[1][1][1] = 1 ;

    forinc(i,1,n-1)
    forinc(j,1,k)
    forinc(t,1,tres)
    if (f[i][j][t] != oo)
    {

        if (j+1 <= k) f[i+1][j+1][t] = (f[i+1][j+1][t] + f[i][j][t]) % m ;
        if (t+1 <= tres) f[i+1][1][t+1] = (f[i+1][1][t+1] + f[i][j][t]) % m ;

    }

    int res = 0 ;

    forinc(i,1,k) res = (res + f[n][i][tres]) % m ;

    cout << tres << " " << res << endl ;

}

int sub2 ()
{

    int t = n / k + 1 ;

    forinc(i,0,t)
    forinc(sum,0,n) dp[t][sum] = 0 ;

    forinc(i,1,k) dp[1][i] = 1 ;

    forinc(i,1,n) g[1][i] = (g[1][i-1] + dp[1][i]) % m ;

    forinc(i,2,t)
    forinc(sum,1,n)
    {

        dp[i][sum] = (g[i-1][sum-1] - g[i-1][max(0,sum-k-1)]) % m  ;
        g[i][sum] = (g[i][sum-1] + dp[i][sum]) % m ;

    }

    cout << t << " " << dp[t][n] << endl ;

}

int process()
   {

    if (n <= 20) sub1() ;
    else if (n <= 1000) sub2() ;

}

int enter()
{

    int t  ;

    cin >> t ;

    forinc(i,1,t)
    {

        cin >> n >> k >> m ;

        if (n % k == 0)
        {

            cout << n / k << " " << 1 << endl ;
            return 0 ;

        }

        process();

    }

}

int main ()
{

    freopen("TPCNINJA.inp" , "r" , stdin) ;

    freopen("TPCNINJA.out" , "w" , stdout) ;

    enter() ;

}
