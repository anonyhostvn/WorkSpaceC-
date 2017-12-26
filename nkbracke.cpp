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

int n , q ;
pii val[4*maxN] ;

void setnode(int s , int l , int r , int k)
{
    val[s].fi = 0 ; val[s].se = 0 ;
    if (k == -1) val[s].se = 1  ;
    else val[s].fi = 1 ;
}

pii combine(pii s1 , pii s2)
{
    pii tmp ;
    int valid  = min(s1.fi,s2.se) ;
    tmp.fi = s1.fi + s2.fi - valid ;
    tmp.se = s1.se + s2.se - valid ;
    return tmp ;
}

void update(int s , int l , int r , int i , int k)
{
    if (r < i || i < l) return ;
    if (l == r) { setnode(s,l,r,k) ; return ; }
    int mid = (l+r) / 2 ;
    update(2*s,l,mid,i,k) ;
    update(2*s+1,mid+1,r,i,k) ;
    val[s] = combine(val[2*s],val[2*s+1]) ;
}

pii get(int s, int l , int r , int u ,int v)
{
    if (r < u || v < l) return mk(0,0) ;
    if (u <= l && r <= v) return val[s] ;
    int mid = (l+r) / 2 ;
    return combine(get(2*s,l,mid,u,v) , get(2*s+1,mid+1,r,u,v)) ;
}

void enter()
{
    ios_base::sync_with_stdio(false) ;
    cin.tie(0) ; cout.tie(0) ;
    cin >> n >> q ;
    forinc(i,1,n) {
        char ch ; cin >> ch ;
        if (ch == '(') update(1,1,n,i,1) ; else update(1,1,n,i,-1) ;
    }
    forinc(i,1,q) {
        int query = 0 ; cin >> query ;
        if (query == 1) {
            int u , v ; cin >> u >> v ;
            pii tmp = get(1,1,n,u,v) ;
            if (tmp.fi == 0 && tmp.se == 0) cout << 1 ; else cout << 0 ;
        } else {
            char ch ; int x ;
            cin >> x >> ch;
            if (ch == '(') update(1,1,n,x,1) ; else update(1,1,n,x,-1) ;
        }
    }
}

int main()
{
    //freopen("nkbracke.inp" , "r" , stdin) ;
    enter() ;
    return 0 ;
}
