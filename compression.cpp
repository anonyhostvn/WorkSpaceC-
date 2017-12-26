#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)

using namespace std ;

string s ;

int n  = 0 , z[1000001];

int enter()
{

    cin >> s ;

    n = s.length();

}

int BuildZ()
{

    int L = 0 , R = 0 ;

    z[0] = n ;

    forinc(i,1,n-1)
    {

        if (i > R)
        {

            L = R = i ;

            while (R < n && s[R] == s[R-L]) R++ ;

            z[i] = R-L ; R-- ;

        }

        else
        {

            int k = i - L;

            if (z[k] < R-i+1) z[i] = z[k] ;
            else
            {

                L = i ;

                while (R < n && s[R] == s[R-L]) R++ ;

                z[i] = R - L ; R-- ;

            }

        }

    }

}

bool check(int l)
{

    forinc(i,0,n-1)
    if ((i % l == 0) && (z[i] < l)) return false ;

    return true ;

}

int process()
{

    BuildZ() ;

    int res = n ;

    forinc(i,1,n-1)
        if (z[i] == n - i)
        {

            res = i ;

            break ;

        }

    forinc(i,0,res-1) cout << s[i] ;

}

int main()
{

    //freopen("compression.inp" , "r" , stdin) ;

    enter() ;

    process() ;

}
