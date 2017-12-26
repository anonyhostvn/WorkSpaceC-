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

template <class _T> bool maximize(_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize(_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

using namespace std ;

const int gox[4] = {-1 , 0 , 1 , 0 } ;
const int goy[4] = {0 , -1 , 0 , 1 } ;

int n , m , a[maxN][maxN] ;

void enter () {
    scanf("%d%d" , &n , &m) ;
    forinc(i,1,n) forinc(j,1,m) scanf("%d" , &a[i][j]) ;
}

typedef pair<int , pii> pipi ;

vector<pipi> p ;
bool dd[maxN][maxN] ;

void bfs(int xrot , int yrot) {
    queue<pii> q ;
    q.push({xrot,yrot}) ; dd[xrot][yrot] = true ;
    while (!q.empty()) {
        int x = q.front().fi , y = q.front().se ; q.pop() ;
        forinc(i,0,3) {
            int cx = x + gox[i] , cy = y + goy[i] ;
            if (cx > 0 && cy > 0 && cx <= n && cy <= m && !dd[cx][cy] && a[cx][cy] <= a[x][y]) dd[cx][cy] = true , q.push({cx,cy}) ;
        }
    }
}

bool cmp(pipi a , pipi b) {return a.fi > b.fi ; }

void process () {
    p.clear() ;
    forinc(i,1,n) forinc(j,1,m) p.push_back({a[i][j],{i,j}})  , dd[i][j] = false ;
    sort(p.begin() , p.end() , cmp) ;
    int res = 0 ;
    for (auto tmp : p) if (!dd[tmp.se.fi][tmp.se.se]) res ++ , bfs(tmp.se.fi,tmp.se.se) ;
    cout << res << endl ;
}

int main () {
    //freopen("Test.inp" , "r" , stdin) ;
    int t = 0 ; cin >> t  ;
    while (t--) enter() , process() ;
    return 0 ;
}
