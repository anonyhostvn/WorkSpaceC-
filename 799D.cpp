#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)
#define oo 1000000

using namespace std ;

int a , b , h , w , n , ex[100002] , d[100002]  ;

int enter()
{

    cin >> a >> b >> h >> w >> n;

    forinc(i,1,n) cin >> ex[i] ;

}

bool cmp(int a , int b)
{

    return a > b ;

}

int solve(int a, int b , int h , int w)
{

    d[h] = w ;

    forinc(i,1,min(34,n)+1)
    {

        fordec(j,100000,0)
        if (d[j] > 0)
        {

            if ((j >= a && d[j] >= b) || (j >= b && d[j] >= a))
                return i - 1 ;

            if ((long long) j * ex[i] <= 100000) d[j*ex[i]] = max(d[j*ex[i]],d[j]) ;
            else d[100000] = max(d[100000],d[j]) ;
            if ((long long) d[j] * ex[i] <= 100000) d[j] = d[j] * ex[i] ;
            else d[j] = 100000 ;

        }

    }

    return oo ;

}

int process()
{

    if (a <= h && b <= w)
    {

        cout << 0 ;

        return 0 ;

    }

    sort(ex+1,ex+1+n,cmp) ;
    int res = solve(a,b,h,w) ;

    if (res == oo) cout << -1 ; else cout << res ;

}

int main()
{

    //freopen("799D.inp" , "r" , stdin) ;

    enter() ;
    process() ;

}
