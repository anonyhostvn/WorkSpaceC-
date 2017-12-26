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
#define oo 1000000000

using namespace std ;

int n , m , k , a[100001] , b[21] , sb , sa ;

int enter()
{
    cin >> n >> m >> k ;
    forinc(i,1,n) cin >> a[i] ;
    forinc(i,1,m) cin >> b[i] ;
    return 0 ;
}

int getbit(int x , int i)
{
    return (x >> (i-1)) & 1 ;
}
pair<long long,int>  c[1100000] ;
int d[100005] ;

bool cmp(pair<long long,int> a , pair<long long,int> b)
{
    return (a.fi < b.fi) || ((a.fi == b.fi) && (a.se > b.se)) ;
}

int prepare()
{
    int l = pow(2,m) - 1 ; sb = 0 ;
    forinc(i,0,l) {
        int cnt = 0 ;
        long long sum = 0 ;
        forinc(j,1,m) if (getbit(i,j)) {
            sum += b[j] ; ++cnt ;
            if (sum > k) break ;
        }
        if (sum > k) continue ;
        c[++sb].fi = sum ; c[sb].se = cnt ;
    }

    sort(c+1,c+1+sb,cmp) ;
    d[0] = k ;
    forinc(i,1,n) {
        if (d[i-1] - a[i] < 0) break ;
        d[i] = d[i-1] - a[i] ; sa = i ;
    }
    return 0 ;
}

int process()
{
    prepare() ;
    int j =  1 , res = oo ;
    fordec(i,sa,0) {
        while (j <= sb && d[i] >= c[j].fi) {
            if (d[i] == c[j].fi) res = min(res,n-i+c[j].se) ;
            ++j ;
        }
    }
    cout << res ;
    return 0 ;
}

int main()
{
    freopen("carriage.inp" , "r" , stdin) ;
    freopen("carriage.out" , "w" , stdout) ;
    enter() ;
    process();
    return 0 ;
}
