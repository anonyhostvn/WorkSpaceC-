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

template <class _T> bool maximize(_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize(_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

const int ooit = 2e9 ;
const long long ooll = 1e15 ;

using namespace std ;

typedef long long TCoord ;

struct Point {
    TCoord x , y ;
} ;

#define maxM 10005

int m ;
vector<Point> poly[maxM] ;

void fix(int &x) {x += 100 ; }

void enter () {
    cin >> m ;
    forinc(i,1,m) {
        int n = 0 ; cin >> n ;
        forinc(j,1,n) {
            int x , y ;
            cin >> x >> y ; fix(x) ; fix(y) ;
            poly[i].push_back({x,y}) ;
        }
    }
}

void prepare () {
    forinc(i,1,m)
        sort(poly[i].begin() , poly[i].end() , [] (Point a , Point b) {
            return (a.x < b.x) || (a.x == b.x && a.y < b.y) ;
        }) ;
}

#define maxCoord_1 205

bool dd[maxCoord_1][maxCoord_1] ;

void sub1 () {
    prepare () ;

    forinc(i,1,m) forinc(x,poly[i][0].x + 1,poly[i][2].x) forinc(y,poly[i][0].y + 1,poly[i][1].y) dd[x][y] = true ;
    int res = 0 ;
    forinc(i,0,200) forinc(j,0,200) res += dd[i][j] ;
    cout << res << endl ;
}

struct Tsegment_tree {
    int val[4 * maxM] , rem[4 * maxM];

    void set_node (int s , int x) {
        maximize(val[s],x) ;
        maximize(rem[s],x) ;
    }

    void trans (int s) {
        if (rem[s] == 0) return ;
        set_node(2 * s , rem[s]) ;
        set_node(2 * s + 1 , rem[s]) ;
    }

    void update(int s , int l , int r , int u , int v , int k) {
        if (r < u || v < l) return ;
        if (u <= l && r <= v) { set_node(s,k) ; return ; }
        trans(s) ;
        int mid = (l+r) / 2 ;
        update(2 * s , l , mid , u , v , k) ;
        update(2 * s + 1 , mid + 1 , r , u , v , k) ;
        val[s] = max(val[2 * s],val[2 * s + 1]) ;
    }

    int get(int s , int l , int r , int u , int v) {
        if (r < u || v < l) return 0 ;
        if (u <= l && r <= v) return val[s] ;
        trans(s) ; int mid = (l+r) / 2 ;
        return max(get(2 * s , l , mid , u , v) , get(2 * s + 1 , mid + 1 , r , u , v)) ;
    }
} tree[2] ;

map<int,int> fx , fy ;
int px = 0 , py = 0 ;
int V[4 * maxM] ;

void prepare_ () {
    forinc(i,1,m)
        for (auto tmp : poly[i]) fx[tmp.x] = 0 , fy[tmp.y] = 0 ;
    for (auto &tmp : fx) tmp.se = ++px , V[px] = tmp.fi ;
    for (auto &tmp : fy) tmp.se = ++py , V[py] = tmp.fi ;
}

vector<int> CoordX ;

void build_tree () {
    forinc(i,1,m) {
        tree[0].update(1,1,px,fx[poly[i][0].x],fx[poly[i][1].x],fy[poly[i][0].y]) ;
        tree[0].update(1,1,px,fx[poly[i][0].x],fx[poly[i][1].x],fy[poly[i][2].y]) ;
        tree[1].update(1,1,px,fx[poly[i][0].x],fx[poly[i][1].x],-fy[poly[i][0].y]) ;
        tree[1].update(1,1,px,fx[poly[i][0].x],fx[poly[i][1].x],-fy[poly[i][2].y]) ;

        CoordX.push_back(poly[i][0].x) ; CoordX.push_back(poly[i][1].x) ;
    }
    sort(CoordX.begin() , CoordX.end())  ;
    //for (auto tmp : CoordX) cout << tmp << " " ;
}

void sub2 () {
    prepare_();
    build_tree() ;

    long long res = 0 ;
    forinc(i,1,CoordX.size() - 1) if (CoordX[i] !=  CoordX[i-1]) {
        int minY = tree[0].get(1,1,px,fx[CoordX[i-1]],fx[CoordX[i]]) , maxY = -tree[1].get(1,1,px,fx[CoordX[i-1]],fx[CoordX[i]]) ;
        res += abs ((long long) (CoordX[i] - CoordX[i-1]) * (V[minY] - V[maxY])) ;
    }

    cout << res << endl ;
}

int main () {
    freopen("POLY.inp" , "r" , stdin) ;
    //freopen("POLY.out" , "w" , stdout) ;
    enter () ;
    sub2 () ;
    return 0 ;
}
