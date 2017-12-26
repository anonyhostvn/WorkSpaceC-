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
#define maxN 100001

using namespace std ;
const long long base = 1e9 + 7 ;
const long long DIV = 5e8 + 4 ;
int n ;
long long f[maxN] , t[maxN];
vector <pii> ke[maxN] ;

int enter()
{
    cin >> n ;
    forinc(i,1,n-1){
        int u , v , w ; cin >> u >> v >> w ;
        ke[u].pb(mk(v,w)) ;
        ke[v].pb(mk(u,w)) ;
    }
    return 0 ;
}

int dfs(int u , int p)
{
    long long sum = 0 , sub = 0 , res = 0 ;
    forv(j,ke[u]){
        int v = ke[u][j].fi ;
        long long dist = ke[u][j].se ;
        if (v != p){
            dfs(v,u) ;
            long long tmp = dist * (f[v] + 1) ; tmp %= base ;
            sum += tmp ; sum %= base ;
            sub += (tmp * tmp) % base ; sub %= base ;
            res += t[v] ; res %= base ;
        }
    }
    f[u] = sum ;
    res += sum ; res %= base ;
    res += ((sum * sum - sub+base) % base) * DIV ; res %= base ;
    t[u] = res ;
    return 0 ;
}

int process()
{
    dfs(1,-1) ;
    cout << t[1] ;
    return 0 ;
}

int main()
{
    //freopen("mtree.inp" , "r" , stdin) ;
    enter() ;
    process() ;
}
