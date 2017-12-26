#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)
#define forv(j,u) for (int j = 0 ; j < u.size() ; j++)

using namespace std ;

int n , a[100001] , b[100001] , cnt[100001] , sc[100001] , sl[100001] ;

int enter()
{
    cin >>  n ;
    forinc(i,1,n) cin >> a[i] ;
}

int getbit(int x , int i)
{
    return (x >> (i-1)) & 1 ;
}

int process()
{
    long long tres = 0 ;
    forinc(k,1,31){
        forinc(i,1,n) b[i] = getbit(a[i],k) ;
        //forinc(i,1,n) if (b[i] == 1) cnt[i] = cnt[i-1] + 1 ; else cnt[i] = cnt[i-1] ;
        forinc(i,1,n) cnt[i] = cnt[i-1] + b[i] ;
        sc[0] = 1 ;
        forinc(i,1,n) {
            sc[i] = sc[i-1] + (int) (cnt[i] % 2 == 0) ;
            sl[i] = sl[i-1] + (int) (cnt[i] % 2 != 0) ;
        }
        long long  res = 0 ;

        forinc(i,1,n) if (cnt[i] % 2 == 0) res += sl[i-1] ; else res += sc[i-1] ;
        tres += (long long) pow(2,k-1) * res ;
    }
    cout << tres ;
}

int main()
{
    freopen("ppxor.inp" , "r" , stdin) ;
    freopen("ppxor.out" , "w" , stdout) ;
    enter() ;
    process() ;
}
