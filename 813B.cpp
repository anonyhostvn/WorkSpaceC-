#include <bits/stdc++.h>
#define oo 10e18
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)

using namespace std ;

long long x,y,l,r,a[5000] ;

int enter ()
{

    cin >> x >> y >> l >> r ;

}

int max_pow(long long x)
{

    long long tmp = 1  ;

    forinc(i,1,64)
    {

        if (tmp > r / x) return i - 1 ;
        tmp = tmp * x ;

    }

    return 64 ;

}

long long power (long long x, int l)
{

    long long tmp = 1 ;
    forinc(i,1,l) tmp = tmp * x ;
    return tmp ;

}

int process()
{

    int mx = max_pow(x) , my = max_pow(y) , m = 0 ;
    long long res = 0 ;

    forinc(i,0,mx)
    forinc(j,0,my)
    {

        long long aa = power (x,i) , bb = power(y,j) ;

        if ((aa <= r - bb) && (aa >= l - bb))
        {

            m++ ;
            a[m] = aa + bb ;

        }

    }

    sort(a+1,a+m+1) ;

    a[0] = l-1 ; a[m+1] = r+1 ;

    forinc(i,1,m+1)
    if (res < a[i]-a[i-1]-1) res = a[i] - a[i-1] -1 ;

    cout << res ;

}

int main ()
{

    //freopen("813B.inp" , "r" , stdin);

    enter() ;
    process() ;

}
