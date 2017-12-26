#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)
#define forv(i,u) for (int j = 0 ; j < ke[u].size() ; j++)
#define base 1000000007

using namespace std ;

int n , a[100001] , b[100001] , c[100001] , m ;
long long f[1001][9001] ;
bool prime[9001] ;

int enter()
{
    cin >> n ;
    forinc(i,1,n) cin >> a[i] ;

    return 0 ;
}

int makeprime()
{
    forinc(i,2,(int)sqrt(9001))
    if (!prime[i])
    {
        int j = i * i ;
        while (j <= 9001)
        {
            prime[j] = true ;
            j += i ;
        }
    }

    return 0 ;
}

int prepare()
{
    int cnt = 1 ;
    sort(a+1,a+1+n) ;
    b[1] = a[1] ; c[1] = 1 ;

    forinc(i,2,n)
    {
        if (a[i] == a[i-1]) c[cnt] ++ ;
        else
        {
            cnt ++ ;
            b[cnt] = a[i] ;
            c[cnt] = 1 ;
        }
    }
    m = cnt ;

    return 0 ;
}

int process()
{
    prepare() ;

    memset(f,0,sizeof(f)) ;

    f[0][0] = 1 ;

    forinc(i,0,m-1)
    forinc(sum,0,8193)
    if (f[i][sum] != 0)
    {
        f[i+1][sum] = (f[i+1][sum] + ((long long)f[i][sum] * (c[i+1] / 2 + 1)) % base) % base ;
        f[i+1][sum^b[i+1]] = (f[i+1][sum^b[i+1]] + ((long long)f[i][sum] * ((c[i+1]+1) / 2)) % base) % base ;
    }

    long long res = 0 ;

    forinc(sum,2,9000)
    if (!prime[sum]) res = (res + f[m][sum]) % base ;

    cout << res << endl ;

    return 0 ;
}

int main()
{
    //freopen("primexor.inp" , "r" , stdin) ;

    int q = 0 ;
    cin >> q ;

    makeprime() ;
    forinc(i,1,q)
    {
        enter() ;
        process() ;
    }

    return 0 ;
}
