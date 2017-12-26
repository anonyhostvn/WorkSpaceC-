#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++ )
#define fordec(i,a,b) for (int i  = a ; i >= b ; i-- )
#define base 20152015

using namespace std ;

int n , a[501] , tt[501][34] ;
long long f[501][34] ;

int onbit(int x, int i)
{

    return (1 << i) ^ x ;

}

int getbit(int x , int i)
{

    return (x >> i) & 1 ;

}

int enter()
{

    cin >> n ;

    forinc(i,1,n)
    {


        string st ;

        cin >> st ;

        forinc(j,0,4)
        if ((int)st[j] == 46) a[i] = onbit(a[i],j) ;

    }

}

bool check(int i1 , int i2 , int st1 , int st2)
{

    forinc(i,0,3)
    if ((getbit(a[i1],i) == 1) && (getbit(a[i2],i) == 1) && (getbit(a[i1],i+1) == 1) && (getbit(a[i2],i+1) == 1))
    {

        if ((getbit(st1,i) == getbit(st1,i+1)) && (getbit(st1,i+1) == getbit(st2,i+1)) && (getbit(st2,i+1) == getbit(st2,i))) return false ;

    }

    return true ;

}

int prepare()
{

    forinc(i,1,n)
    {

        int cnt = 0 ;

        forinc(stt,0,31)
        {

            bool ok = true ;

            forinc(j,1,cnt) if ((stt & a[i]) == (tt[i][j] & a[i])) {ok = false ; break ; }

            if (ok)
            {

                cnt ++ ;

                tt[i][cnt] = stt ;

            }

        }

        tt[i][0] = cnt ;

    }

}

int process()
{

    prepare() ;

    forinc(i,0,n)
    forinc(j,0,31) f[i][j] = 0 ;

    forinc(i,1,tt[1][0]) f[1][tt[1][i]] = 1 ;

    forinc(i,1,n-1)
    forinc(j,1,tt[i][0]) if(f[i][tt[i][j]] > 0)
    {

        forinc(k,1,tt[i+1][0])
        if (check(i,i+1,tt[i][j],tt[i+1][k]))
        {

            f[i+1][tt[i+1][k]] = (f[i+1][tt[i+1][k]] + f[i][tt[i][j]]) % base;

        }

    }

    long long res = 0 ;

    forinc(i,0,32) res = (res + f[n][i]) % base ;

    cout << res ;

}

int main ()
{

    //freopen("alley.inp" , "r" , stdin) ;

    enter() ;
    process() ;

}
