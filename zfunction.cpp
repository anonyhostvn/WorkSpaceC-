#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i--)

using namespace std ;

string st ;

int z[1000001],n  ;

int enter()
{

    cin >> st ;

    n = st.length() ;

}

int BuildZ()
{

    int l = 0 , r = 0 ;
    z[0] = n ;

    forinc(i,1,n-1)
    {

        if (i > r)
        {

            l = r = i ;

            while ((r < n) && (st[r] == st[r-l])) r ++  ;

            z[i] = r - l ; r-- ;

        }

        else

        {

            int k = i - l ;

            if (z[k] < r-i+1) z[i] = z[k] ;
            else
            {

                l = i ;

                while ((r < n) && (st[r] == st[r-l])) r ++ ;

                z[i] = r -l ; r-- ;

            }

        }

    }

}

int process()
{

    BuildZ() ;

    forinc(i,0,n-1) cout << z[i] << " " ;

}

int main()
{

    //freopen("zfunction.inp" , "r" , stdin) ;

    enter() ;
    process() ;

}
