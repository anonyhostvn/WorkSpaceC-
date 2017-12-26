#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)
#define forv(i,u) for (int j = 0 ; j < ke[u].size() ; j++)

using namespace std ;

int n , m , q , a[100001] , b[100001] ;

int enter()
{
    cin >> n >> m >> q ;
    forinc(i,0,n-1) cin >> a[i] ;
    forinc(i,0,m-1) cin >> b[i] ;
    return 0 ;
}

int gcd(int a , int b)
{
    while (b != 0){
        int tmp = a % b ;
        a = b ;
        b = tmp ;
    }

    return a ;
}

int process()
{
    bool dd[100001] ;
    forinc(i,1,q){
        memset(dd , false , sizeof(dd)) ;
        int r1 , c1 , r2 , c2 , res = 0 ;
        cin >> r1 >> c1 >> r2 >> c2 ;
        forinc(i,r1,r2)
        forinc(j,c1,c2) dd[gcd(a[i],b[j])] = true ;
        forinc(i,1,100000) if (dd[i]) res ++ ;
        cout << res << endl ;
    }
    return 0 ;
}

int main()
{
    //freopen("gcdm.inp" , "r" , stdin) ;

    enter() ;
    process() ;
}
