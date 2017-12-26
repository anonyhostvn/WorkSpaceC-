#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)
#define forv(j,u) for (int j = 0 ; j < u.size() ; j++)

using namespace std ;

int n , parent[100001] , g , k ,sct , scthuan_up[100001] , scnguoc_up[100001] ;
vector <int> ke[100001] ;

int enter()
{
    cin >> n ;
    forinc(i,1,n-1){
        int u , v ;
        cin >> u >> v ;
        ke[u].push_back(v) ;
        ke[v].push_back(u) ;
    }
    cin >> g >> k ;

    return 0 ;
}

int dfs(int u , int p )
{
    forv(j,ke[u]){
        int v = ke[u][j] ;
        if (v!=p){
            dfs(v,u) ;
            parent[v] = u ;
        }
    }
    return 0 ;
}

int dfs1(int u , int p)
{
    forv(j,ke[u]){
        int v = ke[u][j] ;
        if (v!=p){
            scthuan_up[v] += scthuan_up[u] ;
            scnguoc_up[v] += scnguoc_up[u] ;
            dfs1(v,u) ;
        }
    }
    return 0 ;
}

int preset()
{
    forinc(i,1,n){
        ke[i].clear() ;
        scthuan_up[i] = 0 ;
        scnguoc_up[i] = 0 ;
    }
    return 0 ;
}

int gcd(int a , int b)
{
    while (b){
        int tmp = a % b ;
        a = b ;
        b = tmp ;
    }
    return a ;
}

int process()
{
    sct = 0 ;
    dfs(1,-1) ;
    forinc(i,1,g) {
        int u , v ; cin >> u >> v ;
        if (parent[v] == u) {
            scthuan_up[v] ++ ;
            ++sct ;
        }
        else scnguoc_up[u]++ ;
    }

    dfs1(1,-1) ;
    //forinc(i,1,n) cout << i << " " << scnguoc_up[i] << " " << scthuan_up[i] << endl  ;
    //cout <<"___" << endl ;
    int res = 0 ;
    forinc(i,1,n){
        int tmp = sct - scthuan_up[i] + scnguoc_up[i] ;
        if (tmp >= k) res ++ ;
        //cout << i <<" "<< tmp << endl ;
    }
    //cout <<"PPPP" << endl ;
    cout << res / gcd(res,n) << "/" << n/gcd(res,n) << endl ;
    preset() ;

    return 0 ;
}

int main()
{
    //freopen("tree1.inp" , "r" , stdin) ;
    int t = 0 ; cin >> t ;
    forinc(i,1,t){
        enter() ;
        process() ;
    }
    return 0 ;
}
