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
#define maxN 101

using namespace std ;

int n , m , a[maxN*maxN] , cnt = 0 , id[maxN*maxN] , topo[maxN*maxN] , b[maxN][maxN] ;
vector<int> ke[maxN*maxN] ,nxt[maxN * maxN] ;
bool vis[maxN * maxN] ;

int add(int u , int v)
{
    ke[u].push_back(v);
    return 0 ;
}

int enter()
{
    cin >> m >> n ;
    forinc(i,1,m){
        string st ; cin >> st ;
        forinc(j,1,n) b[i][j] = (int)st[j-1] ;
    }
    forinc(i,1,m) {
        string st ; cin >> st ;
        forinc(j,1,n) {
            int u = n * (i-1) + j , x = b[i][j] ;
            if (x == (int)'#') {a[u] = -1 ; continue ; }
            else if (x == 'W') {if (j > 1 && b[i][j-1] != (int)'#') add(u,u-1) ;}
            else if (x == 'N') {if (i > 1 && b[i-1][j] != (int)'#') add(u,u-n) ;} else a[u] = x - (int)'0' ;
            if (j < n && b[i][j+1] != (int)'#') add(u,u+1) ;
            if (i < m && b[i+1][j] != (int)'#') add(u,u+n) ;
        }
    }
    return 0;
}

int lab[maxN*maxN] , num[maxN*maxN] , low[maxN*maxN] , s , val[maxN*maxN] , f[maxN*maxN] , de = 0 ;
stack<int> st ;

int set_lab(int u)
{
    st.push(u) ; num[u] = ++cnt ; low[u] = cnt ;
    forv(j,ke[u]) {
        int v = ke[u][j] ;
        if (lab[v] == 0) {
                if (num[v] == 0) {
                    set_lab(v) ;
                    low[u] = min(low[u],low[v]) ;
                }
                else low[u] = min(low[u],num[v]) ;
        }
    }
    if (num[u] == low[u]) {
        int v = -1 , w = 0 ; ++ s ;
        while (v != u) {
            v = st.top() ; st.pop() ;
            lab[v] = s ; w += a[v] ;
        }
        val[s] = w ;
    }
    return 0 ;
}

int stp(int u)
{
    vis[u] = true ;
    forv(j,nxt[u]) {
        int v = nxt[u][j] ;
        if (!vis[v]) stp(v) ;
    }
    id[u] = cnt ;
    topo[cnt--] = u ;
    return 0 ;
}

int re_add(int u , int v)
{
    nxt[u].push_back(v) ;
    return 0 ;
}

int prepare()
{
    cnt = 0 ;
    forinc(i,1,n * m) if (num[i] == 0) set_lab(i) ;
    forinc(i,1,n * m)
        forv(j,ke[i]) if (lab[i] != lab[ke[i][j]]) re_add(lab[i],lab[ke[i][j]]) ;
    forinc(i,1,s) if (!vis[i]) stp(i) ;
    return 0 ;
}

int dp(int u)
{
    forv(j,nxt[u]) {
        int v = nxt[u][j] ;
        if (f[v] < f[u] + val[v]) {
            f[v] = f[u] + val[v] ;
            dp(v) ;
        }
    }
    return 0 ;
}

int process()
{
    prepare() ;
    int root = lab[1] , res = 0 ; f[root] = val[root] ;
    dp(root) ;
    forinc(i,1,s) res = max(res,f[i]) ;
    cout << res ;
    return 0 ;
}

int main()
{
    //freopen("KCOLLECT.inp" , "r" , stdin) ;
    enter() ;
    process()  ;
    return 0 ;
}
