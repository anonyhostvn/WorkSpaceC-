#include <bits/stdc++.h>
#define debug(x) cerr << #x << " : " << x << endl ;
#define maxN 50004

using namespace std ;

int n , q , highCow[maxN] ;

void enter () {
    scanf("%d%d" , &n , &q) ;
    for (int i = 1 ; i <= n ; i ++) scanf("%d" , &highCow[i]) ;
}

int rmqMax[maxN][22] , rmqMin[maxN][22] ;

void buildRMQ () {
    for (int i = 1 ; i <= n ; i ++) rmqMax[i][0] = rmqMin[i][0] = highCow[i] ;
    for (int step = 1 ; step <= (int) log2(n) + 1 ; step ++)
    for (int i = 1 ; i <= n ; i ++) if (i + (int) pow(2,step) - 1 <= n) {
        int leng = (int) pow(2,step-1) ;
        rmqMax[i][step] = max(rmqMax[i][step-1] , rmqMax[i + leng][step-1]) ;
        rmqMin[i][step] = min(rmqMin[i][step-1] , rmqMin[i + leng][step-1]) ;
    }
}

int getMax(int u , int v) {
    int leng = v - u + 1 , step = log2(leng) ;
    return max(rmqMax[u][step] , rmqMax[v-(int) pow(2,step) + 1][step]) ;
}

int getMin(int u , int v) {
    int leng = v - u + 1 , step = log2(leng) ;
    return min(rmqMin[u][step] , rmqMin[v-(int) pow(2,step) + 1][step]) ;
}

void process () {
    buildRMQ() ;
    for (int i = 1 ; i <= q ; i ++) {
        int u , v ;
        scanf("%d%d" , &u , &v) ;
        printf("%d\n" , getMax(u,v) - getMin(u,v)) ;
    }
}

void code () {
    enter () ;
    process () ;
}

int main () {
    #ifdef OFF_LINE
        freopen("NKLINEUP.inp" , "r" , stdin) ;
        freopen("NKLINEUP.out" , "w" , stdout) ;
    #endif // OFF_LINE


    code () ;

    return 0 ;
}
