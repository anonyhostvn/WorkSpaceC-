#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)
#define base 1000000007

using namespace std ;

long long t , l , r , gt[5000001] , estha[5000001] , save[5000001] ;

int enter()
{

    cin >> t >> l >> r ;

}

int estharone (int n)
{

    forinc(i,2,(int) sqrt(n))
    if (estha[i] == 0)
    {

        int j = i * i ;

        while (j <= n)
        {

            estha[j] = i ;

            j = j + i ;

        }

    }

}

int prepare()
{

    gt[0] = 1 ;

    forinc(i,1,r-l) gt[i] = ((long long)gt[i-1] * t) % base ;

    estharone(r) ;

}

long long expression(int x)
{

    return (((long long) x * (x-1)) / 2) % base ;

}

long long solve(int x)
{

    int tmp = x , pew[30] , cnt = 0 ;

    while (estha[tmp] > 0)
    {

        cnt ++ ;
        pew[cnt] = estha[tmp] ;
        tmp = tmp / estha[tmp] ;

    }

    if (tmp > 1)
    {

        cnt ++ ;
        pew[cnt] = tmp ;

    }

    tmp = x ;

    long long res = 0  ;

    sort(pew+1,pew+cnt+1);

    forinc(i,1,cnt)
    {

        res = (res + (long long)expression(pew[i]) * (tmp / pew[i])) % base ;

        tmp = tmp / pew[i] ;

    }

    save[x] = res ;

    return res ;

}

int process()
{

    prepare() ;

    long long res = 0 ;

    forinc(i,l,r)
    if (save[i] == 0) res = (res + (gt[i-l] * solve(i)) % base) % base ;
    else res = (res + (gt[i-l] * save[i]) % base) % base ;

    cout << res ;

}

int main()
{

    //freopen("822D.inp" , "r" ,  stdin) ;

    enter() ;

    process() ;

}
