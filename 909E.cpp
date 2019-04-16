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

#define maxN 100005

int n , m , E[maxN] , degIn[maxN] ;
vector<int> ke[maxN] ;

void enter () {
    cin >> n >> m ;
    forinc(i,1,n) cin >> E[i] ;
    forinc(i,1,m) {
        int u , v ; cin >> u >> v ; u ++ ; v ++ ;
        ke[v].push_back(u) ; degIn[u] ++;
    }
}

int bfs() {
    deque<int> q ;
    forinc(i,1,n) if (degIn[i] == 0) (E[i] == 0) ? q.push_front(i) : q.push_back(i) ;

    int cnt = 0 ;

    while (!q.empty()) {
        while (!q.empty() && E[q.front()] == 0) {
            int u = q.front() ; q.pop_front()  ;
            for (auto v : ke[u]) {
                degIn[v] -- ;
                if (degIn[v] == 0) (E[v] == 0) ? q.push_front(v) : q.push_back(v) ;
            }
        }

        if (!q.empty() && E[q.front()] == 1) cnt ++ ;
        while (!q.empty() && E[q.front()] == 1) {
            int u = q.front() ; q.pop_front() ;
            for (auto v : ke[u]) {
                degIn[v] -- ;
                if (degIn[v] == 0) (E[v] == 0) ? q.push_back(v) : q.push_front(v) ;
            }
        }
    }

    return cnt ;
}

void process () {
    cout << bfs () << endl ;
}

int main () {
    //freopen("909E.inp", "r" , stdin) ;
    enter () ;
    process () ;
    return 0 ;
}
