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

using namespace std;

#define maxN 100000
#define maxn 10005

int n , m , d[maxn][maxn] ;
//vector<int> ke[maxN] ;

///________________________________________________________________________________________________________________________________________________
///                                             Doc du lieu
///________________________________________________________________________________________________________________________________________________

void enter() {
    cin >> n >> m ;
}

///________________________________________________________________________________________________________________________________________________
///                                                             Sub Trau
///________________________________________________________________________________________________________________________________________________

void enter_trau () {
    forinc(i,1,m) {
        int u , v ; cin >> u >> v ;
        d[u][v] ++ ; d[v][u] ++ ;
    }
}

struct node {
    int tque , x1 ,x2 ;
};

#define maxQ 10005

node query[maxQ];
int g[maxn] ;

int bfs(int start , int finish) {
    forinc(i,1,n) g[i] = -1 ; g[start] = 0 ;
    queue<int> q ; q.push(start) ;

    while (!q.empty()) {
        int u = q.front() ; q.pop() ;
        forinc(v,1,n) if (g[v] <= -1 && d[u][v]) g[v] = g[u] + 1 , q.push(v) ;
    }

    return g[finish] ;
}

void trau () {
    int q =  0 ; cin >> q;
    forinc(i,1,q) {
        cin >> query[i].tque ;
        if (query[i].tque == 1) {
            cin >> query[i].x1 >> query[i].x2 ;
            forinc(u,query[i].x1,query[i].x2-1)
            forinc(v,u + 1,query[i].x2) d[u][v] ++ , d[v][u] ++ ;
        }
        else if (query[i].tque == 2) {
            int id ; cin >> id ;
            forinc(u,query[id].x1,query[id].x2-1)
            forinc(v,u+1,query[id].x2) d[u][v] -- , d[v][u] --  ;
        }
        else {
            int u , v ; cin >> u >> v;
            cout << bfs(u,v) << endl ;
        }
    }
}

///________________________________________________________________________________________________________________________________________________
///                                                         Chia Sub
///________________________________________________________________________________________________________________________________________________

void Process () {
    if (n <= 10000) enter_trau() , trau () ;
}

///________________________________________________________________________________________________________________________________________________
///                                                             Xu Ly
///________________________________________________________________________________________________________________________________________________

int main () {
    freopen("SUBGRAPHS.inp" , "r" , stdin) ;
    freopen("SUBGRAPHS.out" , "w" , stdout) ;

    enter () ;
    Process () ;

    return 0 ;
}
