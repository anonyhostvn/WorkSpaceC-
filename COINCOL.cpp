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
#define oo (long long) 1e18 + 1
#define maxN 100005

using namespace std ;

int n  ;
long long a[maxN] , k ;

void enter()
{
    scanf("%d%d" , &n , &k) ;
    forinc(i,1,n) scanf("%lld" , &a[i]) ;
    sort(a+1,a+1+n) ;
}

void process()
{
    stack<int> s ;
    int res = 0 ;
    long long sum = 0 , res_sum = 0 ; a[n+1] = oo ;
    forinc(i,1,n) if (sum + a[i] < a[i+1] && sum + a[i] <= k) sum += a[i] , res ++ ;
    cout << res << " " << sum << endl ;
}

int main()
{
    freopen("COINCOL.inp", "r" , stdin) ;
    freopen("COINCOL.out" , "w" , stdout) ;
    enter() ;
    process() ;
    return  0 ;
}
