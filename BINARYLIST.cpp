#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i--)

using namespace std ;

int n , k , ii , a[10001] , cnt = 0 ;
bool ok = false ;

int enter()
{

    cin >> n >> k >> ii ;

}

int print()
{

    forinc(i,1,n) cout << a[i] << " ";

    ok = true ;

}

int bt (int i , int last)
{

    if (ok) return 0 ;

    if (i == n+1)
    {

        cnt ++ ;

        if (cnt == k) print() ;

        return 0 ;

    }

    if (last+1 < ii)
    {

        a[i] = 0 ;

        bt(i+1,last+1) ;

    }

    a[i] = 1 ;

    bt(i+1,0);

}

int main()
{

    freopen("BINARYLIST.inp" , "r" , stdin) ;
    //freopen("BINARYLIST.out", "w" , stdout) ;

    enter();
    bt(1,0) ;

    if (!ok) cout << -1 ;

}
