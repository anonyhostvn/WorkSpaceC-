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

struct node
{
    int iblock , sl , sr , id ;
};

int n , t , b[200001] , p ;
pii a[200001] ;
node query[200001] ;
long long ans[200001] , res , k[200001] ,  real_val[1000001]   ;

bool cmp(node a , node b)
{
     return (a.iblock < b.iblock) || ((a.iblock == b.iblock) && (a.sr < b.sr)) ;
}

int enter()
{
    cin >> n >> t ; p = (int) sqrt(n) ;
    forinc(i,1,n) {
        cin >> a[i].fi ; a[i].se = i ;
    }
    forinc(i,1,t) {
        int u , v ; cin >> u >> v ;
        query[i].sl = u ; query[i].sr = v ; query[i].iblock = (u-1) / p  ; query[i].id = i ;
    }
    return 0 ;
}

int prepare()
{
    sort(a+1,a+1+n) ;
    int cnt = 1 ;
    b[a[1].se] = 1 ; real_val[1] = a[1].fi ;
    forinc(i,2,n) {
        if (a[i].fi != a[i-1].fi) ++ cnt ;
        b[a[i].se] = cnt ; real_val[cnt] = a[i].fi ;
    }
    sort(query+1,query+1+t,cmp) ;
    return 0 ;
}

int preset()
{
    forinc(i,1,n) k[i] = 0 ;
    return 0 ;
}

int push(int i , int x)
{
    res -= (long long)k[x] * k[x] * real_val[x] ;
    k[x] ++ ;
    res += (long long) k[x] * k[x] * real_val[x] ;
    return 0 ;
}

int pop(int i , int x)
{
    res -= (long long) k[x] * k[x] * real_val[x] ;
    k[x] -- ;
    res += (long long) k[x] * k[x] * real_val[x] ;
    return 0 ;
}

int solve(int queryl , int queryr , int block)
{
    res = 0 ;
    preset() ;
    forinc(i,query[queryl].sl,query[queryl].sr) push(i,b[i]) ;
    ans[query[queryl].id] = res ;
    forinc(i,queryl+1,queryr) {
        if (query[i].sl <= query[i-1].sl)
            forinc(j,query[i].sl,query[i-1].sl-1) push(j,b[j]) ;
        else forinc(j,query[i-1].sl,query[i].sl-1) pop(j,b[j]) ;
        forinc(j,query[i-1].sr+1,query[i].sr) push(j,b[j]) ;
        ans[query[i].id] = res ;
    }
    return 0 ;
}

int process()
{
    int j = 1 ;
    prepare() ;
    forinc(i,2,t) if (query[i].iblock != query[i-1].iblock) {
        solve(j,i-1,query[j].iblock) ;
        j = i ;
    }
    solve(j,t,query[j].iblock) ;
    forinc(i,1,t) cout << ans[i] << endl ;
    return 0 ;
}

int main()
{
    //freopen("86D.inp" , "r" , stdin) ;
    enter() ;
    process() ;
    return 0 ;
}
