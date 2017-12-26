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
#define maxN 1005
#define maxNode 1000005

using namespace std ;

int r , c , a[maxN][maxN] , snode = 1 , nxt[maxNode][26] , lab[maxNode] ;

void enter()
{
    cin >> r >> c ;
    forinc(i,1,r) forinc(j,1,c) {
        char ch ; cin >> ch ;
        a[i][j] = (int) ch - (int) 'a' ;
    }
}

void build(int c)
{
    int u = 1 ; lab[u] ++ ;
    fordec(i,r,1) {
        if (nxt[u][a[i][c]] == 0) nxt[u][a[i][c]] = ++snode ;
        u = nxt[u][a[i][c]] ; lab[u] ++ ;
    }
}

int res = -1 ;

void dfs(int u , int deg)
{
    if (lab[u] > 1) res = max(res,deg) ;
    forinc(i,0,25) if (nxt[u][i] != 0) dfs(nxt[u][i],deg+1) ;
}

void prepare()
{
    forinc(i,1,c) build(i) ;
    dfs(1,0) ;
    if (res == -1) cout << r-1 << endl ; else if (res == r) cout << 0 << endl ; else cout << r - res - 1 << endl ;
}

int main()
{
    //freopen("ZNANSTVE.inp" , "r" , stdin) ;
    ios_base::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    enter() ;
    prepare() ;
    return 0 ;
}
