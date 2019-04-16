#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++ )
#define fordec(i,a,b) for (int i = a ; i >= b ; i -- )

using namespace std ;

int n, t[100001] , d[100001] ;
double b[100001] ;

int enter ()
{

    cin >> n ;
    forinc(i,1,n) cin >> t[i] >> d[i] ;

    forinc(i,1,n) b[i] = (double) t[i] / d[i] ;

}

int qs(int l , int r)
{

    if (l >= r) return 0 ;

    int i = l , j = r ; double key = b[l+rand()%(r-l+1)] ;

    while (i <= j)
    {

        while (b[i] < key) i++ ;
        while (b[j] > key) j-- ;

        if (i <= j)
        {

            swap(b[i],b[j]) ;
            swap(t[i],t[j]) ;
            swap(d[i],d[j]) ;
            i++ ; j -- ;

        }

    }

    qs(l,j) ;
    qs(i,r) ;

}

int process()
{

    qs(1,n) ;

    long long tm = 2 * t[1] , res = 0  ;

    forinc(i,2,n)
    {

        res += (long long) d[i] * tm ;

        tm += 2 * t[i] ;

    }

    cout << res ;

}

int main ()
{

    freopen("flowers.inp" , "r" , stdin) ;
    freopen("flowers.out" , "w" , stdout) ;

    enter () ;
    process() ;

}
