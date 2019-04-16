#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; ++i )
#define fordec(i,a,b) for (int i = a ; i >= b ; --i )
#define forv(j,u) for (int j = 0 ; j < u.size() ; ++j)
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

using namespace std;

int fastRead() {
    int res = 0 ; char c ;
    for (c = getchar() ; c < '0' || c > '9' ; c = getchar()) ;
    for ( ; c >= '0' && c <= '9' ; c = getchar()) res *= 10 , res += c - '0' ;
    return res ;
}

#define maxN 200005

int n , m , q ;
vector<pii> ke[maxN] , black_edge ;

void enter () {
    n = fastRead() ; m = fastRead() ; q = fastRead() ;
    forinc(i,1,m) {
        int u = fastRead() , v = fastRead() , c = fastRead() ;
        ke[u].emplace_back(v,c) ; ke[v].emplace_back(u,c) ;
        black_edge.emplace_back(u,v) ;
    }
}

///____________________________________________________________________________________________________________________________________________________
///                                                         Loai bo canh den
///____________________________________________________________________________________________________________________________________________________

int lab[maxN] , cnt_lab = 0 ;
vector<int> nxt[maxN] ;

void dfs(int u , int cnt_lab) {
    lab[u] = cnt_lab ;
    for (auto v : ke[u]) if (v.se == 1 && !lab[v.fi]) dfs(v.fi,cnt_lab) ;
}

void remove_black_edge() {
    forinc(i,1,n) if (!lab[i]) dfs(i,++cnt_lab) ;
    for (auto tmp : black_edge){
        int u = tmp.fi , v = tmp.se ;
        if (lab[u] != lab[v]) nxt[lab[u]].emplace_back(lab[v]) , nxt[lab[v]].emplace_back(lab[u]) ;
    }
    n = cnt_lab ;
    cout << cnt_lab << endl ;
}

///____________________________________________________________________________________________________________________________________________________
///                                                 Tim khop va thanh phan song lien thong + Xay do thi + phan cac thanh phan lien thong trong do thi
///____________________________________________________________________________________________________________________________________________________

int num[maxN] , low[maxN] , cnt_ = 0 , Component_cout = 0 , Last_Comp[maxN] , comp[maxN] ;
bool Critical[maxN] ;
stack<int> st ;
vector<int> nxt_crit[maxN] ;

void visit(int u , int p , int id) {
    num[u] = low[u] = ++ cnt_ ; comp[u] = id ;
    int cnt_child = 0 ;

    for (auto v : nxt[u]) if (v != p) {
        if (num[v]) minimize(low[u],num[v]) ; else {
            st.push(u) ; visit(v,u,id) ; minimize(low[u],low[v]) ; cnt_child ++ ;

            if ((low[v] >= num[u] && p != -1) || (p == -1 && cnt_child > 1)) {
                Component_cout ++ ; Critical[u] = true ; int curr = 0 ;
                do {
                    curr = st.top() ; st.pop() ;
                    if (maximize(Last_Comp[curr] , Component_cout)) nxt_crit[curr].emplace_back(Component_cout) ;
                } while (curr != u) ;
            }
        }
    }
    st.push(u) ;
}

struct LCA_Tree {
    int f[maxN][20] , cnt_in[maxN] , cnt_out[maxN] , cnt  ;
    vector<int> nxt[maxN] ;

    void add_edge(int u , int v) {
        nxt[u].emplace_back(v) ;
        nxt[v].emplace_back(u) ;
    }

    void Dfs(int u , int p) {
        cnt_in[u] = ++cnt ;
        forinc(i,1,20) f[u][i] = f[f[u][i-1]][i-1] ;

        for (auto v : nxt[u]) if (v != p) f[v][0] = u , Dfs(v,u) ;
        cnt_out[u] = ++ cnt ;
    }

    void build_LCA(const int &snode) {
        forinc(i,1,snode) if (!cnt_in[i]) {
            f[i][0] = i ; Dfs(i,-1) ;
        }
    }

    bool anc(int u , int v) {return (cnt_in[u] <= cnt_in[v]) && (cnt_out[u] >= cnt_out[v]) ; }

    int LCA(int u , int v) {
        if (anc(u,v)) return u ;
        if (anc(v,u)) return v ;
        fordec(i,20,0) if (!anc(f[u][i],v)) u = f[u][i] ;
        return f[u][0] ;
    }
} tree ;

int match_bi_conect[maxN] , match_crit[maxN] , cnt_node = 0 , corress[maxN] ;

void Build_New_Graph() {
    //visit(1,-1) ;
    int cnt_comp = 0 ;
    forinc(i,1,n) if (!num[i]) visit(i,-1,++cnt_comp) ;
    ++Component_cout ;
    while (!st.empty()) {
        int u = st.top() ; st.pop() ;
        if (maximize(Last_Comp[u],Component_cout))
            nxt_crit[u].emplace_back(Component_cout) ;
    }

    forinc(i,1,n) if (Critical[i])
        for (auto u : nxt_crit[i]) {
            if (!match_crit[i]) match_crit[i] = ++cnt_node ;
            if (!match_bi_conect[u]) match_bi_conect[u] = ++cnt_node ;
            tree.add_edge(match_crit[i],match_bi_conect[u]) ;
        }

    forinc(i,1,n)
        if (Critical[i]) corress[i] = match_crit[i] ; else corress[i] = match_bi_conect[nxt_crit[i][0]] ;
    tree.build_LCA(cnt_node) ;
}

///___________________________________________________________________________________________________________________________________________________________
///                                                 Xu ly truy van
///___________________________________________________________________________________________________________________________________________________________

string no_sol = "No" , _sol = "Yes" ;

bool check_in_path(int a , int b , int c) {
    if (b == c || a == c) return true ;
    if (!Critical[c]) return false ;
    a = corress[a] ; b = corress[b] ; c = corress[c] ;

    int p = tree.LCA(a,b) ;
    if (tree.anc(p,c) && (tree.anc(c,a) || tree.anc(c,b))) return true ;
    return false ;
}

string solve(int a , int b , int c , int d) {
    if (comp[a] != comp[b]) return no_sol ;
    if (comp[c] != comp[d]) return _sol ;
    if (c == d) return no_sol ;
    if (a == b) return _sol ;

    if (!check_in_path(a,b,c)) return _sol ;
    if (!check_in_path(a,b,d)) return _sol ;
    return no_sol ;
}

///___________________________________________________________________________________________________________________________________________________________
///                                                 Xu Ly
///___________________________________________________________________________________________________________________________________________________________

void process () {
    remove_black_edge() ;
    Build_New_Graph() ;

    int res = 0 ;

    while (q--) {
        int a = fastRead() , b = fastRead() , c = fastRead() , d = fastRead() ;
        cout << solve(lab[a],lab[b],lab[c],lab[d]) << endl ;
    }
}

int main () {
    freopen("input.txt" , "r" , stdin) ;
    freopen("TWOPATHS.out" , "w" , stdout) ;
    enter () ;
    process () ;
    return 0 ;
}
