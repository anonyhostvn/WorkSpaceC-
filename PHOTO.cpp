#include<bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i--)
#define base 1000000007

using namespace std ;

int n0 , n1 , n2 , nmax ;
long long f[1000001] , g[1000001];

int enter()
{

    cin >> n0 >> n1 >> n2 ;

    nmax = max(n0,max(n1,n2)) ;

}

int prepare()
{

    f[0] = 1 ;

    forinc(i,1,nmax) f[i] = (f[i-1] * i) % base ;

    g[0] = 1 ;

    forinc(i,1,nmax)
        g[i] = (g[i-1] * 2) % base ;

}

long long pow(long long b , int n)
{

    if (n == 1) return b % base ;

    if (n == 0) return 1 ;

    long long tmp = pow(b,n/2) ;

    if (n % 2 == 0) return (tmp * tmp) % base ;
    return (((tmp * tmp) % base ) * b ) % base ;

}

int solve()
{

    if (n0 + 1 != n2) return 0 ;

    long long a = f[n0] , b = (f[n0-n1] * f[n1]) % base ;

    b = pow(b,base-2) ;

    return (((a * b) % base) * g[n1]) % base ;

}

int process ()
{

    prepare() ;

    cout << solve () ;

}

int main()
{

    freopen("PHOTO.inp" , "r" , stdin) ;
    freopen("PHOTO.out" , "w" , stdout) ;

    enter() ;

    process() ;

}
