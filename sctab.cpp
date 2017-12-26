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
#define maxN 105
#define maxM 15


using namespace std ;

int n , m , s , a[maxN][15] ;

void enter()
{
    cin >> m >> n >> s ;
    forinc(i,1,m) forinc(j,1,n) cin >> a[i][j] ;
}

int id = 0 ;
vector<int> qur;

void query_install(){
    int query[maxN] ; bool dd[maxM] ;
    forinc(i,1,n) dd[i] = false ;
    forinc(i,1,s) cin >> query[i] ;
    fordec(i,s,1) if (!dd[query[i]]) qur.push_back(query[i])  , dd[query[i]] = true ;
    s = qur.size() ;
}

pii b[maxN] ;

bool cmp(pii x , pii y) {return a[x.fi][id] < a[y.fi][id] || (a[x.fi][id] == a[y.fi][id] && x.se < y.se) ; }

void prepare() {
    s = qur.size() ;
    forinc(i,1,m) b[i].fi = i , b[i].se = i ;
    fordec(i,qur.size() -1 , 0) {
        id = qur[i] ; sort(b+1,b+1+m,cmp) ;
        forinc(i,1,m) b[i].se = i ;
    }
}

pii c[maxN] ;
vector<int> ans ;

bool check() {forinc(i,1,m) if (b[i].fi != c[i].fi) return false ; return true ; }

int solve_res() {
    int res = oo ;
    vector<int> X ; forinc(i,1,n) X.push_back(i) ;
    do {
        forinc(i,1,m) c[i].fi = i ;
        if (check()) return 0 ;
        vector<int> temp ;
        forv(i,X) if (i + 1 > s || i + 1 >= res) break ; else {
            temp.push_back(X[i]) ;
            forinc(i,1,m) c[i].se = i ;
            id = X[i] ; sort(c+1,c+1+m,cmp) ;
            if (check() && res > i + 1) {
                res = min(res,i + 1) ;
                ans = temp ;
            }
        }
    } while (next_permutation(X.begin(),X.end())) ;
    return res ;
}

void process() {
    query_install() ;
    prepare() ;
    int res = solve_res() ;
    cout << res << endl ;
    if (res > 0) forv(i,ans) cout << ans[i] << " " ;
}

int main()
{
    freopen("sctab.inp" , "r" , stdin) ;
    //freopen("sctab.out" , "w" , stdout) ;
    ios_base::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    enter() ;
    process() ;
    return 0 ;
}
