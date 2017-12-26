#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++ )
#define fordec(i,a,b) for (int i  = a ; i >= b ; i-- )

using namespace std ;

int n,m,l[1001],r[1001] ;

int main ()
{

    //freopen("813A.inp" , "r" , stdin) ;

    cin >> n ;

    int res = 0 ;
    bool ok = false ;

    forinc(i,1,n)
    {

        int x = 0;
        cin >> x ;
        res += x ;

    }

    cin >> m ;

    forinc(i,1,m)
    {

        cin >> l[i] >> r[i] ;
        if ((l[i] <= res) && (res <= r[i])) ok = true ;

    }

    if (!ok)
        forinc(i,1,m) if (l[i] >= res)
        {

            ok = true ;
            res = l[i] ;
            break ;

        }

    if (ok) cout << res ; else cout << -1 ;

}
