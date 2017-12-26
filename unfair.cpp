#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)
#define forv(j,u) for (int j = 0 ; j < u.size() ; j++)
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define mk make_pair
#define pii pair<int,int>

using namespace std ;

int n , a[100001] , b[100001] ;

int enter()
{
    cin >> n ;
    forinc(i,1,n) cin >> a[i] ;
    forinc(i,1,n) cin >> b[i] ;
    sort(a+1,a+1+n) ;
    sort(b+1,b+1+n) ;
    return 0 ;
}

int process()
{
    int j = 1 , res = 0 ;
    forinc(i,1,n) if (b[i] > a[j]) {
        res ++ ; j ++ ;
    }
    cout << res ;
    return 0 ;
}

int main()
{
    freopen("unfair.inp" , "r" , stdin) ;
    freopen("unfair.out" , "w" , stdout) ;
    enter() ;
    process() ;
    return 0 ;
}
