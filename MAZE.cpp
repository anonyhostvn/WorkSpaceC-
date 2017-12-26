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
#define maxN 105

using namespace std;

int n , m ,k , a[maxN][maxN] , xrot  = 0 , yrot = 0 , xfi = 0 , yfi = 0 ;

void enter()
{
    cin >> m >> n >> k ;
    cin >> xrot >> yrot >> xfi >> yfi ;
    forinc(i,1,m) forinc(j,1,n) cin >> a[i][j] ;
}

struct node {
    int x , y , smine ;
    node (int a , int b , int c) {
        x = a ; y = b ; smine = c ;
    }
};

int d[maxN][maxN][4] ;

int gox[4] = {0 , -1 , 0 , +1} ;
int goy[4] = {+1, 0  ,-1 ,  0} ;

int get_bit(int x , int i) {return (x >> i) & 1 ; }

void bfs()
{
    deque<node> q ;
    forinc(i,1,m) forinc(j,1,n) forinc(s,0,3) d[i][j][s] = oo ;
    q.push_back(node(xrot,yrot,k)) ; d[xrot][yrot][k] = 0;
    while (!q.empty()) {
        int x = q.front().x , y = q.front().y , s = q.front().smine ; q.pop_front() ;
        forinc(i,0,3) {
            int cx = x + gox[i] , cy = y + goy[i] ;
            if (cx <= m && cy <= n && cx >= 1 && cy >= 1) {
                int w = 0 ;
                if (i % 2 == 0 && (get_bit(a[x][y],i) == 1 || get_bit(a[cx][cy],2-i) == 1)) w = 1 ;
                else if (i % 2 != 0 && (get_bit(a[x][y],i) == 1 || get_bit(a[cx][cy],4-i) == 1)) w = 1 ;
                if (s-w >= 0 && d[cx][cy][s-w] > d[x][y][s] + 1) {
                    d[cx][cy][s-w] = d[x][y][s] + 1 ;
                    if (w == 0) q.push_front(node(cx,cy,s-w)) ; else q.push_back(node(cx,cy,s-w)) ;
                }
            }
        }
    }
}

void process()
{
    bfs() ;
    int res = oo ;
    forinc(i,0,3) res = min(res,d[xfi][yfi][i]) ;
    cout << res << endl ;
}

int main()
{
    freopen("MAZE.inp" , "r" , stdin) ;
    //freopen("MAZE.out" , "w" , stdout) ;
    enter()  ;
    process() ;
    return 0 ;
}
