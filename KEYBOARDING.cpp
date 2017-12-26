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
#define maxN 55
#define maxM 10005

template <class _T> bool maximize(_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize(_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

using namespace std ;

int r , c , keyboard[maxN][maxN] , n , a[maxM] ;
string st ;

void enter () {
    cin >> r >> c ;
    forinc(i,1,r) forinc(j,1,c) {
        char ch ; cin >> ch ;
        if ((int) ch == 42) keyboard[i][j] = -1 ; else keyboard[i][j] = (int) ch  - (int) 'A' ;
    }

    cin >> st ; n = st.length() ;

    forinc(i,1,n) a[i] = (int) st[i-1] - (int) 'A' ; a[++n] = -1 ;
}

struct node {
    int x , y , pos ;
};

const int gox[4] = {-1 , 0 , +1 , 0} ;
const int goy[4] = {0  , +1 , 0 , -1} ;

pii nxt[4][maxN][maxN] ;

void prepare () {
    forinc(i,1,r) forinc(j,1,c) forinc(k,0,3) {
        nxt[k][i][j] = {ooit , ooit} ;
        int cx = i , cy = j ;
        while (true) {
            cx += gox[k] ; cy += goy[k] ;
            if (cx < 1 || cy < 1 || cx > r || cy > c) break ;
            if (keyboard[cx][cy] != keyboard[i][j]) {nxt[k][i][j] = {cx,cy} ; break ; }
        }
    }
}

queue<node> q ;
int d[maxN][maxN][maxM] ;

void bfs() {
    forinc(i,1,r) forinc(j,1,c) forinc(k,0,n) d[i][j][k] = ooit ;
    d[1][1][(int) (keyboard[1][1] == a[1])] = (int) (keyboard[1][1] == a[1]) ;
    q.push({1,1,(int) keyboard[1][1] == a[1]}) ;

    while (!q.empty()) {
        node tmp = q.front() ; q.pop() ;
        int x = tmp.x , y = tmp.y , pos = tmp.pos  ;

        if (pos < n && a[pos+1] == keyboard[x][y] && d[x][y][pos+1] == ooit) {
            d[x][y][pos+1] = d[x][y][pos] +1 ;
            q.push({x,y,pos+1}) ;
        }

        forinc(i,0,3) if (nxt[i][x][y].fi < ooit) {
            int cx = nxt[i][x][y].fi , cy = nxt[i][x][y].se ;
            if (d[cx][cy][pos] == ooit) {
                d[cx][cy][pos] = d[x][y][pos] + 1 ;
                q.push({cx,cy,pos}) ;
            }
        }

    }
}

void process () {
    prepare() ;
    bfs() ;
    int res =  ooit ;
    forinc(i,1,r) forinc(j,1,c) minimize(res,d[i][j][n]) ;
    cout << res << endl ;
}

int main () {
    freopen("KEYBOARDING.inp" , "r" , stdin) ;
    //freopen("KEYBOARDING.out" , "w" , stdout) ;
    enter () ;
    process () ;
    return 0 ;
}
