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
#define maxN 100000
#define maxK 50
#define oo 2000000000
#define base 790972

using namespace std ;

int  n , k ;
pii a[maxN+2] ;
long long f[maxK+1] ;

int enter()
{
    cin >> n >> k ;
    forinc(i,1,n) cin >> a[i].se >> a[i].fi ;
    return 0 ;
}

long long solve(int l , int r)
{
    memset(f,0,sizeof(f)) ;
    f[0] = 1 ;
    forinc(i,l,r)
    fordec(j,k,0) {f[j] += ((long long) f[j-1] * a[i].se) % base ; f[j] %= base ; }
    return f[k] ;
}

int process()
{
    sort(a+1,a+1+n) ;
    f[0] = 1 ;
    forinc(i,1,n)
    fordec(j,k,1) {f[j] += (long long) (f[j-1]  * a[i].se) % base ; f[j] %= base ;}
    long long res = f[k] , last = 1 ;
    forinc(i,2,n+1)
        if (a[i].fi != a[i-1].fi) {
            res -= solve(last,i-1) ; res += base ; res %= base ;
            last = i ;
        }
    cout << res ;
    return 0 ;
}

int main()
{
    //freopen("11BC1.inp" , "r" , stdin) ;
    enter() ;
    process() ;
    return 0  ;
}
