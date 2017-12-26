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
#define maxN 10005

template <class _T> bool maximize(_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize(_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

using namespace std ;

int n , m ;
vector<int> ke[maxN] ;

void enter () {
    //cin >> n >> m ;
    scanf("%d%d" , &n , &m) ;
    forinc(i,1,m) {
        int u , v ; //cin >> u >> v ;
        scanf("%d%d" , &u , &v) ;
        ke[u].push_back(v) ; ke[v].push_back(u) ;
    }
}

int num[maxN] , low[maxN] , s_bridge = 0 , s_joint = 0 , cnt = 0 ;
bool is_joint[maxN] ;

void dfs(int u , int p) {
    num[u] = low[u] = ++cnt ; int child = 0 ;

    for (int v : ke[u]) if (v != p)
        if (num[v] == 0) {
            dfs(v,u) ; if (p == -1) child ++ ;

            s_bridge += (int) (low[v] > num[u]) ;
            is_joint[u] |= (low[v] >= num[u]) ;

            minimize(low[u],low[v]) ;
        } else minimize(low[u],num[v]) ;
    if (p == -1 && child < 2) is_joint[u] = false ;
}

void process () {
    dfs(1,-1) ;
    forinc(i,1,n) s_joint += (int) is_joint[i] ;
    cout << s_bridge << " " << s_joint << endl ;
}

int main () {
    freopen("COMPNET.inp" , "r" , stdin) ;
    freopen("COMPNET.out" , "w" , stdout) ;
    enter ()  ;
    process () ;
    return 0 ;
}
