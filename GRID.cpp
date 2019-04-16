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

template <class _T> bool maximize(_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize(_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

const int ooit = 2e9 ;
const long long ooll = 1e15 ;

using namespace std ;

#define maxN 105

int n , a[maxN][maxN] , xs , ys , xe , ye ;

void enter () {
    cin >> n ;
    forinc(i,1,n) forinc(j,1,n) {
        char ch ; cin >> ch ;
        if (ch == 'X') a[i][j] = 1 ;
    }
    cin >> xs >> ys >> xe >> ye ;
    xs ++ ; ys ++ ; xe ++ ; ye ++ ;
}

int dd[maxN][maxN] ;
queue<pii> q ;

void go(int x , int y , int _plus , int dis) {
    int u = x , v = y ;
    while (x >= 1 && x <= n) {
        if (dd[x][y] == -1 && a[x][y] == 0) dd[x][y] = dis + 1 , q.emplace(x,y) ;
        if (a[x][y] > 0) break ;
        x += _plus ;
    }
    while (v >= 1 && v <= n) {
        if (dd[u][v] == -1 && a[u][v] == 0) dd[u][v] = dis + 1 , q.emplace(u,v) ;
        if (a[u][v] > 0) break ;
        v += _plus ;
    }
}

void bfs(int xs , int ys) {
    forinc(i,1,n) forinc(j,1,n) dd[i][j] = -1 ;
    dd[xs][ys] = 0 ; q.emplace(xs,ys) ;

    while (!q.empty()) {
        auto tmp = q.front() ; q.pop() ;
        int u = tmp.fi , v = tmp.se ;
        go(u,v,1,dd[u][v]) ;
        go(u,v,-1,dd[u][v]) ;
    }
}

void process () {
    bfs(xs,ys) ;
    cout << dd[xe][ye]  ;
}

int main () {
    freopen("GRID.inp" , "r" , stdin) ;
    freopen("GRID.out" , "w" , stdout) ;
    enter () ;
    process () ;
    return 0 ;
}
