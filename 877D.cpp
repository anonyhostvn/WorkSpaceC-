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
#define oo (int) 1e9 + 7
#define maxN 1005

using namespace std ;

int n , m , k , a[maxN][maxN] , xrot , yrot , xfi , yfi ;

void enter()
{
    cin >> n >> m >> k ;
    forinc(i,1,n) forinc(j,1,m) {
        char ch ; cin >> ch ;
        if (ch == '#') a[i][j] = 1 ;
    }
    cin >> xrot >> yrot >> xfi >> yfi ;
}

set<int> trow_nxt[maxN] , tcol_nxt[maxN] ;
set<int , greater<int> > trow_prev[maxN] , tcol_prev[maxN] ;
set<int> :: iterator it_nxt ;
set<int , greater<int> > :: iterator it_prev ;

void prepare()
{
    forinc(i,1,n)
        forinc(j,1,m) trow_nxt[i].insert(j) , tcol_nxt[j].insert(i) , trow_prev[i].insert(j) , tcol_prev[j].insert(i) ;
}

void update(int x , int y)
{
    trow_nxt[x].erase(y) ; trow_prev[x].erase(y) ;
    tcol_nxt[y].erase(x) ; tcol_prev[y].erase(x) ;
}

int d[maxN][maxN] ;
queue<pii> q ;

void up_bfs(int x , int y)
{
    it_prev = trow_prev[x].upper_bound(y) ;
    while (it_prev != trow_prev[x].end() && abs((*it_prev) - y) <= k) {
        int cx = x , cy = (*it_prev) ;
        if (a[cx][cy] == 1) break ;
        if (d[cx][cy] > d[x][y] + 1) {
            d[cx][cy] = d[x][y] + 1 , q.push(mk(cx,cy)) ;
            update(cx,cy) ; it_prev = trow_prev[x].upper_bound(y) ;
        }
    }
    it_nxt = trow_nxt[x].upper_bound(y) ;
    while (it_nxt != trow_nxt[x].end() && abs((*it_nxt) - y) <= k) {
        int cx = x , cy = *it_nxt ;
        if (a[cx][cy] == 1) break ;
        if (d[cx][cy] > d[x][y] + 1) {
            d[cx][cy] = d[x][y] + 1 ; q.push(mk(cx,cy)) ;
            update(cx,cy) ; it_nxt = trow_nxt[x].upper_bound(y) ;
        }
    }
    it_prev = tcol_prev[y].upper_bound(x) ;
    while (it_prev != tcol_prev[y].end() && abs((*it_prev) - x) <= k) {
        int cx = *it_prev , cy = y ;
        if (a[cx][cy] == 1) break ;
        if (d[cx][cy] > d[x][y] + 1) {
            d[cx][cy] = d[x][y] + 1 ; q.push(mk(cx,cy)) ;
            update(cx,cy) ; it_prev = tcol_prev[y].upper_bound(x) ;
        }
    }
    it_nxt = tcol_nxt[y].upper_bound(x) ;
    while (it_nxt != tcol_nxt[y].end() && abs((*it_nxt) - x) <= k) {
        int cx = *it_nxt , cy =y ;
        if (a[cx][cy] == 1) break ;
        if (d[cx][cy] > d[x][y] + 1) {
            d[cx][cy] = d[x][y] + 1 ; q.push(mk(cx,cy)) ;
            update(cx,cy) ; it_nxt = tcol_nxt[y].upper_bound(x) ;
        }
    }
}

void bfs()
{
    forinc(i,1,n) forinc(j,1,m) d[i][j] = oo ;
    d[xrot][yrot] = 0 ; q.push(mk(xrot,yrot)) ; update(xrot,yrot) ;
    while (!q.empty()) {
        int x = q.front().fi , y = q.front().se ; q.pop() ;
        up_bfs(x,y) ;
    }
}

void process()
{
    prepare() ;
    bfs() ;
    if (d[xfi][yfi] < oo) cout << d[xfi][yfi] << endl ; else cout << -1 << endl ;
}

int main()
{
    //freopen("877D.inp" , "r" , stdin) ;
    enter() ;
    process() ;
    return 0 ;
}
