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
#define maxN 75005
#define oo 2000000000

using namespace std ;

int n , q , k , a[maxN] , maxa = -oo , mina = oo , c[maxN] , val[4*maxN] , rem[4*maxN]  ;
pii b[maxN] ;

void enter()
{
    cin >> n >> q >> k ; k ++ ;
    forinc(i,1,n) cin >> a[i] , maxa = max(maxa,a[i]) , mina =min(mina,a[i]) ;
    forinc(i,1,q) cin >> b[i].fi >> b[i].se ;
    forinc(i,1,q) b[i].fi++ , b[i].se ++ ;
}

void set_node(int s , int l , int r , int k)
{
    rem[s] = k  + 1 ;
    val[s] = (r-l+1) * k ;
}

void trans(int s , int l , int r)
{
    if (rem[s] == 0) return ;
    rem[2*s] = rem[s] ;
    rem[2*s+1] = rem[s] ;
    int mid = (l+r) / 2 ;
    val[2*s] = (rem[s] - 1) * (mid-l+1) ;
    val[2*s+1] = (rem[s] - 1) * (r-mid) ;
    rem[s] = 0 ;
}

void update(int s , int l , int r , int u , int v , int k)
{
    if (r < u || v < l) return ;
    if (u <= l && r <= v) {
        set_node(s,l,r,k) ;
        return ;
    }
    trans(s,l,r) ;
    int mid = (l+r) / 2 ;
    update(2*s,l,mid,u,v,k) ;
    update(2*s+1,mid+1,r,u,v,k) ;
    val[s] = val[2*s] + val[2*s+1] ;
}

int get(int s , int l , int r , int u , int v)
{
    if (r < u || v < l) return  0 ;
    trans(s,l,r) ;
    if (u <= l && r <= v) return val[s] ;
    int mid = (l+r) / 2 ;
    return get(2*s,l,mid,u,v) + get(2*s+1,mid+1,r,u,v) ;
}

int check(int x)
{
    memset(rem,0,sizeof(rem)) ;
    memset(val,0,sizeof(val)) ;
    forinc(i,1,n) if (a[i] >= x) update(1,1,n,i,i,1) ; else update(1,1,n,i,i,0) ;
    forinc(i,1,q) {
        int tmp = get(1,1,n,b[i].fi,b[i].se) ;
        if (tmp < b[i].se - b[i].fi + 1) update(1,1,n,b[i].fi,b[i].se-tmp,0) ;
        if (tmp > 0) update(1,1,n,b[i].se-tmp+1,b[i].se,1) ;
    }
    return get(1,1,n,k,k) ;
}

void process()
{
    int l = mina , r = maxa , res = 0 ;
    while (l <= r) {
        int mid = (l+r)  / 2;
        if (check(mid) == 1) res = mid , l = mid + 1  ; else r = mid - 1 ;
    }
    cout << res << endl ;
}

int main()
{
    //freopen("subsegments.inp" , "r" , stdin) ;
    enter() ;
    process() ;
    return 0 ;
}
