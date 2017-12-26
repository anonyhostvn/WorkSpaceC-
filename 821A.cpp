#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)

using namespace std ;

int n = 0 , a[51][51] ;

int main()
{

    //freopen("821A.inp" , "r" , stdin) ;

    cin >> n ;

    forinc(i,1,n)
    forinc(j,1,n) cin >> a[i][j] ;

    bool ok = true ;

    forinc(i,1,n)
    forinc(j,1,n)
    if (a[i][j] > 1)
    {

        bool beauty = false ;

        forinc(t,1,n)
        forinc(s,1,n) if (a[i][j] == a[i][t] + a[s][j])
        {

            beauty = true ;

            break ;

        }

        if (!beauty)
        {

            ok = false ;

            break ;

        }

    }

    if (!ok) cout << "No" ; else cout << "Yes" ;

}
