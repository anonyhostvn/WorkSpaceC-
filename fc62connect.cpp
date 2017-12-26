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
#define maxN 10005

using namespace std ;

int n , f[maxN][maxN] ;
long long sw[maxN] , r[maxN] , l[maxN] ;
pii a[maxN] ;

void enter()
{
    cin >> n ;
    forinc(i,1,n) cin >> a[i].fi ;
    forinc(i,1,n) cin >> a[i].se ;
    sort(a+1,a+1+n) ;
}

void prepare()
{
    forinc(i,1,n) sw[i] = sw[i-1] + a[i].se ;
    forinc(i,1,n) l[i] = (long long) a[i].fi - sw[i] , r[i] = (long long) a[i].fi - sw[i-1] ;
    forinc(i,1,n) forinc(j,1,n) f[i][j] = -1 ;
}

void process()
{
    prepare() ;
    forinc(i,1,n) f[1][i] = (l[i] >= l[1] && l[i] <= r[1]) ? 1 : 0 ;
    forinc(i,1,n)
    forinc(j,1,n) if (f[i][j] > -1) {
        if (l[j] >= l[i+1] && l[j] <= r[i+1]) f[i+1][j] = max(f[i+1][j],f[i][j] + 1) ; else f[i+1][j] = max(f[i+1][j],f[i][j])  ;
        if (l[i+1] >= l[j]) f[i+1][i+1] = max(f[i+1][i+1],f[i][j] + 1) ;
    }
    int res = 0 ;
    forinc(i,1,n) res = max(res,f[n][i]) ;
    cout << n - res << endl ;
}

int main()
{
    //freopen("fc62connect.inp" , "r" , stdin) ;
    enter() ;
    process() ;
    return 0 ;
}
