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
#define oo 1e9 + 7
#define maxN 105

using namespace std ;

int n , m ;
pii a[maxN] , b[maxN] ;

void enter()
{
    cin >> n ;
    forinc(i,1,n) cin >> a[i].fi >> a[i].se ;
    cin >> m ;
    forinc(i,1,m) cin >> b[i].fi >> b[i].se ;
}

double length(pii a , pii b) {return sqrt((a.fi - b.fi) * (a.fi - b.fi) + (a.se - b.se) * (a.se-b.se)) ; }

int ccw(pii a , pii b , pii c)
{
    pii vect_1 , vect_2 ;
    vect_1.fi = b.fi - a.fi ; vect_1.se = b.se - a.se ;
    vect_2.fi = c.fi - b.fi ; vect_2.se = c.se - b.se ;
    int tmp =  (vect_1.fi * vect_2.se - vect_1.se * vect_2.fi) ;
    if (tmp == 0) return 0 ; else if (tmp > 0)  return 1 ; else return -1 ;
}

bool check_edge(pii a_1 , pii a_2)
{
    int tmp = 0 ;
    forinc(i,1,n) if (ccw(a_1,a_2,a[i]) == 0) return false ;
    forinc(i,1,n) if (ccw(a_1,a_2,a[i]) != ccw(a_1,a_2,a[1])) return false  ;
    return true ;
}

vector<pair<int, pair<double,int> > >  ke[maxN] ;

void build_graph()
{
    int cnt = 0 ;
    forinc(i,1,m-1) forinc(j,i+1,m) if (check_edge(b[i],b[j]))
        ke[i].push_back(mk(j,mk(length(b[i],b[j]),++cnt))) , ke[j].push_back(mk(i,mk(length(b[i],b[j]),cnt))) ;
}

double d[maxN] ;

double sol(int root , int fsh , int id)
{
    priority_queue<pair<double,int> >  q ;
    forinc(i,1,m) d[i] = oo ;
    d[root] = 0 ; q.push(mk(d[root],root)) ;
    while (!q.empty()) {
        pii tmp = q.top() ; q.pop();
        int u = tmp.se  ;
        forv(i,ke[u]) if (ke[u][i].se.se != id && d[ke[u][i].fi] > (double) d[u] + ke[u][i].se.fi) {
            d[ke[u][i].fi] = d[u] + ke[u][i].se.fi ;
            q.push(mk(-d[ke[u][i].fi],ke[u][i].fi)) ;
        }
    }
    return d[fsh] ;
}

void process()
{
    build_graph() ;
    double res = oo ;
    forinc(i,1,m) forv(j,ke[i]) res = min(res,ke[i][j].se.fi + sol(i,ke[i][j].fi,ke[i][j].se.se)) ;
    cout << setprecision(2) << fixed << res << endl ;
}

int main()
{
    freopen("MINPERIM.inp" , "r" , stdin) ;
    freopen("MINPERIM.out" , "w" , stdout) ;
    enter() ;
    process() ;
    return 0 ;
}
