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
#define maxN 10001
#define oo (int) 1e9

using namespace std ;

int n , a[maxN] ;


int main()
{
    //freopen("nmax.inp", "r" , stdin) ;
    cin >> n ;
    forinc(i,1,n) cin >> a[i] ;
    sort(a+1,a+1+n) ;
    int tmp = a[1] * a[2] * a[n] ;
    int tmp1 = max(max(a[1] * a[2],a[n]*a[n-1]),max(a[1] * a[2] * a[3] , a[n] * a[n-1] * a[n-2])) ;
    cout << max(tmp1,tmp) ;
    return 0 ;
}
