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
#define maxQ 200005
#define maxN 100005

using namespace std ;

struct node {
    int type , x , y ;
};

struct Coord {int x , y  ; };
typedef pair<Coord,int> pCi ;

int n , q ;
node query[maxQ] ;
vector<pCi> a ;

void enter() {
    //cin >> n >> q ;
    scanf("%d%d" , &n , &q) ;
    forinc(i,1,n) {
        int x , y  ; //cin >> x >> y ;
        scanf("%d%d" , &x  , &y) ;
        a.push_back({{x,y},i}) ;
    }
    forinc(i,1,q) {
        scanf("%d%d%d" , &query[i].type , &query[i].x , &query[i].y );
        a.push_back({{query[i].x,query[i].y},i + n}) ;
    }
}

Coord S[maxN] ;
int val_x[3 * maxN] , val_y[3 * maxN] ;                 /// [ (fi , se) , (fi , se) , (fi , se) , () , () ]
                                                        /// f[fi] = se ;

map<int,int> f  ;

inline void roi_rac() {
    forv(i,a) f[a[i].fi.x] = 0 ; int cnt = 0 ;
    for (auto& it : f) (it).se = ++cnt , val_x[cnt] = it.fi ;
    forv(i,a) a[i].fi.x = f[a[i].fi.x] ; f.clear() ;

    forv(i,a) f[a[i].fi.y] = 0 ; cnt = 0 ;
    for (auto& it : f) it.se = ++cnt , val_y[cnt] = it.fi ;
    forv(i,a) a[i].fi.y = f[a[i].fi.y] ;
}

inline void prepare() {
    roi_rac() ;
    forv(i,a) if (a[i].se <= n) S[a[i].se] = a[i].fi ; else query[a[i].se-n].x = a[i].fi.x , query[a[i].se-n].y = a[i].fi.y ;
}

set<int> ddx[3 * maxN] , ddy[3*maxN] ;

inline void Build_() {
    forinc(i,1,n) ddx[S[i].x].insert(S[i].y) , ddy[S[i].y].insert(S[i].x) ;
}

long long solve(int x , int y , int u , int v) {
    return (long long) abs(val_x[u] - val_x[x]) * abs(val_y[v] - val_y[y]) ;
}

void process() {
    prepare() ;
    Build_() ;
    forinc(i,1,q) {
        if (query[i].type == 2) ddx[query[i].x].erase(query[i].y) , ddy[query[i].y].erase(query[i].x) ;
        else if (query[i].type == 1) ddx[query[i].x].insert(query[i].y) , ddy[query[i].y].insert(query[i].x) ;
        else {
            if (ddx[query[i].x].size() == 0 || ddy[query[i].y].size() == 0) {
                printf("%d\n" , 0);
                continue ;
            }
            int x = query[i].x , y = query[i].y , minY = *ddx[x].begin() , maxY = *ddx[x].rbegin() , minX = *ddy[y].begin() , maxX = *ddy[y].rbegin() ;
            long long res = max(max(solve(x,y,minX,minY),solve(x,y,minX,maxY)) , max(solve(x,y,maxX,minY) , solve(x,y,maxX,maxY))) ;
            if (res % 2 == 0) printf("%lld\n" , res/ 2) ; else printf("%lld.5\n" , res / 2); ;
        }
    }
}

int main() {
    freopen("TRIANGLE.inp" , "r" , stdin) ;
    freopen("TRIANGLE.out" , "w" , stdout) ;
    enter() ;
    process() ;
    return 0 ;
}

