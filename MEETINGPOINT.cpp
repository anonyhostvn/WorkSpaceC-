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

int n , m , k ;
vector<pii> ke[maxN] ;

void enter()
{
    scanf("%d%d%d" , &n , &m , &k) ;
    forinc(i,1,m) {
        int u ,v , c ; scanf("%d%d%d" , &u , &v, &c) ;
        ke[u].push_back(mk(v,c)) ;
        ke[v].push_back(mk(u,c)) ;
    }
}

long long d[maxN] ;
priority_queue<pair<long long, int> > q ;

void dkstra(int root)
{
    forinc(i,1,n) d[i] = oo ;
    d[root] = 0 ; q.push(mk(0,root)) ;
    while (!q.empty()) {
        int u = q.top().se ; q.pop() ;
        forv(i,ke[u]) {
            int v = ke[u][i].fi ;
            if (d[v] > d[u] + ke[u][i].se) d[v] = d[u] + ke[u][i].se , q.push(mk(-d[v],v)) ;
        }
    }
}

struct node {
    long double c ;
    long long d[2] ;
};

bool cmp (node a , node b) {return a.c < b.c ; }

long long dist[2][maxN] , f[maxN] , g[maxN] ;
node p[maxN] ;

void prepare()
{
    dkstra(1) ; forinc(i,1,n) p[i].d[0] = d[i] ;
    dkstra(n) ; forinc(i,1,n) p[i].d[1] = d[i] ;
    forinc(i,1,n) if (p[i].d[1] != 0) p[i].c = (long double) p[i].d[0] / p[i].d[1] ; else p[i].c = oo ;
    sort(p+1,p+1+n,cmp) ;
    f[1] = p[1].d[1] ; g[n] = p[n].d[0] ;
    forinc(i,2,n) f[i] = min(f[i-1],p[i].d[1]) ;
    fordec(i,n-1,1) g[i] = min(g[i+1],p[i].d[0]) ;
}

int find_(long double x)
{
    int l = 1 , r = n , res = 0 ;
    while (l <= r) {
        int mid = (l+r) / 2 ;
        if (p[mid].c <= x) res = mid , l = mid + 1 ; else r = mid - 1 ;
    }
    return res ;
}

void process()
{
    prepare() ;
    forinc(i,1,k){
        int u , v ; scanf("%d%d" , &u , &v) ;
        int t = find_((long double) v / u) ;
        printf("%lld" , min((long long) v * f[t],(long long) u * g[t+1])) ; printf("\n") ;
    }
}

int main()
{
    freopen("MEETINGPOINT.inp" , "r" , stdin) ;
    freopen("MEETINGPOINT.out" , "w" , stdout) ;
    enter() ;
    process() ;
    return 0 ;
}
