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

int n , a[maxN] , q , t = 0  , rem[2][4*maxN];
bool ok_rem[2][4*maxN] ;
struct node {
    long long sum_square , sum ;
};
node val[4*maxN] , null  = {0 , 0} ;

void enter()
{
    cin >> n >> q ;
    forinc(i,1,n) cin >> a[i] ;
}

void set_node(int s , int l , int r , int query , int x)
{
    long long len = r - l + 1 ;
    if (query == 0) {
        ok_rem[1][s] = false ;
        ok_rem[0][s] = true ; rem[0][s] = x ;
        val[s].sum_square = (long long) len * x * x ;
        val[s].sum = (long long) len * x ;
    }
    else {
        ok_rem[1][s] = true ;
        rem[1][s] += x ;
        val[s].sum_square += (long long) val[s].sum * x * 2 + (long long) len * x * x ;
    }
}

void trans(int s , int l , int r)
{
    int mid = (l+r) / 2 ;
    if (ok_rem[0][s]) {
        set_node(2*s,l,mid,0,rem[0][s]) ;
        set_node(2*s+1,mid+1,r,0,rem[0][s]) ;
        ok_rem[0][s] = false ;
    }
    if (ok_rem[1][s]) {
        set_node(2*s,l,mid,1,rem[1][s]) ;
        set_node(2*s+1,mid+1,r,1,rem[1][s]) ;
        ok_rem[1][s] = false ;
    }
}

node combine(node a , node b)
{
    node res ;
    res.sum_square = a.sum_square + b.sum_square ;
    res.sum = a.sum + b.sum ;
    return res ;
}

void update(int s , int l , int r , int u , int v , int query , int k)
{
    if (r < u || v < l) return ;
    if (u <= l && r <= v) {
        set_node(s,l,r,query,k) ;
        return ;
    }
    trans(s,l,r) ;
    int mid = (l+r) / 2 ;
    update(2*s,l,mid,u,v,query,k) ;
    update(2*s+1,mid+1,r,u,v,query,k) ;
    val[s] = combine(val[2*s],val[2*s+1]) ;
}

node get(int s , int l , int r , int u , int v)
{
    if (r < u  || v < l) return null ;
    if (u <= l && r <= v) return val[s] ;
    int mid = (l+r) / 2 ;
    trans(s,l,r) ;
    return combine(get(2*s,l,mid,u,v) , get(2*s+1,mid+1,r,u,v)) ;
}

void process(int id)
{
    cout << "Case " << id << ":" << endl ;
    forinc(i,1,n) update(1,1,n,i,i,0,a[i]) ;
    forinc(i,1,q) {
        int query ; cin >> query ;
        if (query <= 1) {
            int u , v , x ; cin >> u >> v >> x ;
            update(1,1,n,u,v,query,x) ;
        } else {
            int u , v ; cin >> u >> v ;
            cout << get(1,1,n,u,v).sum_square << endl  ;
        }
    }
}

int main()
{
    //freopen("SEGSQRSS.inp" , "r"  , stdin) ;
    cin >> t ;
    forinc(i,1,t) enter() , process(i) ;
    return 0 ;
}
