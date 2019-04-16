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
#define pli pair<long long,int>

template <class _T> bool maximize(_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize(_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

const int ooit = 2e9 ;
const long long ooll = 1e15 ;

using namespace std ;


int fastRead() {
    char c ; int res = 0 ;
    for (c = getchar() ; c < '0' || c > '9' ; c = getchar()) ;
    for ( ; c >= '0' && c <= '9' ; c = getchar()) res*= 10 , res += c - '0' ;
    return res ;
}

struct node {
    int v , w , id ;
};

#define maxN 100005

int n , m , st , en , del ;
vector<node> ke[maxN] ;

void enter () {
    n = fastRead() ; m = fastRead() ; st = fastRead() ; en = fastRead() ; del = fastRead() ;
    forinc(i,1,m) {
        int u = fastRead() , v = fastRead() , c = fastRead() ;
        ke[u].push_back({v,c,i}) ;
    }
}

long long d[maxN] ;

void dkstra() {
    priority_queue<pli> q ;
    forinc(i,1,n) d[i] = ooll ; d[st] = 0 ; q.push({0,st}) ;

    while (!q.empty()) {
        auto tmp = q.top() ; q.pop() ; int u = tmp.se ;
        for (auto nxt : ke[u]) {
            int v = nxt.v , we = nxt.w , pos = nxt.id ;
            long long W = (long long) we + ((v == en) ? (long long) 0 : (long long) pos * del ) + ((u == st) ? 0 : pos) ;
            if (d[v] > d[u] + W) {
                d[v] = d[u] + W ;
                if (v != en) q.push({-d[v] , v}) ;
            }
        }
    }
}

void process () {
    dkstra() ;
    if (d[en] < ooll) cout << d[en] << endl ; else cout << -1 << endl ;
}

int main () {
    freopen("METRO.inp" , "r" , stdin) ;
    freopen("METRO.out" , "w" , stdout) ;
    enter () ;
    process () ;
    return 0 ;
}
