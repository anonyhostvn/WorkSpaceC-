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

typedef long long TCoord ;

struct Point {
    TCoord x ,y ;

    TCoord operator % (const Point &b) {return x * b.x + y * b.y ; } ;

    TCoord operator * (const Point &b) {return x * b.y - y * b.x ;} ;

    Point operator  - (const Point &b) {return {x-b.x,y-b.y} ; }  ;

    TCoord sqrLen() {return x * x + y * y ; } ;
};

typedef Point Tvector ;

bool CCW(Point &a, Point &b , Point &c) {return (b-a) * (c-b) < 0 ; } ;

void enter()
{
    scanf("%d%d%d" , &n , &m , &k) ;
    forinc(i,1,m) {
        int u ,v , c ; scanf("%d%d%d" , &u , &v, &c) ;
        ke[u].push_back(mk(v,c)) ;
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

long long dist[2][maxN] , f[maxN] , g[maxN] ;

void prepare()
{
    dkstra(1) ; forinc(i,1,n) dist[0][i] = d[i] ;
    dkstra(n) ; forinc(i,1,n) dist[1][i] = d[i] ;
}

vector<Point> ans , bns ;

Point A = {oo , oo} ;

bool cmp (Point a ,Point b) { return a.x < b.x || (a.x == b.x && a.y < b.y) ; }

bool cmp_1(Point u , Point v) {return (u-A) * (v-A) > 0 || ((u-A) * (v-A) == 0 && (u-A).sqrLen() < (v-A).sqrLen()) ; }

void convexHull()
{
    vector<Point> p , q ;
    forinc(i,1,n) if (dist[0][i] < oo && dist[1][i] < oo) p.push_back({dist[0][i],dist[1][i]}) ;
    forv(i,p) cout << p[i].x << " " << p[i].y << endl ; cout << endl ;
    sort(p.begin(),p.end(),cmp) ; q.push_back(p[0]) ;
    forinc(i,1,p.size() - 1) if (p[i].x != p[i-1].x) q.push_back(p[i]) ;
    forv(i,q) if (A.y > q[i].y || (A.y == q[i].y && A.x > q[i].x)) A = q[i] ;
    sort(q.begin(),q.end(),cmp_1) ;
    forv(i,q) {
        while (ans.size() >= 2 && !CCW(ans[ans.size()-2] ,ans[ans.size()-1] , q[i])) ans.pop_back() ;
        ans.push_back(q[i]) ;
    }
}

long long solve(long long u , long long v) {
    long long res = oo ;
    forv(i,ans) res = min(res,ans[i].x * u + ans[i].y * v) ;
    return res ;
}

void process()
{
    prepare() ;
    convexHull() ;
    forinc(i,1,k) {
        long long u ,v  ; scanf("%lld%lld" , &u , &v);
        cout << u << " " << v << endl ;
        printf("%lld\n" , solve(u,v)) ;
    }
}

int main()
{
    freopen("MPOINTS.inp" , "r" , stdin) ;
    //freopen("MPOINTS.out" , "w" , stdout) ;
    enter() ;
    process() ;
    return 0 ;
}
