#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)
#define forv(i,u) for (int j = 0 ; j < ke[u].size() ; j++)

using namespace std ;

int n , k ;
long long f[30][30] ;


int enter()
{
    cin >> n >> k ;

    f[0][0] = 1 ;
    forinc(i,0,n-1)
    forinc(j,0,k)
    if (f[i][j] > 0){
        f[i+1][j] += f[i][j] * j ;
        if (j+1 <= k) f[i+1][j+1] += f[i][j] ;
    }

    cout << f[n][k] << endl ;

    memset(f,0,sizeof(f)) ;
}

int main()
{
    //freopen("bcdiv.inp" , "r" , stdin) ;

    int t = 0 ;
    cin >> t ;

    forinc(i,1,t) enter() ;
}
