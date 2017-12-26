#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++ )
#define fordec(i,a,b) for (int i  = a ; i >= b ; i-- )
#define base 1000000007

using namespace std ;

int a[1000001] , dd[1000001] , x[1000001] , ok ;

long long n,m;

long long pow2[1000001];

int update(int i , int k)
{

    while (i > 0)
    {

        x[i] += k ;

        i = i - (i & (-i)) ;

    }

}

int get(int i )
{

    int res = 0 ;

    while (i <= n)
    {

        res += x[i] ;

        i = i + (i & (-i));

    }

    return res ;

}

int print ()
{

    long long res =0 ;

    forinc(i,1,n) res = (res + (long long) a[i] * pow2[i-1]) % base ;

    cout << res  << endl ;

}

int check()
{

    int res = 0 ;

    forinc(i,1,n) x[i] = 0 ;

    forinc(i,1,n)
    {

        int tmp = get(a[i]+1) ;

        res += tmp ;

        update(a[i],1) ;

    }

    if (res == m)
    {

        print() ;

        ok = true ;

        return  0 ;

    }

}

int bt(int i)
{

    if (ok) return 0 ;

    if (i == n+1)
    {

        check() ;

        return 0 ;

    }

    forinc(j,1,n)
    if (dd[j] == 0)
    {

        a[i] = j ;

        dd[j] = 1 ;

        bt(i+1) ;

        dd[j] = 0 ;

    }

}

int sub1()
{

    forinc(i,1,n) dd[i] = 0 ;

    bt(1) ;

    if (!ok) cout << -1 << endl ;

}

int upd(int i , int k)
{

    while (i <= n)
    {


        x[i] += k ;

        i = i + (i & (-i)) ;

    }

}

int getpd(int i)
{

    int res = 0 ;

    while (i > 0)
    {

        res += x[i] ;

        i = i - (i & (-i)) ;

    }

    return res ;

}

int sub2()
{

    //memset(x,0,sizeof(x)) ;
    forinc(i,1,n) x[i] = 0 ;

    //memset(dd,0,sizeof(dd)) ;
    forinc(i,1,n) dd[i] = 0 ;

    long long recent = 0 ;

    forinc(i,1,n) upd(i,1) ;

    forinc(i,1,n)
    {

        forinc(j,1,n)
        if (dd[j] == 0)
        {

            //update(j,-1) ;

            long long tmp = getpd(j-1) ;

            if ((long long)recent + tmp + ((long long) (n-i) * (n-i-1)) / 2 >= m)
            {

                upd(j,-1) ;

                a[i] =j ;

                recent += tmp ;

                dd[j] = 1 ;

                break ;

            }

        }

    }

    if (recent == m) print () ;
    else cout << -1 << endl ;

}

int prepare()
{

    pow2[0] = 1 ;

    forinc(i,1,1000000) pow2[i] = (pow2[i-1] * 2 ) % base ;

}
int enter()
{

    int t ;

    prepare() ;

    cin >>  t ;

    forinc(i,1,t)
    {

        ok = false ;

        cin >> n >> m ;

        if (n <= 10) sub1() ; else
        if (n <= 1000) sub2() ;
        else cout << -1 << endl ;

    }

}

int main ()
{

    freopen("INVERSION.inp" , "r" , stdin) ;
    freopen("INVERSION.out" , "w" , stdout) ;

    enter() ;

}
