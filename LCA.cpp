#include <bits/stdc++.h>
#define maxN 1005
#define debug(x) cerr << #x << " : " << x << endl ;

using namespace std ;

int n , m ;
vector<int> nxt[maxN] ;

void enter (){
    scanf("%d" , &n) ;
    for (int u = 1 ; u <= n  ; u ++) {
        int numChild = 0 ;
        scanf("%d" , &numChild) ;
        for (int i = 1 ; i <= numChild ; i ++) {
            int v ;
            scanf("%d" , &v) ;
            nxt[u].push_back(v) ;
            nxt[v].push_back(u) ;
        }
    }
}

int ancess[maxN][22] , timeIn[maxN] , timeOut[maxN] , Time ;

void Dfs(int u , int par) {
    timeIn[u] = ++Time ;
    for (int i = 1 ; i <= (int) log2(n) + 1 ; i ++) ancess[u][i] = ancess[ancess[u][i-1]][i-1] ;

    for (int v : nxt[u]) if (v != par) {
        ancess[v][0] = u ;
        Dfs(v,u) ;
    }

    timeOut[u] = ++Time ;
}

bool anc(int u , int v)  {
    return (timeIn[u] <= timeIn[v]) && (timeOut[u] >= timeOut[v]) ;
}

int LCA(int u , int v) {
    if (anc(u,v)) return u ; else if (anc(v,u)) return v ;
    for (int i = (int) log2(n) + 1 ; i >= 0 ; i --) if (ancess[u][i] > 0 && !anc(ancess[u][i],v)) u = ancess[u][i] ;
    return ancess[u][0] ;
}

void reset() {
    Time = 0 ;
    for (int i = 1 ; i <= n ; i ++) nxt[i].clear() ;
    memset(ancess , 0 , sizeof(ancess)) ;
}

void process (int numCase) {
    printf("Case %d:\n" , numCase) ;
    ancess[1][0] = 1 ;
    Dfs(1,0) ;
    scanf("%d" , &m) ;
    for (int i = 1 ; i <= m ; i ++) {
        int u , v ;
        scanf("%d%d" , &u , &v) ;
        printf("%d\n" , LCA(u,v)) ;
    }
}

void code () {
    int q = 0 ;
    scanf("%d" , &q) ;
    for (int i = 1 ; i <= q ; i ++) {
        enter () ;
        process (i) ;
        reset () ;
    }
}

int main () {
    #ifdef OFF_LINE
        freopen("LCA.inp" , "r" , stdin) ;
        freopen("LCA.out" , "w" , stdout) ;
    #endif

    code () ;

    return 0 ;
}
