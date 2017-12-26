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

#define maxN 405

int n ;
int d[maxN][maxN] ;

void enter () {
    cin >> n ;
    forinc(i,1,n) forinc(j,1,n) d[i][j] = ooit ;

    int u , v , c ;
    while (cin >> u >> v >> c) d[u][v] = c ;
}

int trace [maxN] , fx[maxN] , fy[maxN] , matchY[maxN] , matchX[maxN] ;

int wp(int x , int y) {return d[x][y] + fx[x] + fy[y] ; }

int Find_Open_Path(int start) {
    memset(trace , 0 , sizeof(trace)) ;
    queue<int> q ; q.push(start) ;

    while (!q.empty()) {
        int u = q.front() ; q.pop() ;
        forinc(i,1,n) if (!trace[i] && !wp(u,i)) {
            trace[i] = u ; if (!matchY[i]) return i ;
            q.push(matchY[i]) ;
        }
    }
    return 0 ;
}

bool visX[maxN] , visY[maxN] ;

void Reverse_Path(int start, int finish) {
    memset(visX , 0 , sizeof(visX)) ;
    memset(visY , 0 , sizeof(visY)) ;

    visX[start] = true ;
    forinc(i,1,n) if (trace[i]) visY[i] = true , visX[matchY[i]] = true ;

    int delta = ooit ;
    forinc(i,1,n) if (visX[i]) forinc(j,1,n) if (!visY[j]) minimize(delta , wp(i , j)) ;
    forinc(i,1,n) fx[i] -= (visX[i]) ? delta : 0 , fy[i] += (visY[i]) ? delta : 0 ;
}

void Enlarge(int finish) {
    do {
        int u = trace[finish]  , nxt = matchX[u] ;
        matchX[u] = finish ;
        matchY[finish] = u ;
        finish = nxt ;
    } while (finish != 0) ;
}

void Hungari () {
    forinc(i,1,n) {
        int finish = 0 ;
        do {
            finish = Find_Open_Path(i) ;
            if (finish == 0) Reverse_Path(i , finish) ;
        } while (finish == 0) ;
        Enlarge(finish) ;
    }
}

void process () {
    Hungari() ;
    long long res = 0 ;
    forinc(i,1,n) if (matchX[i] > 0 && d[i][matchX[i]] < ooit)  res += (long long) d[i][matchX[i]] ;
    cout << res << endl ;
    forinc(i,1,n) if (matchX[i] > 0 && d[i][matchX[i]] < ooit) cout << i << " " << matchX[i] << endl ;
}

int main () {
    //freopen("MATCH2.inp" , "r" , stdin) ;
    //freopen("MATCH2.out" , "w" , stdout) ;
    enter () ;
    process () ;
    return 0 ;
}
