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

#define maxN 305

int n , k , a[maxN]  ;

int fastRead() {
    char c ; int res = 0 ;
    for (c = getchar() ; c < '0' || c > '9' ; c = getchar()) ;
    for ( ; c >= '0' && c <= '9' ; c = getchar()) res*= 10 , res += c - '0' ;
    return res ;
}

void enter () {
    n = fastRead() ; k = fastRead() ;
    forinc(i,1,n) a[i] = fastRead() ;
}

vector<int> ke[maxN] ;

void prepare () {
    forinc(i,1,n) ke[i].clear() ;
    forinc(i,1,n-1)
        forinc(j,i+1,n) if (abs(a[j] - a[i]) >= k) ke[i].push_back(j) ;
}

int matchX[maxN] , matchY[maxN] , trace[maxN] ;

int Open_Path() {
    queue<int> q ;
    forinc(i,1,n) {
        if (!matchX[i]) q.push(i) ;
        trace[i] = 0 ;
    }

    while (!q.empty()) {
        int u = q.front() ; q.pop() ;
        for (auto v : ke[u]) if (!trace[v]) {
            trace[v] = u ;
            if (!matchY[v]) return v ;
            q.push(matchY[v]) ;
        }
    }

    return 0 ;
}

void Enlarger(int finish) {
    do {
        int u = trace[finish] , nxt = matchX[u] ;
        matchX[u] = finish ; matchY[finish] = u ;
        finish = nxt ;
    } while (finish > 0) ;
}

int maximum_matching() {
    forinc(i,1,n) matchX[i] = 0 , matchY[i] = 0 ;
    int finish = 0 ;
    do {
        finish = Open_Path () ;
        if (finish > 0) Enlarger(finish) ;
    } while (finish > 0) ;

    int cnt = 0 ;
    forinc(i,1,n) if (matchX[i]) cnt ++ ;
    return cnt ;
}

void process () {
    prepare () ;
    cout << n - maximum_matching() << endl ;
}

int main () {
    freopen("PROSOL.inp" , "r" , stdin) ;
    freopen("PROSOL.out" , "w" , stdout) ;
    int t = fastRead() ;
    while (t--) enter () , process () ;
    return 0 ;
}
