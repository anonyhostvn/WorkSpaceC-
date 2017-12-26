#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i--)

using namespace std ;

string st1 , st2  ;
long long f[100005][2][2][10][10] , n ;

int enter()
{
    cin >> st1 ;
    cin >> st2 ;
    n = st2.length() ;
}

int fixString()
{
    int k = st2.length() - st1.length() ;
    forinc(i,1,k) st1 = '0' + st1 ;
}

long long cal(int i , int bigger , int smaller , int last , int d)
{
    if (f[i][bigger][smaller][last][d] != -1) return f[i][bigger][smaller][last][d] ;
    if (i == n+1) {
        f[i][bigger][smaller][last][d] = 1 ;
        return 1 ;
    }
    int recent = (last + d) % 10  ;
    int tbigger = 0 , tsmaller = 0 , tup = (int) st1[i] - (int) '0' , tdown = (int)st2[i] - (int)'0' ;
    if ((bigger == 0 && tup > recent) || (smaller == 0 && tdown < recent)) {
        f[i][bigger][smaller][last][d] = 0 ;
        return 0 ;
    }
    tbigger = bigger | (tup < recent) ;
    tsmaller = smaller | (tdown > recent) ;
    f[i][bigger][smaller][last][d] = cal(i+1,tbigger,tsmaller,recent,d) ;
    return f[i][bigger][smaller][last][d] ;
}

int process()
{
    int res = 0 ;
    return 0 ;
}

int center()
{
    int t = 0 ;
    cin >> t ;
    forinc(i,1,t)
    {
        enter() ;
        process() ;
    }
    return  0 ;
}

int main()
{


    freopen("ARITHDIG.inp" , "r" , stdin) ;
    freopen("ARITHDIG.out" , "w" , stdout) ;

    center() ;
    return 0 ;
}
