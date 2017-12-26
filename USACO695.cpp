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
#define maxN 25

using namespace std ;

int n , a[maxN][maxN] ;

void enter() {
    cin >> n ;
    forinc(i,1,n) forinc(j,1,n) {
        char ch ; cin >> ch ;
        if (ch == 'H') a[i][j] = 1 ;
    }
    //forinc(i,1,n) {forinc(j,1,n) cout << a[i][j] ; cout << endl ; }
}

struct node {
    int dir_1 , x_1 , y_1 , dir_2 , x_2 , y_2 ;
};

int gox[4] = {-1  , 0 , +1 , 0} ;
int goy[4] = {0 , +1 , 0 , -1 } ;
int d[4][maxN][maxN][4][maxN][maxN] ;
queue<node> q ;

inline bool min_check(int x , int y) { if (x > 0 && x <= n && y > 0 && y <= n && a[x][y] == 0) return true ; return false ; }

inline bool check(node tmp) { if ((!min_check(tmp.x_1,tmp.y_1)) || (!min_check(tmp.x_2,tmp.y_2))) return false ; return true ;}

inline node get_coor(int id , node tmp) {
    node res , res_1 ;
    if (id == 0) res.dir_1 = tmp.dir_1 , res.dir_2 = tmp.dir_2 ;
    else if (id == 1) res.dir_1 = (tmp.dir_1 + 3) % 4 , res.dir_2 = (tmp.dir_2 + 3) % 4 ;
    else res.dir_1 = (tmp.dir_1 + 1) % 4 , res.dir_2 = (tmp.dir_2 + 1) % 4 ;
    res.x_1 = tmp.x_1 ; res.x_2 = tmp.x_2 ; res.y_1 = tmp.y_1 ; res.y_2 = tmp.y_2 ; res_1 = res ;
    if (id == 0) res.x_1 += gox[res.dir_1] , res.y_1 += goy[res.dir_1] , res.x_2 += gox[res.dir_2] , res.y_2 += goy[res.dir_2] ;
    if (!min_check(res.x_1,res.y_1)) res.x_1 = res_1.x_1 , res.y_1 = res_1.y_1 ;
    if (!min_check(res.x_2,res.y_2)) res.x_2 = res_1.x_2 , res.y_2 = res_1.y_2 ;
    if (res_1.x_1 == 1 && res_1.y_1 == n) res.x_1 = res_1.x_1 , res.y_1 = res_1.y_1 ;
    if (res_1.x_2 == 1 && res_1.y_2 == n) res.x_2 = res_1.x_2 , res.y_2 = res_1.y_2 ;
    return res ;
}

inline bool not_visit(node a) {return d[a.dir_1][a.x_1][a.y_1][a.dir_2][a.x_2][a.y_2] == -1 ; }

inline void update_(node a , node b) { d[a.dir_1][a.x_1][a.y_1][a.dir_2][a.x_2][a.y_2] = d[b.dir_1][b.x_1][b.y_1][b.dir_2][b.x_2][b.y_2] + 1 ; }

void bfs() {
    memset(d , -1 , sizeof(d)) ;
    d[0][n][1][1][n][1] = 0 ; q.push({0,n,1,1,n,1}) ;
    //forinc(i,0,1) forinc(x,1,n) forinc(y,1,n) forinc(j,0,1) forinc(u,1,n) forinc(v,1,n) cout << d[i][x][y][j][u][v] << endl ;
    while (!q.empty()) {
        node tmp = q.front() ; q.pop() ;
        forinc(i,0,2) {
            node _ = get_coor(i,tmp) ;
            if (not_visit(_)) update_(_,tmp) , q.push(_) ;
        }
    }
    int res = ooit ;
    forinc(i,0,3) forinc(j,0,3) if (d[i][1][n][j][1][n] != -1) res = min(res,d[i][1][n][j][1][n]) ;
    cout << res << endl ;
}

int main() {
    freopen("cownav.in" , "r" , stdin) ;
    freopen("cownav.out" , "w" , stdout) ;
    enter() ;
    bfs() ;
    return 0 ;
}
