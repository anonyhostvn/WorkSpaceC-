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
#define maxN 200005

using namespace std ;

int n , m , k ;
vector<int> ke[maxN] ;

void enter()
{
    scanf("%d%d%d" , &m , &n , &k) ;
    forinc(i,1,k) {
        int u ,v ; scanf("%d%d" , &u , &v) ;
        ke[u].push_back(v+n) ;
    }
}

int match[maxN] ;
bool found , vis[maxN] ;
vector<int> Xlist ;

void dfs(int u) {
    forv(i,ke[u]) if (!vis[ke[u][i]]) {
        int v = ke[u][i] ; vis[v] = true ;
        if (match[v] == 0) found = true ; else dfs(match[v]) ;
        if (found) {match[v] = u ; return ; }
    }
}

void process()
{
    int res = 0 , old_size = 0 ;
    forinc(i,1,m) Xlist.push_back(i) ;
    do {
        old_size = Xlist.size() ;
        forinc(i,1,2*n) vis[i] = false ;
        for (int i = Xlist.size() -1 ; i >= 0; --i) {
            found = false ; dfs(Xlist[i]) ;
            if (found) Xlist[i] = Xlist.back() , Xlist.pop_back() , ++res ;
        }
    } while (old_size != Xlist.size()) ;
    printf("%d\n" , res) ;
    forinc(i,1,n) cout << match[i+n] << " " ; cout << endl ;
}

int main()
{
    freopen("ASSIGN.inp" , "r" , stdin) ;
    freopen("ASSIGN.out" , "w" , stdout) ;
    enter() ;
    process() ;
    return 0 ;
}
