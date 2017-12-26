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
#define oo (long long) 1e15
#define maxN 100005

using namespace std ;

int n , a[maxN] , val[4*maxN] , rem[4*maxN] ;

void enter()
{
    scanf("%d" , &n) ;
    forinc(i,1,n) scanf("%d" , &a[i]) ;
}

void set_node(int s , int k)
{
    val[s] += k ;
    rem[s] += k ;
}

void trans(int s )
{
    if (rem[s] == 0) return ;
    set_node(2*s,rem[s]) ; set_node(2*s+1,rem[s]) ;
    rem[s] = 0 ;
}

void mini()
{
    pii b[maxN] ; forinc(i,1,n) b[i].fi = a[i] , b[i].se = i ;
    sort(b+1,b+1+n) ; a[b[1].se] = 1 ; int cnt = 1 ;
    forinc(i,2,n) {
        if (b[i].fi != b[i-1].fi) ++ cnt ;
        a[b[i].se] = cnt ;
    }
}

void update(int s , int l , int r , int u , int v , int k)
{
    if (r < u || v < l) return  ;
    if (u <= l && r <= v) {
        set_node(s,k) ;
        return ;
    }
    trans(s) ;
    int mid = (l+r) / 2 ;
    update(2*s,l,mid,u,v,k) ;
    update(2*s+1,mid+1,r,u,v,k) ;
    val[s] = min(val[2*s],val[2*s+1]) ;
}

void process()
{
    mini() ; int res = 0 ;
    update(1,1,n+1,1,a[1]+1,-1) ;
    update(1,1,n+1,1,a[2],+1) ; if (val[1] >= 0) res = 1 ;
    int t = 2 ;
    forinc(i,2,n/2) {
        update(1,1,n+1,1,a[i],-1) ;
        update(1,1,n+1,1,a[i]+1,-1) ;
        update(1,1,n+1,1,a[t+1],1) ; update(1,1,n+1,1,a[t+2],1) ; t+=2 ;
        if (val[1] >= 0) res = i ;
    }
    cout << res << endl ;
}
int main()
{
    freopen("MATROSKA.inp" , "r" , stdin) ;
    freopen("MATROSKA.out" , "w" , stdout) ;
    enter() ;
    process() ;
    return 0 ;
}
