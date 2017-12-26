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
#define ooll (long long) 1e15
#define ooit (int) 2e9
#define maxN 2005

template <class _T> bool maximize(_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize(_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

using namespace std ;

int n , m ;
vector<int> ke[maxN];

void enter() {
    cin >> n >> m ;
    forinc(i,1,m) {
        int u , v , c ; cin >> u >> v >> c ;
        ke[u].push_back(v) ; ke[v].push_back(u) ;
    }
}

bool vis[maxN] ;
int num[maxN] , low[maxN] ;

void dfs(int u) {
    vis[u] = true ;
}

int main () {
    return 0 ;
}
