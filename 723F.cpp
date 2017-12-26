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
#define maxM 400005
#define maxN 200005

template <class _T> bool maximize(_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize(_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

using namespace std ;

int n , m , S , T , dS , dT ;
pii edge[maxM] ;

void enter () {
    cin >> n >> m ;
    forinc(i,1,n) cin >> edge[i].fi >> edge[i].se ;
    cin >> S >> T >> dS >> dT ;
}

int lab[maxN] ;

int get_root(int u) {
    if (u == lab[u]) return u ;
    lab[u] = get_root(lab[u]) ;
    return lab[u] ;
}

void uni(int u , int v) {lab[get_root(u)] = get_root(v) ; get_root(u) ; }

bool dd[maxN] , edge_toS[maxN] , edge_toT[maxN] ;
int edge_from_S_to_T = 0 , to_S[maxN] , to_T[maxN] ;
vector<int> comp_S , comp_T , comp_ST , comp_not_ST , comp , ans ;

void prepare () {
    forinc(i,1,n) lab[i] = i ;
    forinc(i,1,m)
    if (edge[i].fi != S && edge[i].fi != T && edge[i].se != S && edge[i].se != T && get_root(edge[i].fi) != get_root(edge[i].se))
        uni(edge[i].fi,edge[i].se) , ans.push_back(i) ;
    else if ((edge[i].fi == S && edge[i].se == T) || (edge[i].fi == T && edge[i].se == S)) edge_from_S_to_T = i  ;

    forinc(i,1,n) if (i != S && i != T && !dd[get_root(i)]) dd[get_root(i)]  = true , comp.push_back(get_root(i)) ;

    forinc(i,1,m)
        if ((edge[i].fi == S && edge[i].se != T) || (edge[i].fi != T && edge[i].se == S)) {
            int u = (edge[i].fi == S) ? edge[i].se : edge[i].fi ;
            edge_toS[get_root(u)] = true ; to_S[get_root(u)] = i ;

        } else if ((edge[i].fi == T && edge[i].se != S) || (edge[i].fi != S && edge[i].se == T)) {
            int u = (edge[i].fi == T) ? edge[i].se : edge[i].fi ;
            edge_toT[get_root(u)] = true ; to_T[get_root(u)] = i ;
        }

    for (auto u : comp) if (edge_toS[u] && edge_toT[u]) comp_ST.push_back(u) ;
    else if (!edge_toS[u] && !edge_toT[u]) comp_not_ST.push_back(u) ;
    else if (edge_toS[u]) comp_S.push_back(u) ; else if (edge_toT[u]) comp_T.push_back(u) ;
}

int deg_S = 0 , deg_T = 0 ;

void process () {
    prepare ()  ;

    if (comp_not_ST.size() > 0) {cout << -1 << endl ; return ; }

    deg_S = comp_S.size() ; deg_T = comp_T.size() ;
    if (deg_S >= dS || deg_T >= dT) {cout << -1 << endl ; return ; }

    if (!edge_from_S_to_T) {
        if (comp_ST.size() == 0) {cout << -1 << endl ; return ; }
        if ()
    }
}

int main () {
    return 0 ;
}
