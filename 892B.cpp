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
#define ooll (long long) 1e15
#define ooit (int) 2e9
#define maxN 1000005

using namespace std ;

int n , a[maxN] , b[maxN] ;

int main() {
    ios_base::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    //freopen("892B.inp" , "r" , stdin) ;
    cin >> n ;
    forinc(i,1,n) cin >> a[i] ;
    forinc(i,1,n) b[max(1,i-a[i])] -- , b[i] ++ ;
    forinc(i,1,n) b[i] += b[i-1] ;
    int res = 0 ;
    forinc(i,1,n) if (b[i] >= 0) res ++ ;
    cout << res << endl ;
}
