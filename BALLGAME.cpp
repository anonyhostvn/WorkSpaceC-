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
#define oo (int) 1e9
#define maxN 205

using namespace std ;

pii bal[maxN] ;
bool forbi[maxN][maxN] , sub2 = false;
int n , m ;

void enter()
{
    cin >> n ;
    forinc(i,1,n) {
        int u , v ; cin >> u >> v ;
        if (u <= 100 && v <= 100) forbi[u][v] = true ;
    }
    cin >> m ;
    forinc(i,1,m) {
        cin >> bal[i].fi >> bal[i].se ;
        if (bal[i].fi > 100 || bal[i].se > 100) sub2 = true ;
    }
}

bool dd[maxN][maxN]  ;
int d[maxN][maxN] , dbal[maxN][maxN][maxN] ;

int gox[4] = {0 , 0 , -1 , 1} ;
int goy[4] = {-1 , 1 , 0 , 0} ;

void bfs(int xrot , int yrot)
{
    forinc(i,0,101) forinc(j,0,101) d[i][j] = -1  ;
    queue<pii> q ; d[xrot][yrot] = 0 ;q.push(mk(xrot,yrot)) ;
    while (!q.empty()) {
        pii tmp = q.front() ; q.pop() ;
        int x = tmp.fi , y = tmp.se ;
        forinc(i,0,3) {
            int cx = x + gox[i] , cy = y + goy[i] ;
            if (cx >= 0 && cy >= 0 && cx <= 101 && cy <= 101 && d[cx][cy] == -1 && !forbi[cx][cy]) d[cx][cy] = d[x][y] + 1 , q.push(mk(cx,cy)) ;
        }
    }
}

void sub_1()
{
    forinc(i,1,m) {
        bfs(bal[i].fi,bal[i].se) ;
        forinc(u,0,101) forinc(v,0,101) dbal[i][u][v] = d[u][v] ;
    }
    int res = oo ;
    forinc(i,0,101) forinc(j,0,101) if (!forbi[i][j]) {
        int tmp = 0 ;
        forinc(k,1,m) if (dbal[k][i][j] > -1) tmp += dbal[k][i][j] ;
        else {tmp = oo ; break ;}
        res = min(res,tmp) ;
    }
    if (res < oo) cout << res << endl ; else cout << -1 << endl ;
}

bool cmp(pii a , pii b) {return a.se < b.se ; }

void sub_2()
{
    sort(bal+1,bal+1+m) ;
    int x = bal[m/2+1].fi ;
    sort(bal+1,bal+1+m,cmp) ;
    int y = bal[m/2+1].se ;
    long long res =0 ;
    forinc(i,1,m) res += abs(bal[i].fi-x) + abs(bal[i].se-y) ;
    cout << res << endl ;
}

void process()
{
    if (sub2) sub_2() ; else sub_1()  ;
}

int main()
{
    freopen("BALLGAME.inp" , "r" , stdin) ;
    freopen("BALLGAME.out" , "w" , stdout) ;
    enter() ;
    process() ;
    return 0 ;
}
