#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)

using namespace std ;

int n , k , a[10001] ;
long long f[10001] ;
bool dd[10001] ;

int enter()
{

    cin >> n >> k ;

}

int prepare()
{

    f[0] = 1 ;

    forinc(i,1,n)
    if (f[i-1] <= k / i) f[i] = f[i-1] * i ;
    else break ;

}

int process()
{

    prepare() ;

    long long cnt = 0 ;

    forinc(i,1,n)
    forinc(j,1,n)
    if (!dd[j])
    {

        if (cnt + f[n-i] >= k)
        {

            cout << j << " " ;

            dd[j] = true ;

        }

        cnt += f[n-i] ;

    }

}

int main ()
{

    freopen("PERMUTATIONLIST.inp" , "r" , stdin) ;
    freopen("PERMUTATIONLIST.out" , "w" , stdout) ;

    enter() ;

    process() ;

}
