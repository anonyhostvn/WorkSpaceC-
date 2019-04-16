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

template <class _T> bool maximize(_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize(_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

const int ooit = 2e9 ;
const long long ooll = 1e15 ;

using namespace std ;

int fastRead() {
    int res = 0 ; char c ;
    for (c = getchar() ; c < '0' || c > '9' ; c = getchar()) ;
    for (c = getchar() ; c >= '0' && c <= '0' ; c = getchar()) res *= 10 , res += c - '0' ;
}

#define maxM 200005
#define maxN 200005

int n , m ;
vector<pii> ke[maxN] , black_edge ;

void enter () {
    n = fastRead() ; m = fastRead() ;
    forinc(i,1,m) {
        int u = fastRead() , v = fastRead() , c = fastRead() ;
        ke[u].emplace_back(v,c) ; ke[v].emplace_back(u,c) ;
        if (c == 0) black_edge.emplace_back(u,v) ;
    }
}

///____________________________________________________________________________________________________________________________________________
///                                                           Loai Cac Canh Trang
///____________________________________________________________________________________________________________________________________________

bool vis[maxN] ; int lab[maxN] ;

void dfs(int u , int cnt_comp) {
    vis[u] = true ; lab[u] = cnt_comp ;
    for (auto v : ke[u]) if (!vis[v.fi] && v.se == 1) dfs(v.fi , cnt_comp) ;
}

vector<int> nxt[maxN] ;

void remove_white_edge() {
    int cnt_comp = 0 ;
    forinc(i,1,n) if (!vis[i]) dfs(i,++cnt_comp) ;

    for (auto tmp : black_edge) if (lab[tmp.fi] != lab[tmp.se]) nxt[tmp.fi].emplace_back(tmp.se) , nxt[tmp.se].emplace_back(tmp.fi) ;
}

///____________________________________________________________________________________________________________________________________________
///
///____________________________________________________________________________________________________________________________________________

///____________________________________________________________________________________________________________________________________________
///____________________________________________________________________________________________________________________________________________

int main () {
    return 0 ;
}
