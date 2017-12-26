#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)
#define base 1000007

using namespace std ;

int n , k ;
long long g[100001][101][2] ;

int enter()
{
    cin >> n >> k ;
}

int solve(int n , int k)
{
    if (k > n) return 0 ;
    g[0][0][0] = 1 ;

    forinc(i,0,n-1)
    forinc(j,0,k)
    forinc(t,0,1)
    if (g[i][j][t] > 0) {
        g[i+1][0][t] = (g[i+1][0][t] + g[i][j][t]) % base ;
        if (j + 1 >= k) g[i+1][min(j+1,k)][1] = (g[i+1][min(j+1,k)][1] + g[i][j][t]) % base ;
        else g[i+1][min(k,j+1)][t] = (g[i+1][min(k,j+1)][t] + g[i][j][t]) % base ;
    }
    long long res = 0 ;
    forinc(i,0,k) res = (res + g[n][i][1]) % base ;
    return res ;
}

int process()
{
    cout << solve(n,k) ;
}

int main()
{
    //freopen("BITSTR.inp" , "r" , stdin) ;
    enter() ;
    process() ;
}
