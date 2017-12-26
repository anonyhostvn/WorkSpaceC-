#include <bits/stdc++.h>
#define oo 1000000000
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)

using namespace std ;

int n , t[2501] , w[2501] , b[2501] , f[2501][2501] ;

int enter ()
{

    cin >> n ;

    forinc(i,1,n) cin >> w[i] ;
    forinc(i,1,n) cin >> t[i] ;

    forinc(i,1,n) b[i] = w[i] + t[i] ;

}

int qs(int l , int r)
{

    if (l >= r) return 0 ;

    int i = l , j = r , key = b[l+rand()%(r-l+1)] ;

    while (i <= j)
    {

        while (b[i] < key) i++ ;
        while (b[j] > key) j-- ;
        if (i <= j)
        {

            swap(b[i],b[j]) ;
            swap(t[i],t[j]) ;
            swap(w[i],w[j]) ;
            i ++ ; j -- ;

        }

    }

    qs(l,j) ;
    qs(i,r) ;

}

int process()
{

    qs(1,n) ;

    forinc(i,0,n)
    forinc(j,0,n) f[i][j] = oo ;

    f[0][0] =  0 ;

    forinc(i,0,n-1)
    forinc(j,0,i)
    if (f[i][j] != oo)
    {

        f[i+1][j] = min(f[i+1][j],f[i][j]) ;
        if (t[i+1] >= f[i][j])
            f[i+1][j+1] = min(f[i+1][j+1],f[i][j] + w[i+1]) ;

    }

    fordec(i,n,0) if (f[n][i] != oo)
    {

        cout << i ;
        return 0 ;

    }

}

int main ()
{

    freopen("STACK.inp" , "r" , stdin) ;
    freopen("STACK.out" , "w" , stdout) ;

    enter() ;
    process() ;

}
