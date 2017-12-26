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
#define maxN 200001

using namespace std ;

int n , a[maxN] , f[maxN] , g[maxN][200] , d[maxN] , beau[maxN];
vector<int> ke[maxN] ;

int enter()
{
    cin >> n ;
    forinc(i,1,n) cin >> a[i] ;
    forinc(i,1,n-1) {
        int u , v ; cin >> u >> v ;
        ke[u].push_back(v) ;
        ke[v].push_back(u) ;
    }
    return  0 ;
}

int gcd(int a , int b)
{
    if (a == 0) return b ;
    while (b > 0) {
        int tmp = a % b ;
        a = b ; b = tmp ;
    }
    return a ;
}

int dfs(int u , int par)
{
    forv(j,ke[u]) {
        int v = ke[u][j] ;
        if (v != par) {
            f[v] = gcd(a[v],f[u]) ;
            dfs(v,u) ;
        }
    }
    return 0 ;
}

vector <int> divsor ;

int find_div(int x)
{
    forinc(i,1,x) if (x % i == 0) divsor.push_back(i) ;
    return 0 ;
}

int count_div(int x)
{
    int res = 0 ;
    forinc(i,2,(int) sqrt(x)) if (x % i == 0) res ++ ;
    return res ;
}

int visit(int u , int p)
{
    forv(i,divsor) g[u][i] = g[p][i] + (int) (a[u] % divsor[i] == 0) ;
    forv(j,ke[u]) {
        int v = ke[u][j] ;
        if (v != p) {
            d[v] = d[u] + 1 ;
            visit(v,u) ;
        }
    }
    return 0 ;
}

int process()
{
    dfs(1,-1) ;
    find_div(a[1]) ;
    d[1] = 1 ;
    visit(1,0) ;
    forinc(i,1,n) {
        int res = 0 ;
        forv(j,divsor) if (g[i][j] >= d[i] -1) res = divsor[j] ;
        f[i] = max(f[i],res) ;
    }
    forinc(i,1,n) cout << f[i] << " " ;
    return 0 ;
}

int main()
{
    //freopen("842C.inp" , "r" , stdin) ;
    enter() ;
    process() ;
    return 0 ;
}
