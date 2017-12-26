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

int a [101] ;

int main()
{
    //freopen("839A.inp" , "r" , stdin) ;
    int n , k ; cin >> n  >> k ;
    forinc(i,1,n) cin >> a[i] ;
    int extra = 0  , sum = 0 , cnt = 0 ;
    forinc(i,1,n){
        int pick = min(8,extra + a[i]) ;
        sum += pick ;
        extra = extra + a[i] - pick ;
        ++cnt ;
        if (sum >= k) break ;
    }
    if (sum >= k) cout << cnt ; else cout << -1 ;
    return 0 ;
}
