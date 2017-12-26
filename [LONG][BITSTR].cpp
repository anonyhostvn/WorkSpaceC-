#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)
#define forv(j,u) for (int j = 0 ; j < u.size() ; j++)
#define base 1000000007

using namespace std ;

int n , k , f[100001][101][2] ;

int enter()
{
    cin >> n >> k ;
    f[0][0][0] = 1 ;
    forinc(i,0,n-1)
    forinc(j,0,k)
    forinc(t,0,1)
    if (f[i][j][t] > 0){
        f[i+1][min(j+1,k)][t || (j+1 == k)] = (f[i+1][min(j+1,k)][t || (j+1 == k)] + f[i][j][t]) % base ;
        f[i+1][0][t] = (f[i+1][0][t] + f[i][j][t]) % base ;
    }

    long long res = 0 ;
    forinc(i,0,k) res = (res + f[n][i][1]) % base ;
    cout << res ;
}

int main()
{
    freopen("BITSTR.inp" , "r" , stdin) ;
    freopen("BITSTR.out" , "w" , stdout) ;

    enter() ;
}
