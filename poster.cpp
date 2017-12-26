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
#define maxN 40005

using namespace std ;

int n , rem[8*maxN] , val[8*maxN] ;

void setnode(int s , int k)
{
    if (k == -1) val[s] = 0 , rem[s] = -1 ;
    else val[s] = k , rem[s] = k ;
}

void trans(int s)
{
    if (rem[s] == 0) return ;
    setnode(2*s,rem[s]) ; setnode(2*s+1,rem[s]) ;
    rem[s] = 0 ;
}

void update(int s , int l , int r , int u , int v , int k)
{
    if (r < u || v < l) return ;
    if (u <= l && r <= v) {
        setnode(s,k) ;
        return ;
    }
    int mid = (l+r) / 2 ;
    trans(s) ;
    update(2*s,l,mid,u,v,k) ;
    update(2*s+1,mid+1,r,u,v,k) ;
    val[s] = max(val[2*s],val[2*s+1]) ;
}

int get(int s , int l , int r , int i)
{
    if (r < i || i < l) return 0 ;
    if (l == r) return val[s] ;
    int mid = (l+r)  /  2 ;
    trans(s) ;
    return max(get(2*s,l,mid,i),get(2*s+1,mid+1,r,i)) ;
}

pii a[2*maxN] , query[maxN]  ;
int m = 0 ;

void enter()
{
    cin >> n ; m = 0 ;
    forinc(i,1,n) {
        int u , v ; cin >> u >> v ;
        a[++m].fi = u ; a[m].se = -i ;
        a[++m].fi = v ; a[m].se = i ;
    }
}

void prepare()
{
    sort(a+1,a+1+2*n) ;
    int cnt = 1 ; if (a[1].se < 0) query[-a[1].se].fi = 1 ; else query[a[1].se].se = 1 ;
    forinc(i,2,2 * n) {
        if (a[i].fi != a[i-1].fi) cnt ++ ;
        if (a[i].se < 0) query[-a[i].se].fi = cnt ; else query[a[i].se].se = cnt ;
    }
}

bool dd[2 * maxN] ;

void process()
{
    val[1] = 0 ; rem[1] = -1 ;
    prepare() ;
    forinc(i,1,n) update(1,1,2*n,query[i].fi,query[i].se,i) ;
    forinc(i,1,2*n) dd[i] = false ;
    int res =0 ;
    forinc(i,1,2*n) {
        int id = get(1,1,2*n,i) ;
        if (id != 0 && !dd[id]) res ++ , dd[id] = true ;
    }
    cout << res << endl ;
}

int main()
{
    //freopen("poster.inp" , "r" , stdin) ;
    int t = 0 ; cin >> t ;
    while (t--) enter() , process() ;
    return 0 ;
}
