#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)

using namespace std ;

int n,m,a[10001] ;

int main ()
{

    freopen("COMBINATIONGEN.inp" , "r" , stdin) ;
    freopen("COMBINATIONGEN.out" , "w" , stdout) ;

    int pos = 0 ;

    cin >> n >> m ;

    forinc(i,1,m) cin >> a[i] ;

    forinc(i,1,m) if (a[i] < n) pos = i ;

    if (pos == 0) cout << -1 ;
    else
    {

        forinc(i,1,m) if (pos != i) cout << a[i] << " " ;
        else cout << a[i] + 1 << " " ;

    }

}
