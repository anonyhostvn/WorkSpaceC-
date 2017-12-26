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
#define maxN 100005

template <class _T> bool maximize(_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize(_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

using namespace std ;

int n ;
vector<pii> a;

void enter () {
    //cin >> n ;
    scanf("%d" , &n) ;
    forinc(i,1,n) {
        int x , y ; //cin >>  x >> y ;
        scanf("%d%d" , &x , &y) ;
        a.push_back({x,y}) ;
    }
}

set<pii> h ;
bool dd[maxN] ;
pii b[maxN] ; int m = 0 ;

void prepare () {

    sort(a.begin() , a.end() , [] (pii a , pii b) {return (a.se < b.se) || (a.se == b.se && a.fi < b.fi) ; }) ;
    for (auto tmp : a) {
        while (!h.empty() && (*h.begin()).fi <= tmp.fi) h.erase(h.begin());
        h.insert( {tmp.fi , tmp.se} ) ;
    } a.clear()  ;
    while (!h.empty()) a.push_back((*h.begin())) , h.erase(h.begin()) ;

    sort(a.begin() , a.end() , [](pii a , pii b) { return (a.fi < b.fi) || (a.fi == b.fi && a.se < b.se) ; } ) ;
    for (auto tmp : a) {
        while (!h.empty() && (*h.begin()).fi <= tmp.se) h.erase(h.begin()) ;
        h.insert( {tmp.se , tmp.fi} ) ;
    } a.clear() ;
    while (!h.empty()) a.push_back({(*h.begin()).se , (*h.begin()).fi}) , h.erase(h.begin()) ;

    for (auto tmp : a) b[++m] = tmp ;
    sort(b+1 , b+1+m) ;
}

long long f[maxN] ;

void process () {
    prepare () ;
    forinc(i,0,m) f[i] =ooll ; f[1] = (long long) b[1].se * b[1].fi ; f[0] = 0 ;
    forinc(i,2,m) {
        minimize(f[i],f[i-1] + (long long) b[i].se * b[i].fi) ;
        forinc(j,1,i-1) minimize(f[i],f[j-1] + (long long) max(b[i].fi,b[j].fi) * max(b[i].se , b[j].se)) ;
    }
    cout << f[m] ;
}

int main () {
    freopen("PRINTERS.inp" , "r" , stdin) ;
    freopen("PRINTERS.out" , "w" , stdout) ;
    enter() ;
    process () ;
    return 0 ;
}
