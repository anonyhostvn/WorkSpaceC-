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
#define maxN 200005

using namespace std ;

struct node {
    int u , v , pos ;
    node (int a , int b , int c){
        u = a ; v = b ; pos = c ;
    }
};
int n , m , k , lab[maxN] ;
vector<node> a[2] ;

void enter()
{
    cin >> n >> m >> k ;
    forinc(i,1,m) {
        int  u , v , c ; cin >> u >> v >> c ;
        a[c].push_back(node(u,v,i)) ;
    }
}

int get_root(int u)
{
    if (u == lab[u]) return u ;
    lab[u] = get_root(lab[u]) ;
    return lab[u] ;
}

void uni(int u , int v){lab[lab[u]] = lab[v] ; }

void reset() { forinc(i,1,n) lab[i] = i ; }

bool check_com() {forinc(i,1,n) if (get_root(i) != get_root(1)) return false ; return true; }

bool import[maxN] ;

int prepare()
{
    int cnt = 0 ;
    reset() ;
    forv(i,a[1]) if (get_root(a[1][i].u) != get_root(a[1][i].v)) uni(a[1][i].u,a[1][i].v) , cnt ++ ;
    if (cnt < k) return -1 ;
    cnt = 0 ;
    forv(i,a[0]) if (get_root(a[0][i].u) != get_root(a[0][i].v)) uni(a[0][i].u,a[0][i].v) , cnt ++ , import[i] = true ;
    if (!check_com()) return -1 ;
    return cnt ;
}

vector<int> ans ;

void process()
{
    int c = prepare() ;
    if (c == -1) { cout << -1 ; return  ; }
    reset() ;
    forv(i,a[0]) if (import[i]) uni(a[0][i].u,a[0][i].v) ;
    int cnt = 0 ;
    forv(i,a[0])
        if (!import[i] && cnt < n-1-k-c && get_root(a[0][i].u) != get_root(a[0][i].v)) uni(a[0][i].u,a[0][i].v) , import[i] = true , cnt ++ ;
    if (cnt < n-1-c-k) {cout << -1 ; return ; }
    forv(i,a[0]) if (import[i]) ans.push_back(a[0][i].pos) ;
    forv(i,a[1]) if (get_root(a[1][i].u) != get_root(a[1][i].v)) uni(a[1][i].u,a[1][i].v) , ans.push_back(a[1][i].pos) ;
    forv(i,ans) cout << ans[i] << " " ;
}

int main()
{
    freopen("ROADS.inp" , "r" , stdin) ;
    freopen("ROADS.out" , "w" , stdout) ;
    enter() ;
    process() ;
    return 0 ;
}
