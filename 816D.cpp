#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fotdec(i,a,b) for (int i = a ; i >= b ; i --)
#define base 1000000007

using namespace std ;

int n , a[200001]  , g[200001];

int enter()
{

    cin >> n ;

    forinc(i,1,n) cin >> a[i] ;

}

int prepare()
{

    g[0] = 1 ;

    forinc(i,1,n) g[i] = ((long long)g[i-1] * i) % base ;

}

long long cpow (int x , int n)
{

    if (n == 0) return 1 ;

    if (n == 1) return x ;

    long long tmp = cpow (x,n/2) ;

    if (n % 2 == 0) return ((long long) tmp * tmp ) % base ;

    return ((((long long) tmp * tmp) % base) * x) % base ;

}

long long C(int k, int n)
{

    long long a = g[n] , b = ((long long) g[k] * g[n-k]) % base ;

    return (long long) a * cpow(b,base-2) % base  ;

}

int case1()
{

    int oper = 1 , factor = -1 ;
    long long res = 0 ;

    forinc(i,1,n)
    {

        if (oper == 1) factor ++ ;

        res = (res + ((long long) oper * C(factor,(n-2)/2) * a[i]) % base + base) % base ;

        oper = 0 - oper ;

    }

    return res % base ;

}

long long  case2 ()
{

    int factor = 0 ;

    long long res = 0 ;

    forinc(i,1,n)
    {

        if (i % 2 == 1)
        {

            res = (res + ((long long)C(factor,(n-1)/2) * a[i]) % base + base) % base ;

            factor ++ ;

        }

    }

    return res % base ;

}

long long case3()
{

    int factor = -1 ;

    long long res = 0 ;

    forinc(i,1,n)
    {

        if (i % 2 == 1) factor ++ ;

        res = (res + (long long)(C(factor,(n-2)/2) * a[i]) % base + base) % base ;

    }

    return res % base;

}

long long case4()
{

    int factor = -1 ;

    long long res = (((long long) C(0,(n-3)/2) * a[1]) % base + base) % base ;

    forinc(i,2,n)
    {

        if (i % 2 == 0) factor ++ ;

        if (i % 2 == 0) res = (res + ((long long) 2 * C(factor,(n-3)/2) * a[i]) % base + base) % base ;
        else res = (res + (long long) (((C(factor+1,(n-3)/2) - C(factor,(n-3)/2))) * a[i]) % base + base) % base ;

    }

    return res % base ;

}

int process()
{

    prepare() ;

    if (n % 4 == 0) cout << case1() ;
    else if (n % 4 == 1) cout << case2() ;
    else if (n % 4 == 2) cout << case3() ;
    else cout << case4() ;

}

int main()
{

    //freopen("816D.inp" , "r" , stdin) ;

    enter() ;

    process()  ;

}
