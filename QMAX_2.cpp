#include <bits/stdc++.h>
#define maxN 50004

using namespace std ;

int n , m , q ;

void enter () {
    scanf("%d%d" , &n , &m) ;
}

struct SegmentTree {
    int val[4 * maxN] , rem[4 * maxN] ;

    void trans (int s , int l , int r) {
        rem[2 * s] += rem[s] ; rem[2 * s + 1] += rem[s] ;
        val[2 * s] += rem[s] ; val[2 * s + 1] += rem[s] ;
        rem[s] = 0 ;
    }

    void updateRange(int s , int l , int r , int u , int v , int k) {
        if (r < u || v < l) return ;
        if (u <= l && r <= v) {
            rem[s] += k ;
            val[s] += k ;
            return ;
        }
        trans(s,l,r) ;
        int mid = (l+r) / 2 ;
        updateRange(2 * s , l , mid , u , v , k) ;
        updateRange(2 * s + 1 , mid + 1 , r , u , v , k) ;
        val[s] = max(val[2 * s] , val[2 * s + 1]) ;
    }

    int getMax(int s , int l , int r , int u , int v) {
        if (r < u || v < l) return 0 ;
        if (u <= l && r <= v) return val[s] ;
        trans(s,l,r) ;
        int mid = (l+r) / 2 ;
        return max(getMax(2 * s , l , mid , u , v) , getMax(2 * s + 1 , mid + 1 , r , u , v)) ;
    }
};

SegmentTree GreenTree ;

void process () {
    for (int i = 1 ; i <= m ; i ++) {
        int u , v , k ;
        scanf("%d%d%d" , &u , &v , &k) ;
        GreenTree.updateRange(1,1,n,u,v,k) ;
    }

    int q ; scanf("%d" , &q) ;
    for (int i = 1 ; i <= q ; i ++) {
        int u , v ;
        scanf("%d%d" , &u , &v) ;
        printf("%d\n" , GreenTree.getMax(1,1,n,u,v)) ;
    }
}

void code () {
    enter () ;
    process () ;
}

int main () {
    #ifdef OFF_LINE
        freopen("QMAX.inp" , "r" , stdin) ;
        freopen("QMAX.out" , "w" , stdout) ;
    #endif // OFFLINE

    code () ;
    return 0 ;
}
