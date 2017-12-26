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
#define maxN 100005

template <class _T> bool maximize(_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize(_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

using namespace std ;

int P , n  ;

set<int> nxt[maxN] ;

int fastRead() {
    char c ; int res = 0 ;
    for (c = getchar() ; c < '0' || c > '9' ; c = getchar()) ;
    for ( ; c >= '0' && c <= '9' ; c = getchar()) res *= 10  , res += (int) c - (int) '0' ;
    return res ;
}


void enter () {
    //scanf("%d%d" , &P , &n) ;
    P = fastRead() ; n = fastRead() ;
    forinc(i,1,n) {
        int k = fastRead() ; //scanf("%d" , &k) ;
        forinc(j,1,k) {
            int u = fastRead(); //scanf("%d" , &u) ;
            if (nxt[u].find(i) != nxt[u].end()) nxt[u].erase(i) ; else nxt[i].insert(u) ;
        }
    }
}

int deg[maxN] ;

void process () {
    forinc(i,1,n) for (int u : nxt[i]) deg[i]++ , deg[u] ++ ;
    int cnt = 0 , adj = 0 ;
    forinc(i,1,n) if (maximize(cnt,deg[i])) adj = i ;

    if (P == 1) { cout << adj << endl ; return ; }

    int adj_1 = 0 , cnt_1 = 0  ;
    forinc(i,1,n) deg[i] = 0 ;
    forinc(i,1,n) if (i != adj) for (int u : nxt[i]) if (u != adj) deg[u] ++ , deg[i] ++ ;
    forinc(i,1,n) if (maximize(cnt_1,deg[i])) adj_1 = i ;

    cout << min(adj,adj_1) << " " << max(adj_1,adj) << endl ;
}

int main () {
    freopen("GRAPHGAME.inp" , "r" , stdin) ;
    freopen("GRAPHGAME.out" , "w" , stdout) ;
    enter() ;
    process () ;
}
