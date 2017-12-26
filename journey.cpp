#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)
#define forv(i,u) for (int j = 0 ; j < u.size() ; j++)

using namespace std ;

int n , p  , cnt , a[100001], sum[100001] ;
vector <int> ke[100001] ;
bool dd[100001] ;

int enter()
{
    cin >> n >> p ;
    forinc(i,1,p) {
        int u , v  ;
        cin >> u >> v ;
        ke[u].push_back(v) ;
        ke[v].push_back(u) ;
    }

    return 0 ;
}

int dfs(int u)
{
    cnt ++ ;
    dd[u] = true ;
    forv(j,ke[u]){
        int v = ke[u][j] ;
        if (!dd[v]) dfs(v) ;
    }

    return 0 ;
}

int process()
{
    int dem = 0 ;
    forinc(i,0,n-1)
    if (!dd[i]){
        cnt = 0 ;
        dfs(i) ;
        a[++dem] = cnt ;
        sum[dem] = sum[dem-1] + a[dem] ;
    }

    long long res = 0 ;

    forinc(i,1,dem) res += (long long) a[i] * (sum[dem] - sum[i]) ;

    cout << res ;

    return 0 ;
}

int main()
{
   //freopen("journey.inp", "r" , stdin) ;
    enter() ;
    process() ;

    return 0 ;
}
