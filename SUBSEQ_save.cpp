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

int n , d ;
int a[maxN]  , b[maxN] , c[maxN] , root[maxN] ;

void enter()
{
    scanf("%d%d" , &n , &d) ;
    forinc(i,1,n) scanf("%d" , &a[i]) ;
    forinc(i,1,n) b[i] = a[i] - d , c[i] = a[i] + d , root[i] = a[i] ;
}

pii p[3*maxN] ;

void set_val(int id , int x)
{
    if (id <= n) a[id] = x ;
    else if (id <= 2 * n) b[id-n] = x ; else c[id-2*n] = x ;
}

void prepare()
{
    forinc(i,1,n) p[i].fi = a[i] ;
    forinc(i,n+1,2*n) p[i].fi = b[i-n] ;
    forinc(i,2*n+1,3*n) p[i].fi = c[i-2*n] ;
    forinc(i,1,3*n) p[i].se = i ;
    sort(p+1,p+1+3*n) ;
    int cnt = 1 ; set_val(p[1].se,cnt) ;
    forinc(i,2,3*n) {
        if (p[i].fi != p[i-1].fi) cnt ++ ;
        set_val(p[i].se,cnt) ;
    }
}

int val[12*maxN] ;
int f[maxN] , trc[maxN] ;

void update(int s , int l , int r , int i , int k)
{
    if (r < i || i < l) return ;
    if (l == r) {
        if (f[k] > f[val[s]]) val[s] = k ;
        return ;
    }
    int mid = (l+r) / 2 ;
    update(2*s,l,mid,i,k) ;
    update(2*s+1,mid+1,r,i,k) ;
    if (f[val[2*s]] > f[val[2*s+1]]) val[s] = val[2*s] ; else val[s] = val[2*s+1] ;
}

int get(int s , int l , int r , int u  , int v)
{
    if (r < u || v < l) return 0 ;
    if (u <= l && r <= v) return val[s] ;
    int mid = (l+r) / 2 , t_1 = get(2*s,l,mid,u,v) , t_2 = get(2*s+1,mid+1,r,u,v) ;
    if (f[t_1] > f[t_2]) return t_1 ; return t_2 ;
}

vector<int> ans ;

void trace(int u)
{
    if (u == 0) return ;
    trace(trc[u]) ;
    ans.push_back(u) ;
}

void process()
{
    prepare() ; int res = 0 , fi = 0 ;
    forinc(i,1,n) {
        int tmp = get(1,1,3*n,b[i],c[i]) ;
        res = max(res,f[tmp]+1) ;
        f[i] = f[tmp] + 1 ; trc[i] = tmp ;
        if (f[i] == res) fi = i ;
        update(1,1,3*n,a[i],i) ;
    }
    printf("%d\n" , res) ;
    trace(fi) ;
    forv(i,ans) printf("%d " , root[ans[i]]) ; cout << endl ;
}

int main()
{
    freopen("SUBSEQ.inp" , "r" , stdin) ;
    freopen("SUBSEQ.out" , "w" , stdout) ;
    enter() ;
    process() ;
    return 0 ;
}
