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
#define oo (int) 1e9 + 7
#define maxN 505

using namespace std ;

int n , a[maxN] , dd[maxN] , cnt[maxN][maxN][maxN] , f[maxN][maxN] ;
bool c[maxN][maxN] , full[maxN][maxN] ;

void enter()
{
    cin >> n ;
    forinc(i,1,n) cin >> a[i] ;
}

void prepare()
{
    forinc(u,1,n)
    forinc(v,u,n) {
        forinc(i,1,n) dd[i] = 0 ; bool ok = true ;
        forinc(i,u,v) if (++dd[a[i]] > 1) ok = false ;
        c[u][v] = ok ; if (!ok) continue ;
        forinc(i,1,n) dd[i] += dd[i-1] , cnt[u][v][i] = dd[i] ;
        if (dd[v-u+1] == v - u + 1) full[u][v] = true ;
    }
}

int cost(int i , int j , int u , int v)
{
    if (a[i] < a[u]) return (v - u + 1) + (j - i + 1 - cnt[i][j][a[u]]) ;
    return (j-i+1) + (v - u + 1 - cnt[u][v][a[i]]) ;
}

void process()
{
    forinc(i,1,n) if (a[i] > n) {
        cout << "impossible" << endl ;
        return ;
    }
    prepare() ;
    fordec(u,n-1,1)
    forinc(v,u+1,n) if (c[u][v]) {
        f[u][v] = oo ;
        forinc(i,u,v-1) f[u][v] = min(f[u][v],f[u][i] + f[i+1][v] + cost(u,i,i+1,v)) ;
    }
    bool ok = true ;
    int i = 1 , res = 0 ;
    while (i <= n) {
        int j = i ;
        while (j <= n && c[i][j]) j ++ ;
        if (full[i][j-1]) res += f[i][j-1] , i = j ; else {
            cout << "impossible" << endl ;
            return ;
        }
    }
    cout << res << endl ;
}

int main()
{
    freopen("DOLL.inp" , "r" , stdin) ;
    freopen("DOLL.out" , "w" , stdout) ;
    enter() ;
    process() ;
    return 0 ;
}
