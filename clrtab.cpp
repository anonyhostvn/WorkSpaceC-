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

using namespace std ;

int n , m , c[maxN][maxN] ;

void enter() {
    cin >> m >> n ;
    forinc(i,1,m) forinc(j,1,n) cin >> c[i][j] ;
}

vector<pii> s ;
int a[maxN][maxN] , col[maxN] ;

bool cmp(pii a , pii b) {return a.fi > b.fi ; }

void build_() {
    memset(col , 0 , sizeof(col)) ; s.clear() ;
    forinc(i,1,m) forinc(j,1,n) col[c[i][j]] ++  ;
    forinc(i,1,n) if (col[i] > 0) s.push_back({col[i],i}) ;
    sort(s.begin() , s.end() , cmp) ;
}

struct node { int x , y , u , v  ; };

vector<node> ans ;
bool dd[maxN][maxN] ;

void process () {
    build_() ;
    forinc(i,1,n) {
        forinc(j,1,m) if (s.back().fi > 0) s.back().fi -- , a[j][i] = s.back().se ; else a[j][i] = s.front().se , s.front().fi -- ;
        sort(s.begin() , s.end() , cmp) ;
        while (s.back().fi == 0) s.pop_back() ;
    }

    memset(dd , 0 , sizeof(dd)) ;
    ans.clear() ;
    forinc(i,1,m) forinc(j,1,n) {

        if (a[i][j] != c[i][j]) {
            bool ok = false ;
            forinc(u,1,m) {
                forinc(v,1,n) if (!dd[u][v] && c[u][v] == a[i][j]) {
                    swap(c[u][v] , c[i][j]) ;
                    ans.push_back({i,j,u,v}) ;
                    ok = true ; break ;
                }
                if (ok) break  ;
            }
        }

        dd[i][j] = true ;
    }
    cout << ans.size() << endl ;
    for (auto tmp : ans) cout << tmp.x << " " << tmp.y << " " << tmp.u << " " << tmp.v << endl ;
}

int main() {
    freopen("CLRTAB.inp" , "r" , stdin) ;
    freopen("CLRTAB.out" , "w" , stdout) ;
    int t = 0 ; cin >> t ;
    forinc(i,1,t) enter () , process () ;
    return 0 ;
}
