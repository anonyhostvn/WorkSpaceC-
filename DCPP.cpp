
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
#define pli pair<long long , int>

template <class _T> bool maximize(_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize(_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

const int ooit = 2e9 ;
const long long ooll = 1e15 ;

using namespace std ;

#define maxN 1005

int fastRead() {
    char c ; int res = 0 ;
    for (c = getchar() ; c < '0' || c > '9' ; c = getchar())  ;
    for ( ; c >= '0' && c <= '9' ; c = getchar()) res *= 10 , res += c - '0' ;
    return res ;
}

int n , m , degOut[maxN] , degIn[maxN] ;
vector<pii> ke[maxN] ;
long long ans = 0 ;

void enter () {
    //cin >> n >> m ;
    n = fastRead() ; m = fastRead() ;
    forinc(i,1,m) {
        int u = fastRead() , v = fastRead() , c = fastRead() ; //cin >> u >> v >> c ;
        ke[u].push_back({v,c}) ;
        degOut[u] ++ ; degIn[v] ++ ; ans += c ;
    }
}

long long d[maxN] ;

void dkstra(int start) {
    priority_queue<pli> q ;
    forinc(i,1,n) d[i] = ooll ; d[start] = 0 ; q.push({0,start}) ;

    while (!q.empty()) {
        int u = q.top().se ; q.pop() ;
        for (auto tmp : ke[u]) if (minimize(d[tmp.fi] , d[u] + tmp.se)) q.push({-d[tmp.fi] , tmp.fi}) ;
    }
}

long long f[maxN][maxN] ;
vector<int> X_adj , Y_adj ;

void prepare () {
    forinc(i,1,n) {
        dkstra(i) ;
        forinc(j,1,n) f[i][j] = d[j] ;
    }
}

int k = 0  ;
long long dist[2 * maxN][2 * maxN] ;

void Build_New_Graph () {
    forinc(i,1,n) if (degIn[i] > degOut[i]) forinc(j,1,degIn[i] - degOut[i]) X_adj.push_back(i) ;
    else if (degIn[i] < degOut[i]) forinc(j,1,degOut[i] - degIn[i]) Y_adj.push_back(i) ;

    k = max(X_adj.size() , Y_adj.size()) ;
    forinc(i,1,k) forinc(j,1,k) dist[i][j] = ooll ;

    forv(i,X_adj) forv(j,Y_adj) {
        int u = X_adj[i] , v = Y_adj[j] ;
        dist[i + 1][j + 1] = f[X_adj[i]][Y_adj[j]] ;
    }
}

int trace[2 * maxN] ;
long long fx[2 * maxN] , fy[2 * maxN] , matchX[2 * maxN] , matchY[2 * maxN] ;

long long wp(int x , int y) {return dist[x][y] + fx[x] + fy[y] ; }

int Find_Open_Path(int start) {
    memset(trace , 0 , sizeof(trace)) ;
    queue<int> q ; q.push(start) ;

    while (!q.empty()) {
        int u  = q.front() ; q.pop() ;
        forinc(i,1,k) if (!trace[i] && !wp(u,i)) {
            trace[i] = u ;
            if (!matchY[i]) return i ;
            q.push(matchY[i]) ;
        }
    }

    return 0 ;
}

bool visX[2 * maxN] , visY[2 * maxN] ;

void Reverse_Path(int start) {
    memset(visX , false , sizeof(visX)) ;
    memset(visY , false , sizeof(visY)) ;

    visX[start] = true ;
    forinc(i,1,k) if (trace[i]) visY[i] = true , visX[matchY[i]] = true ;

    long long delta = ooll ;
    forinc(i,1,k) if (visX[i]) forinc(j,1,k) if (!visY[j]) minimize(delta , wp(i,j)) ;
    forinc(i,1,k) (visX[i]) ? fx[i] -= delta : 0 , (visY[i]) ? fy[i] += delta : 0 ;
}

void Enlarge(int start , int finish) {
    do {
        int u = trace[finish] , nxt = matchX[u] ;
        matchX[u] = finish ; matchY[finish] = u ;
        finish = nxt ;
    } while (finish > 0) ;
}

void Hungari() {
    forinc(i,1,k) {
        int finish = Find_Open_Path(i) ;
        for ( ; finish == 0 ; finish = Find_Open_Path(i)) Reverse_Path(i) ;
        Enlarge(i , finish) ;
    }
}

void process () {
    prepare () ;
    Build_New_Graph() ;
    Hungari() ;
    forinc(i,1,k) ans += dist[i][matchX[i]] ;
    cout << ans << endl ;
}

int main () {
    freopen("DCPP.inp" , "r" , stdin) ;
    freopen("DCPP.out" , "w" , stdout) ;
    enter () ;
    process () ;
    return 0 ;
}
