#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i--)
#define base 1000001

using namespace std ;

int n , m , k ;
long long f[101] , c[52][52] ;

int prepare()
{

    f[0] = 1 ;

    forinc(i,1,100) f[i] = ((long long) f[i-1] * i) % base ;

    forinc(i,1,50) {c[0][i] = 1 ; c[i][i] = 1; }

    c[1][1] = 1 ;

    forinc(i,2,50)
    forinc(j,1,i) c[j][i] = (c[j-1][i-1] + c[j][i-1]) % base ;

}

int enter()
{

    int t = 0 ;

    cin >> t ;

    prepare() ;

    forinc(test,1,t)
    {

        cin >> m >> n >> k ;

        if ((n < k) || (m < k)) cout << 0 << endl ;
        else cout << ((long long) ((long long)(c[k][n] * c[k][m]) % base) * f[k]) % base << endl ;

    }

}

int main()
{

    freopen("rook1.inp" , "r" , stdin) ;
    freopen("rook1.out" , "w" , stdout) ;

    enter() ;

}
