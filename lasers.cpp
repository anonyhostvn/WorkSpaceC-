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
#define maxN 100005
#define oo 1000000000

using namespace std ;

struct node{
    int x , y , pos ;
};

int n ;
node a[maxN] , b[maxN] ;

int enter()
{
    cin >> n ;
    cin >> a[0].x >> a[0].y >> a[n+1].x >> a[n+1].y ;
    forinc(i,1,n) cin >> a[i].x >> a[i].y ;
    forinc(i,0,n+1) a[i].pos = i ;
    return 0 ;
}

bool cmp1(node a , node b)
{
    return (a.x < b.x) || ((a.x == b.x) && (a.y < b.y));
}

bool cmp2(node a , node b)
{
    return (a.y < b.y) || ((a.y == b.y) && (a.x < b.x)) ;
}

vector<int> ke[maxN] ;

int prepare()
{
    forinc(i,0,n+1) b[i] = a[i] ;
    sort(a,a+2+n,cmp1) ;
    forinc(i,1,n+1) if (a[i].x == a[i-1].x && a[i].y == a[i-1].y) continue ;
    else if (a[i].x == a[i-1].x) {
        int u = a[i].pos , v = a[i-1].pos ;
        ke[u].push_back(v) ;
        ke[v].push_back(u) ;
    }
    sort(a,a+2+n,cmp2) ;
    forinc(i,1,n+1) if (a[i].x == a[i-1].x && a[i].y == a[i-1].y) continue ;
    else if (a[i].y == a[i-1].y) {
        int u = a[i].pos , v = a[i-1].pos ;
        ke[u].push_back(v) ;
        ke[v].push_back(u) ;
    }
    return 0 ;
}

deque <pii> q ;
int d[maxN][2] ;

int bfs()
{
    q.push_back(mk(0,0)) ;
    q.push_back(mk(0,1)) ;
    forinc(i,0,n+1) forinc(j,0,1) d[i][j] = oo ; d[0][0] = 0 ; d[0][1] = 0 ;
    while (!q.empty()){
        pii tmp = q.front() ; q.pop_front() ;
        int u = tmp.fi , side = tmp.se ;
        forv(j,ke[u]) {
            int v = ke[u][j] , vside = (b[v].y == b[u].y) ? 1 : 0 , w = (vside == side) ? 0 : 1 ;
            if (d[v][vside] > d[u][side] + w) {
                d[v][vside] = d[u][side] + w ;
                if (w == 0) q.push_front(mk(v,vside)) ; else q.push_back(mk(v,vside)) ;
            }
        }
    }
    return 0 ;
}

int process()
{
    prepare()  ;
    bfs() ;
    cout << min(d[n+1][1],d[n+1][0]) ;
    return 0 ;
}

int main()
{
    freopen("lasers.in" , "r" , stdin) ;
    freopen("lasers.out" , "w" , stdout) ;
    enter() ;
    process() ;
    return 0 ;
}
