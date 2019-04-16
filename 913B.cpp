#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)
#define forv(j,u) for (int j = 0 ; j < u.size() ; j++)
#define fi first
#define se second
#define pii pair<int,int>
#define pli pair<long long , int>

template <class _T> bool maximize(_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize(_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

const int ooit = 2e9 ;
const long long ooll = 1e15 ;

using namespace std ;

#define maxN 1005

int n ;
vector<int> ke[maxN] ;

int child[maxN] , c_leaf[maxN] ;
bool is_leaf[maxN] ;

void dfs(int u , int p) {
    for (auto v : ke[u])
            if (v != p) child[u] ++ , dfs(v,u) , c_leaf[u] += (int) is_leaf[v] ;
    if (child[u] == 0) is_leaf[u] = true ;
}

bool check() {
    forinc(i,1,n) if (!is_leaf[i] && c_leaf[i] < 3) return false ;
    return true ;
}

int main () {
    //freopen("913.inp" , "r" , stdin)  ;

    cin >> n ;
    forinc(i,1,n-1) {
        int x ; cin >> x ;
        ke[i+1].push_back(x) ;
        ke[x].push_back(i+1) ;
    }

    dfs(1,-1) ;

    if (!check()) cout << "no" << endl ; else cout << "yes" << endl ;

    return 0 ;
}
