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
#define base (int) 1e9 + 7
#define maxNode 1000000

using namespace std ;

int n , m , nxt[maxNode][2] , snode , lab[maxNode] , f[maxNode] ;

void build_trie(vector<int> x)
{
    int u = 1 ; lab[u] ++ ;
    forv(i,x) {
        if (nxt[u][x[i]] == 0) nxt[u][x[i]] = ++snode ;
        u = nxt[u][x[i]] ;
    }
    lab[u] ++ ;
}

void dfs(int u)
{
    f[u] = lab[u] ;
    if (nxt[u][0] != 0) dfs(nxt[u][0]) , f[u] += f[nxt[u][0]] ;
    if (nxt[u][1] != 0) dfs(nxt[u][1]) , f[u] += f[nxt[u][1]] ;
}

void enter()
{
    snode = 1 ;
    cin >> m >> n ;
    forinc(i,1,m) {
        int s = 0 ; cin >> s ;
        vector<int> bit ; bit.clear() ;
        forinc(i,1,s) {
            int x = 0 ; cin >> x ;
            bit.push_back(x) ;
        }
        build_trie(bit) ;
    }
}

int solve(vector<int> x)
{
    int u = 1 , res = 0 ;
    forv(i,x) {
        if (nxt[u][x[i]] == 0) return res ;
        u = nxt[u][x[i]] ; res += lab[u] ;
    }
    return res + f[u] - lab[u] ;
}

void process()
{
    dfs(1) ;
    forinc(i,1,n) {
        int s = 0 ; cin >> s ;
        vector<int> bit ; bit.clear() ;
        forinc(i,1,s) {
            int x = 0 ; cin >> x ;
            bit.push_back(x) ;
        }
        cout << solve(bit) << endl ;
    }
}

int main()
{
    //freopen("SEC.inp" , "r" , stdin) ;
    enter() ;
    process() ;
    return 0  ;
}
