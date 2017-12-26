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
#define maxN 100005

using namespace std ;

struct node {
    int node_left , node_right , sum ;
};
int n , q , a[maxN]  , real_val[maxN] , id[maxN] , snode ;
pii b[maxN] ;
node val[20*maxN] ;

void enter()
{
    cin >> n >> q ;
    forinc(i,1,n) cin >> a[i] ;
}

void mini()
{
    forinc(i,1,n) b[i].fi = a[i] , b[i].se = i ;
    sort(b+1,b+1+n) ;
    int cnt = 1 ; real_val[1] = a[b[1].se] ; a[b[1].se] = 1 ;
    forinc(i,2,n) {
        cnt += (int) (b[i].fi != b[i-1].fi) ;
        real_val[cnt] = a[b[i].se] ;
        a[b[i].se] = cnt ;
    }
}

void update(int s , int l , int r , int older , int x)
{
    if (l == r) { val[s].sum ++ ; return ; }
    int mid = (l+r) / 2 ;
    if (x <= mid) {
        val[s].node_right = val[older].node_right ;
        val[s].node_left = ++snode ;
        update(snode,l,mid,val[older].node_left,x) ;
    } else {
        val[s].node_left = val[older].node_left ;
        val[s].node_right = ++snode ;
        update(snode,mid+1,r,val[older].node_right,x) ;
    }
    val[s].sum = val[val[s].node_left].sum + val[val[s].node_right].sum ;
}

void prepare()
{
    snode = 1;  id[1] = 1 ;
    update(1,1,n,0,a[1]) ;
    forinc(i,2,n) id[i] = ++snode , update(snode,1,n,id[i-1],a[i]) ;
}

int get(int s , int l , int r , int x)
{
    if (l == r) return val[s].sum ;
    int mid = (l+r) / 2 ;
    if (x <= mid) return get(val[s].node_left,l,mid,x) ;
    else return val[val[s].node_left].sum + get(val[s].node_right,mid+1,r,x) ;
}

int query(int x , int u , int v)
{
    return get(id[v],1,n,x) - get(id[u-1],1,n,x) ;
}

int solve(int u , int v , int x)
{
    int l = 1 , r = n , res = 0 ;
    while (l <= r){
        int mid = (l+r)  / 2 ;
        if (query(mid,u,v) >= x) res = mid , r = mid - 1 ; else l = mid + 1 ;
    }
    return res ;
}

void process()
{
    mini() ;
    prepare() ;
    forinc(i,1,q) {
        int u ,v , x ; cin >> u >> v >> x ;
        cout << real_val[solve(u,v,x)] << endl ;
    }
}

int main()
{
    freopen("MKTHNUM.inp" , "r" , stdin) ;
    enter() ;
    process() ;
    return 0 ;
}
