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

int n  , deg[2 * maxN][2 * maxN] ;
bool is_connect[2 * maxN][2 * maxN][4] , dd[2 * maxN] [2 * maxN] ;

///len tren 0
///sang phai 1
/// xuong duoi 2
///sang trai 3

const int gox[4] = {-1 , 0 , +1 , 0} ;
const int goy[4] = { 0 ,+1 ,  0 ,-1} ;

void add_row(int r , int t1 , int t2) {
    forinc(i,t1,t2-1) if (!is_connect[r][i][1]) deg[r][i] ++ , is_connect[r][i][1] = true ;
    fordec(i,t2,t1+1) if (!is_connect[r][i][3]) deg[r][i] ++ , is_connect[r][i][3] = true ;
    forinc(i,t1,t2) dd[r][i] = true ;
}

void add_col(int c , int t1 , int t2) {
    forinc(i,t1,t2) dd[i][c] = true ;
    forinc(i,t1,t2-1) if (!is_connect[i][c][2]) deg[i][c] ++ , is_connect[i][c][2] = true ;
    fordec(i,t2,t1+1) if (!is_connect[i][c][0]) deg[i][c] ++ , is_connect[i][c][0] = true ;
}

void enter() {
    cin >> n ;
    forinc(i,1,n) {
        int x , y , u ,v ; cin >> x >> y >> u >> v ;
        x += 1000 ; y += 1000 ; u += 1000 ; v += 1000;
        if (x == u) add_row(x,min(y,v),max(y,v)) ; else add_col(y,min(x,u),max(x,u)) ;
    }
}

bool vis[2 * maxN][2 * maxN] ;

int bfs(int xrot , int yrot) {
    queue<pii> q ; int cnt = 0 ;
    q.push({xrot,yrot}) ; vis[xrot][yrot] = true ;

    while (!q.empty()) {
        pii tmp = q.front() ; q.pop() ;
        int x = tmp.fi , y = tmp.se ;
        cnt += (int) (deg[x][y] % 2 != 0) ;
        forinc(i,0,3) if (is_connect[x][y][i]) {
            int cx = x + gox[i] , cy = y + goy[i] ;
            if (!vis[cx][cy]) vis[cx][cy] = true , q.push({cx,cy}) ;
        }
    }

    return (cnt == 0) ? 1 : cnt / 2 ;
}

void process () {
    int res = 0 ;
    forinc(i,0,2000) forinc(j,0,2000) if (dd[i][j] && !vis[i][j]) res += bfs(i,j) ;
    cout << res << endl ;
}

int main() {
    freopen("ARCHI.inp" , "r" , stdin) ;
    freopen("ARCHI.out" , "w" , stdout) ;
    enter() ;
    process () ;
    return 0 ;
}
