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
#define ooll (long long) 1e15
#define ooit (int) 2e9
#define maxN 200005

template <class _T> bool maximize(_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize(_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

using namespace std;

struct node {
    int up , down , pos , active ;
};

node coin[maxN] ;
int n , m , c[maxN] , active[maxN] ;

int fastRead() {
    int res = 0 ; char c ;
    for (c = getchar() ; c < '0' || c > '9' ; c = getchar()) ;
    for ( ; c >= '0' && c <= '9' ; c = getchar()) res *= 10  , res += (int) c - (int) '0'  ;
    return res ;
}

void enter () {
    //cin >> n >> m ;
    //scanf("%d%d" , &n , &m) ;
    n = fastRead() ; m = fastRead() ;
    forinc(i,1,n) {
        int x , y ; //cin >> x >> y ;
        //scanf("%d%d" , &x , &y) ;
        x = fastRead() ; y = fastRead() ;
        coin[i].up = max(x,y) ; coin[i].down = min(x,y) ;
        if (coin[i].up > x) coin[i].active = 1 ; else coin[i].active = 0 ;
    }
    forinc(i,1,m) c[i] = fastRead() ;
    //scanf("%d" , &c[i]) ;
    //cin >> c[i] ;
}

int val[12 * maxN] ;

void update(int s , int l , int r , int i , int k) {
    if (r < i || i < l) return ;
    if (l == r) {
        maximize(val[s],k) ;
        return ;
    }
    int mid = (l+r) / 2 ;
    update(2 * s , l , mid , i , k) ;
    update(2 * s + 1 , mid + 1 , r , i , k) ;
    val[s]  = max(val[2*s] , val[2*s+1]) ;
}

int get(int s , int l , int r , int u , int v) {
    if (r < u || v < l) return -1 ;
    if (u <= l && r <= v) return val[s] ;
    int mid = (l+r) / 2 ;
    return max(get(2*s,l,mid,u,v),get(2*s+1,mid+1,r,u,v)) ;
}

node a[maxN] ;
map<int,int> f ;
int cnt = 0 ;

int BIT[3 * maxN] ;

void update_BIT(int i , int x) {
    for ( ; i <= m ; i += i & -i) BIT[i] += x ;
}

int get_BIT(int i) {
    int res = 0 ;
    for ( ;  i > 0 ; i -= i & -i) res += BIT[i] ;
    return res ;
}

pii fp[maxN] ;
int real_val[3  * maxN] ;

void prepare () {
    forinc(i,1,m) f[c[i]] = 0 ;
    forinc(i,1,n) f[coin[i].up] = 0 , f[coin[i].down] = 0 ;
    for (auto& tmp : f) tmp.se = ++cnt , real_val[cnt] = tmp.fi ;

    forinc(i,1,n) coin[i].up = f[coin[i].up] , coin[i].down = f[coin[i].down] ;
    forinc(i,1,m) update(1,1,cnt,f[c[i]],i) , fp[i].fi = f[c[i]] , fp[i].se = i ;
    sort(fp + 1 , fp + 1 + m) ;
    forinc(i,1,n) coin[i].pos = i ;
    sort(coin + 1 , coin + 1 + n , [] (node a , node b) { return a.down < b.down ; } ) ;
}

int g[3 * maxN][20] ;

void build_rmq() {
    forinc(i,1,m) g[fp[i].fi][0] = fp[i].se ;
    int k = log2(cnt) ;
    forinc(j,1,k) forinc(i,1,n) g[i][j] = max(g[i][j-1],g[i+(1 << (j-1)) - 1][j-1]) ;
}

int get_rmq(int u , int v) {
    int k = log2(v-u+1) ;
    return max(g[u][k] , g[v- (1 << k) +1][k]) ;
}

int ans[maxN] ;

void process () {
    prepare () ;
    build_rmq() ;
    int j = 0 ;
    forinc(i,1,n) {
        while (j < m && fp[j+1].fi < coin[i].down) update_BIT(fp[++j].se,1) ;
        int t = get_rmq(coin[i].down,coin[i].up-1) ;
        if (t > 0) coin[i].active = 0 ;
        coin[i].active+= m - t - (get_BIT(m) - get_BIT(t)) ;
        ans[coin[i].pos] = (coin[i].active % 2 == 0) ? real_val[coin[i].up] : real_val[coin[i].down] ;
    }

    forinc(i,1,n) cout << ans[i] << " " ;
}

int main () {
    freopen("FLIP.inp" , "r" , stdin) ;
    freopen("FLIP.out" , "w" , stdout) ;
    //ios_base::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    enter () ;
    process () ;
    return 0 ;
}
