#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)
#define forv(i,u) for (int j = 0 ; j < ke[u].size() ; j++)
#define oo 100000000

using namespace std ;

int n , k , a[500001] , f[500001][3] , c[500001][2] ;
long long sum[500001] ;

int enter()
{
    cin >> n >> k ;
    forinc(i,1,n) {
        int x ;
        cin >> x ;
        a[i] = x % 2 ;
    }
}

int prepare()
{
    forinc(i,1,k){
        int j = i + k ;
        c[i][(a[i] + 1) % 2] = 1 ;
        while (j <= n){
            if (a[j] % 2 == 0) c[i][1] ++ ; else c[i][0] ++ ;
            j = j + k ;
        }
    }
}

int process()
{
    prepare() ;

    forinc(i,0,k)
    forinc(j,0,1) f[i][j] = oo ;
    f[0][0] = 0 ;

    forinc(i,0,k-1)
    forinc(j,0,1)
    if (f[i][j] <= oo){
        f[i+1][(j+a[i+1]) % 2] = min(f[i+1][(j+a[i+1]) % 2] , f[i][j] + c[i+1][a[i+1]%2]) ;
        f[i+1][(j + a[i+1]+1) % 2] = min(f[i+1][(j+a[i+1]+1) % 2] , f[i][j] + c[i+1][(a[i+1]+1) % 2]) ;
    }

    cout << f[k][0] ;
}

int main()
{
    freopen("meven.inp" , "r" , stdin) ;
    freopen("meven.out" , "w" , stdout) ;

    enter() ;
    process() ;
}
