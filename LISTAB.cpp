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

int n , m ;
pii a[maxN * maxN] ;

int convert_coord(int x , int y ) {return x * n + y ; }
pii swap_coord(int x) {return {x / n  , x % n} ; }

void enter() {
    cin >> m >> n ;
    forinc(i,0,m-1) forinc(j,0,n-1) cin >> a[i * n + j].fi ;
    forinc(i,0,m*n-1) a[i].se = i ;
}

int gox[4] = {-1 , 1 , 0 , 0} ;
int goy[4] = {0 , 0 , -1 , 1} ;
int f[maxN * maxN] , pos[maxN * maxN];

void process() {
    sort(a,a+m*n) ;
    forinc(i,0,m*n-1) pos[a[i].se] = i ;
    forinc(i,0,m*n-1) f[i] = 1 ;
    forinc(i,0,m*n-1) {
        pii tmp = swap_coord(a[i].se) ;
        forinc(j,0,3) {
            int cx = tmp.fi + gox[j] , cy = tmp.se + goy[j] ;
            if (cx >= 0 && cy >= 0 && cx < m && cy < n) {
                int cid = convert_coord(cx,cy) ;
                if (a[pos[cid]].fi < a[i].fi) f[i] = max(f[i],f[pos[cid]] + 1) ;
            }
        }
    }
    int res = 0 ;
    forinc(i,0,m*n-1) res = max(res,f[i]) ;
    cout << res << endl ;
}

int main() {
    freopen("LISTAB.inp" , "r" , stdin) ;
    freopen("LISTAB.out" , "w" , stdout) ;
    enter() ;
    process() ;
    return 0 ;
}
