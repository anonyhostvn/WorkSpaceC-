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

#define maxN 10005

int n , a[maxN] ;
vector<int> ke[maxN] ;

void enter () {
    cin >> n ;
    forinc(i,1,n-1) {
        int x ; cin >> x ;
        ke[i+1].push_back(x) ; ke[x].push_back(i+1) ;
    }
    forinc(i,1,n) cin >> a[i] ;
}

int vis[maxN] , cnt = 0 , f[maxN] ;

void dfs(int u , int p) {
    vis[++cnt] = u ; f[u] = 1 ;
    for (auto v : ke[u]) if (v != p) dfs(v,u) , f[u] += f[v] ;
}

int color[maxN] ;

void change(int l , int r , int x) {
    forinc(i,l,r) color[vis[i]] = x ;
}

void process () {
    dfs(1,-1) ;
    int res = 0 ;
    forinc(i,1,n) {
        int u = vis[i] ;
        if (color[u] != a[u]) res ++ , change(i, i+f[u]-1 , a[u]) ;
    }

    cout << res << endl ;
}

int main () {
    //freopen("902.inp" , "r" , stdin) ;
    enter () ;
    process () ;
    return 0 ;
}
