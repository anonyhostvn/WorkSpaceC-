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

#define maxN 205

int n , m ;
bool d[maxN][maxN] ;

void enter () {
    cin >> n >> m ;
    int u , v ;
    while (cin >> u >> v) d[u][v] = true ;
}

int matchX[maxN] , matchY[maxN] , trace[maxN] ;

int Find_Open_Path() {
    memset(trace , 0 , sizeof(trace)) ;
    queue<int> q ;
    forinc(i,1,n) if (!matchX[i]) q.push(i) ;

    while (!q.empty()) {
        int u = q.front() ; q.pop() ;
        forinc(i,1,m) if (!trace[i] && d[u][i]) {
            trace[i] = u ;
            if (matchY[i] == 0) return i ;
            q.push(matchY[i]) ;
        }
    }
    return 0 ;
}

void Enlarge(int finish) {
    do {
        int u = trace[finish] , nxt = matchX[u] ;
        matchX[u] = finish ; matchY[finish] = u ;
        finish = nxt ;
    } while (finish != 0) ;
}

void process() {
    int finish = Find_Open_Path() ;

    for ( ; finish > 0 ; finish = Find_Open_Path()) if (finish > 0) Enlarge(finish) ;

    int res = 0 ; forinc(i,1,n) res += (int) (matchX[i] > 0) ; cout << res << endl ;

    forinc(i,1,n) if (matchX[i] > 0) cout << i << " " << matchX[i] << endl ;
}

int main () {
    //freopen("MATCH1.inp" , "r" , stdin) ;
    enter () ;
    process () ;
    return 0 ;
}
