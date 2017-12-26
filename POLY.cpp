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
#define maxN 205

using namespace std ;

typedef long long TCoord ;
typedef long double llu ;

struct Point {
    TCoord x , y ;
    Point operator - (const Point &v) {return {x - v.x , y - v.y} ; }
    TCoord sqrLen() {return x * x + y * y ; }
    TCoord operator * (const Point &v) {return x * v.y - y * v.x ; }
};

typedef Point Tvector ;

int n , k ;
Point a[maxN] ;

void enter()
{
    scanf("%d%d" , &n , &k) ;
    forinc(i,1,n) scanf("%lld%lld" , &a[i].x , &a[i].y) ;
}

Point A ;

Point Find_A()
{
    Point res = {oo,oo} ;
    forinc(i,1,n) if (res.y > a[i].y || (res.y == a[i].y && res.x > a[i].x)) res = a[i] ;
    return res ;
}

vector<Point> ans ;

bool cmp(Point u , Point v) {return ((u-A) * (v-A) > 0) || ((u-A) * (v-A) == 0 && (u-A).sqrLen() < (v-A).sqrLen()) ; }

bool CCW(Point A , Point B , Point C) {return ( (B-A) * (C-B) > 0 ) ; }

void convexHull()
{
    A = Find_A() ;
    sort(a+1,a+1+n,cmp) ;
    //forinc(i,1,n) cout << a[i].x << " " << a[i].y << endl ;
    forinc(i,1,n) {
        while (ans.size() >= 2 && !CCW(ans[ans.size()-2],ans[ans.size()-1],a[i])) ans.pop_back() ;
        ans.push_back(a[i]) ;
    }
}

llu SolveS(vector<Point> a ) {
    llu res = 0 ;
    forv(i,a) res += a[i] * a[(i+1) %  a.size()] ;
    return res / 2 ;
}

llu S_convex ;
vector<pair<int,llu> > ke[maxN] ;

inline void add(int  u , int v , llu c) { ke[u].push_back(mk(v,c)) ; }

void build_graph()
{
    S_convex = SolveS(ans) ;
    vector<Point> tmp ;
    forv(i,ans) {
        tmp.clear() ;
        tmp.push_back(ans[i]) ;
        forinc(j,i+1,ans.size()-1) {
            tmp.push_back(ans[j]) ;
            llu S = SolveS(tmp) ;
            add(i,j,S) ; add(j,i,S_convex-S) ;
        }
    }
}

typedef pair<llu , pair<int,int> > data ;

priority_queue<data> q ;
llu d[maxN][maxN] ;

void dkstra(int root) {
    forinc(i,0,ans.size()-1) forinc(j,0,ans.size()-1) d[i][j] = oo ;
    d[root][0] = 0 ; q.push(mk(0,mk(root,0))) ;
    while (!q.empty()) {
        data tmp = q.top() ; q.pop() ;
        int u = tmp.se.fi , t = tmp.se.se ;
        forv(i,ke[u]) {
            int v = ke[u][i].fi ;
            if (t < k && d[v][t+1] > d[u][t] + ke[u][i].se) d[v][t+1] = d[u][t] + ke[u][i].se , q.push(mk(-d[v][t+1],mk(v,t+1))) ;
        }
    }
}

void process()
{
    convexHull() ;
    build_graph() ;
    llu res = 0 ;
    forv(i,ans) {
        dkstra(i) ;
        res = max(res,S_convex-d[i][k]) ;
    }
    cout << fixed << setprecision(2) << res << endl ;
}

int main()
{
    freopen("POLY.inp" , "r" , stdin) ;
    freopen("POLY.out" , "w" , stdout) ;
    enter() ;
    process() ;
    return 0;
}
