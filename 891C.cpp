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
#define pli pair<long long , int>

template <class _T> bool maximize(_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize(_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

const int ooit = 2e9 ;
const long long ooll = 1e15 ;

using namespace std ;

#define maxN 500005

int n , m , q ;
vector<pii> Tedge[maxN] , query[maxN] ;
struct node {
    int u , v , c ;
} Pedge[maxN] ;

int fastRead() {
    char c ; int res = 0 ;
    for (c = getchar() ; c < '0' || c > '9' ; c = getchar()) ;
    for ( ; c >= '0' && c <= '9' ; c = getchar()) res*= 10 , res += c - '0' ;
    return res ;
}

void enter () {
    n = fastRead() ; m = fastRead() ;
    forinc(i,1,m) {
        int u = fastRead() , v = fastRead()  , c = fastRead() ;
        Tedge[c].push_back({u,v}) ;
        Pedge[i] = {u,v,c}  ;
    }
    q = fastRead() ;
    forinc(i,1,q) {
        int k = fastRead() ;
        forinc(se,1,k) {
            int id = fastRead() ;
            query[Pedge[id].c].push_back({i,id}) ;
        }
    }
}

int lab[maxN] , vir_lab[maxN] , T = 0 , dd[maxN] ;

int get_root(int u) {
    return (lab[u] == u) ? lab[u] : (lab[u] = get_root(lab[u]) , lab[u]) ;
}

void Uni(int u , int v) {
    lab[get_root(u)]  = get_root(v) ;
}

int get_vir_root(int u) {
    if (maximize(dd[u],T)) vir_lab[u] = lab[u] ;
    return (vir_lab[u] == u) ? u : (vir_lab[u] = get_vir_root(vir_lab[u]), vir_lab[u]) ;
}

void Uni_vir(int u , int v) {
    vir_lab[get_vir_root(u)] = get_vir_root(v) ;
}

int ans[maxN] ;

void process () {
    forinc(i,1,n) lab[i] = i ;

    forinc(i,1,500000) if (query[i].size() > 0 || Tedge[i].size() > 0) {
        sort(query[i].begin()  , query[i].end()) ;

        if (query[i].size() > 0) forinc(j,0,query[i].size()-1) {
            if (j == 0 || query[i][j].fi != query[i][j-1].fi) T++ ;
            int id = query[i][j].se , u = Pedge[id].u , v = Pedge[id].v ;
            if (get_vir_root(u) == get_vir_root(v)) ans[query[i][j].fi] = 1 ;
            Uni_vir(u,v) ;
        }

        for (auto tmp : Tedge[i]) Uni(tmp.fi , tmp.se) ;
    }

    forinc(i,1,q) cout << (ans[i] ? "NO" : "YES") << endl ;
}

int main () {
    //freopen("891C.inp" , "r" , stdin) ;
    enter () ;
    process () ;
    return 0 ;
}
