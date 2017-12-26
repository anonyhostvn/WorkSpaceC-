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
#define maxN 500005
#define oo (int) 1e9

using namespace std ;

int n , m , c1 ,c2 ;
pii a[2 * maxN];

void enter()
{
    cin >> n >> m ;
    cin >> c1 >> c2 ;
    forinc(i,1,n+m) cin >> a[i].fi , a[i].se = (int) (i > n) ;
}

map<int,int> f ;
map<int,int> :: iterator it ;

void process()
{
    sort(a+1,a+1+n+m) ;
    forinc(i,2,n+m) if (a[i].se != a[i-1].se) f[abs(a[i].fi-a[i-1].fi)] ++ ;
    int ans = oo , cnt = 0;
    for (it = f.begin() ; it != f.end() ; it++) if (ans > (*it).first) ans = (*it).first , cnt = (*it).second ;
    cout << ans + abs(c1-c2) << " " << cnt << endl ;
}

int main()
{
    //freopen("closet.inp" , "r" , stdin) ;
    ios_base::sync_with_stdio(false) ;
    cin.tie(0) ; cout.tie(0) ;
    enter() ;
    process() ;
    return 0 ;
}
