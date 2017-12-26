#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)

using namespace std ;

int n  , a[10001];
string st ;

int enter()
{

    cin >> n ;

    cin >> st ;

    forinc(i,0,n-1) a[i] = (int) st[i] - (int) '0' ;

}

int process()
{

    int pos = 0 ;

    forinc(i,0,n-1) if (a[i] == 0) pos = i ;

    if (pos == 0) cout << -1 ;
    else
    {

        forinc(i,0,n-1) if (i < pos ) cout << a[i] ;
        else if (i == pos) cout << 1 ; else cout << 0 ;

    }

}

int main ()
{

    freopen("BINARYGEN.inp" , "r" , stdin) ;
    freopen("BINARYGEN.out" , "w" , stdout) ;

    enter() ;
    process();

}
