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
#define maxN 1005

using namespace std ;

int n , a[maxN][maxN] , L1 , C1 , L2 , C2;

void enter() {
    cin >> n ;
    forinc(i,1,n) forinc(j,1,n) cin >> a[i][j] ;
    cin >> L1 >> C1 >> L2 >> C2 ;
}

const int gox[4] = {-1 , 0 , +1 , 0 } ;
const int goy[4] = { 0 ,+1 , 0 , -1 } ;

struct node {
    int x , y , direct, broken ;
};

int d[maxN][maxN][4][2] ;

void bfs(int xrot , int yrot) {
    deque<node> q ;
    forinc(i,1,n) forinc(j,1,n) forinc(k,0,3) forinc(t,0,1) d[i][j][k][t] = ooit ;
    forinc(i,0,3) d[xrot][yrot][i][0] = 0 , q.push_back({xrot,yrot,i,0}) ;

    while (!q.empty()) {
        node tmp = q.front() ; q.pop_front() ;
        int x = tmp.x  , y = tmp.y , direct = tmp.direct , broken = tmp.broken ;

        forinc(i,0,3) {
            int cx = x + gox[i] , cy = y + goy[i] ;
            if (cx > 0 && cy > 0 && cx <= n && cy <= n) {

                if (a[cx][cy] == 0 && d[cx][cy][i][broken] > d[x][y][direct][broken] + (int) (i != direct)) {
                    d[cx][cy][i][broken] = d[x][y][direct][broken] + (int) (i != direct) ;
                    if (i != direct) q.push_back({cx,cy,i,broken}) ; else q.push_front({cx,cy,i,broken}) ;
                }

                if (a[cx][cy] == 1 && broken == 0 && d[cx][cy][i][1] > d[x][y][direct][broken] + (int) (i != direct)) {
                    d[cx][cy][i][1] = d[x][y][direct][broken] + (int) (i != direct);
                    if (i != direct) q.push_back({cx,cy,i,1}) ; else q.push_front({cx,cy,i,1}) ;
                }

            }
        }
    }
}

int f[maxN][maxN][4][2] , g[maxN][maxN][4][2] , res_1 = ooit , res_2 = ooit  , res_3 = 0 ;

void prepare() {
    bfs(L1,C1) ; forinc(i,1,n) forinc(j,1,n) forinc(k,0,3) forinc(t,0,1) f[i][j][k][t] = d[i][j][k][t] ;
    bfs(L2,C2) ; forinc(i,1,n) forinc(j,1,n) forinc(k,0,3) forinc(t,0,1) g[i][j][k][t] = d[i][j][k][t] ;
}

bool check(int u , int v) {
    int res = ooit ;
    forinc(i,0,3) forinc(j,0,3)  {
        res = min(res,f[u][v][i][1] + g[u][v][j][1] + (int) (abs(i-j) != 2)) ;
        if (res == res_2) return true ;
    }
    return false ;
}

void process() {
    prepare() ;
    forinc(i,0,3) res_1 = min(res_1,f[L2][C2][i][0]) , res_2 = min(res_2,min(res_1,f[L2][C2][i][1])) ;
    forinc(i,1,n) forinc(j,1,n) if (a[i][j] == 1 && check(i,j)) res_3 ++ ;
    cout << res_1 << " " << res_2 << " " << res_3 << endl ;
}

int main() {
    freopen("ROBOT.inp" , "r" , stdin) ;
    //freopen("ROBOT.out" , "w" , stdout) ;
    ios_base::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    enter() ;
    process() ;
    return 0 ;
}
