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
#define oo (long long) 1e15
#define maxN 300005

using namespace std ;

int n , a , b ;
vector<int> ke[maxN] ;
bool black[maxN] ;

void enter()
{
    scanf("%d" , &n) ;
    forinc(i,1,n-1) {
        int u , v ; scanf("%d%d" , &u , &v) ;
        ke[u].push_back(v) ;
        ke[v].push_back(u) ;
    } scanf("%d%d" , &a , &b) ;
    black[a] = true ; black[b] = true ;
}

int f[maxN]  , g[maxN] , d[maxN] , cnt = 0 ;

vector<int> t_black ;

bool dfs(int u , int p)
{
    forv(i,ke[u]) {
        int v = ke[u][i]  ;
        if (v != p) {
            dfs(v,u) ;
            black[u] |= black[v] ;
            if (!black[v] && d[u] < d[v] + 1) d[u] = d[v] + 1;
        }
    }
    if (black[u]) t_black.push_back(u) ;
    return black[u] ;
}

void process()
{
    dfs(a,-1) ;
    f[0] = d[t_black[0]] ;
    forinc(i,1,t_black.size()-1) f[i] = max(f[i-1],d[t_black[i]] + i) ;
    g[t_black.size()-1] = d[t_black[t_black.size()-1]] ;
    fordec(i,t_black.size()-2,0) g[i] = max(g[i+1],d[t_black[i]]+(int) t_black.size()-i-1) ;
    int res = 0 ;
    forinc(i,0,t_black.size()-2) res = max(res,min(f[i],g[i+1])) ;
    printf("%d" , res + 1) ;
}

int main()
{
    freopen("WEDDING.inp" , "r" , stdin) ;
    freopen("WEDDING.out" , "w" , stdout) ;
    enter() ;
    process() ;
    return 0 ;
}
