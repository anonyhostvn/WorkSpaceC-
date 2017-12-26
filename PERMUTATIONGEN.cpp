#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a;  i >= b ; i--)

using namespace std ;

int n , a[10001] ;

int main ()
{

    freopen("PERMUTATIONGEN.inp" , "r" , stdin) ;
    freopen("PERMUTATIONGEN.out" , "w" , stdout) ;

    int pos = n ;

    cin >> n ;

    forinc(i,1,n) cin >> a[i] ;

    fordec(i,n-1,1)
    {

        if (a[i] < a[i+1]) break ;

        pos = i ;

    }  //1 5 4 3 2

    if (pos == 1) {cout << -1 ; return 0 ;}

    int smin = 500000 , spos ;

    forinc(i,pos,n) if (smin > a[i])
    {

        smin = a[i] ;
        spos = i ;

    }

    swap(a[spos],a[pos-1]) ;

    sort(a+pos,a+1+n) ;

    forinc(i,1,n) cout << a[i] << " " ;

}
