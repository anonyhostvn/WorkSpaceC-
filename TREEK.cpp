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
    char c ; int res = 0 ;
    for (c = getchar() ; c < '0' || c > '9' ; c = getchar()) ;
    for ( ; c >= '0' && c <= '9' ; c = getchar()) res*= 10 , res += c - '0' ;
    return res ;
}

#define maxN 100005

int n , k ;
vector<pii> ke[maxN] ;
bool import[maxN] ;

void enter () {
    n = fastRead() ; k = fastRead() ;
    forinc(i,1,n-1) {
        int u = fastRead() , v = fastRead() , c = fastRead() ;
        ke[u].push_back({v,c}) ;
        ke[v].push_back({u,c}) ;
    }
    forinc(i,1,k) {
        int u = fastRead() ;
        import[u] = true ;
    }
}

long long f[maxN][2] ;

void dfs(int u , int p) {
    if (import[u]) f[u][0] = ooll ;
    long long sum0 = 0 , minc = ooll  ;
    for (auto v : ke[u]) if (v.fi != p) {
        dfs(v.fi,u) ;
        long long tmp = min(f[v.fi][0] , f[v.fi][1] + v.se) ;
        sum0 += tmp ; minimize(minc , -tmp + f[v.fi][1]) ;
    }
    if (!import[u]) f[u][0] = sum0 , f[u][1] = sum0 + minc ; else f[u][1] = sum0 ;
}

void process () {
    dfs(0,-1) ;
    cout << min(f[0][1],f[0][0]) ;
}

int main () {
    freopen("TREEK.inp" , "r" , stdin) ;
    //freopen("TREEK.out" , "w" , stdout) ;
    enter () ;
    process () ;
    return 0 ;
}
