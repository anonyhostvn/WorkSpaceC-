#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++ )
#define fordec(i,a,b) for (int i  = a ; i >= b ; i-- )

using namespace std ;

int n,c,p,t,a[101] ;

bool oksub2 = true ;

int enter ()
{

    cin >> n >> c >> p >> t ;

    forinc(i,1,n) {cin >> a[i] ; if (a[i] > 1) oksub2 = false ;}

}

int sub1 ()
{

    long long stime = 0  , res = 0 ;

    forinc(i,1,n)
    {

        if ((long long) i * p * 2  <= (double) (t - stime) / a[i])
        {

            stime += (long long ) i * p * 2 * a[i] ;

            res += a[i] ;

        }

        else
        {

            res += (t-stime) / (i*p*2) ;

            break ;

        }

    }

    cout << res ;

}

int sub2 ()
{

    long long recent = 0  , stime = 0 ,  res = 0 , last = 0;

    forinc(i,1,n)
    {

        if ((a[i] == 1))
        {

                if (recent + 1 <= c)
                {

                    if ((long long) 2 * i * p + stime <= t)
                    {

                        res ++ ;

                        a[i] = 0 ;

                        recent ++ ;

                        last = i ;

                    }
                    else break ;

                }

                else

                {

                    stime += (long long) 2 * p * (last) ;

                    recent = 0 ;

                    if (stime + 2 * p * i <= t) {res ++ ; recent = 1 ; last = i ; } else break ;

                }
        }
    }

    cout << res ;

}

int process()
{

    if (c == 1) sub1() ;
    else if (oksub2) sub2() ;

}

int main ()
{

    freopen("ELEVATOR.inp" , "r" , stdin) ;
    freopen("ELEVATOR.out" , "w" , stdout) ;

    enter ();
    process();

}
