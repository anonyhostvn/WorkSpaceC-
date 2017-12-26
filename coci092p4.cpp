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
#define maxN 505

using namespace std ;

const int gox[4] = {-1 , 1 , 0 , 0} ;
const int goy[4] = {0 , 0 , -1 , 1} ;

int m , n , a[maxN][maxN] , xrot , yrot , xend , yend ;

void enter() {
    cin >> n >> m ;
    forinc(i,1,n) forinc(j,1,m) {
        char ch ; cin >> ch ; if (ch == '+') a[i][j] = 1 ;
        if (ch == 'V') xrot = i , yrot = j; else if (ch == 'J') xend = i , yend = j ;
    }
}

int dist_tree[maxN][maxN] ;

void build_() {
    queue<pii> q ;
    forinc(i,1,n) forinc(j,1,m) {
        dist_tree[i][j] = -1 ;
        if (a[i][j] == 1) q.push({i,j}) , dist_tree[i][j] = 0  ;
    }
    while (!q.empty()) {
        pii tmp = q.front() ; q.pop() ;
        int u = tmp.fi , v = tmp.se ;
        forinc(i,0,3) {
            int cx = u + gox[i] , cy = v + goy[i] ;
            if (cx >= 1 && cy >= 1 && cx <= n && cy <= m && dist_tree[cx][cy] == -1) dist_tree[cx][cy] = dist_tree[u][v] + 1 , q.push({cx,cy}) ;
        }
    }
}

int d[maxN][maxN] ;

bool bfs(int minest, int xrot , int yrot , int xend , int yend) {
    queue<pii> q ;
    if (dist_tree[xrot][yrot] < minest) return false ;
    if (dist_tree[xend][yend] < minest) return false ;
    forinc(i,1,n) forinc(j,1,m) d[i][j] = -1 ; d[xrot][yrot] = 0 ; q.push({xrot,yrot}) ;
    while (!q.empty()) {
        pii tmp = q.front() ; q.pop() ;
        int u = tmp.fi , v = tmp.se ;
        forinc(i,0,3) {
            int cx = u + gox[i] , cy = v + goy[i] ;
            if (cx >= 1 && cy >= 1 && cx <= n && cy <= m && dist_tree[cx][cy] >= minest && d[cx][cy] == -1) {
                d[cx][cy] = d[u][v] + 1 ;
                q.push({cx,cy}) ;
            }
        }
    }
    return d[xend][yend] > -1 ;
}

void process() {
    build_() ;
    int l = 0 , r = m * n , res = 0 ;
    while (l <= r) {
        int mid = (l+r) / 2 ;
        if (bfs(mid,xrot,yrot,xend,yend)) {
            l = mid + 1 ; res = mid ;
        } else r = mid - 1 ;
    }
    cout << res << endl ;
}

int main() {
    //freopen("coci092p4.inp" , "r" , stdin) ;
    enter() ;
    process() ;
    return 0 ;
}
