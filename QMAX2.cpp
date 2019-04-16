#include <bits/stdc++.h>
#define maxN 50004
using namespace std ;

int n , m ;

struct SegmentTree {
    int val[4 * maxN] , rem[4 * maxN] ;

    void trans(int s , int l , int r) {
        rem[2 * s] += rem[s] ; rem[2 * s + 1] += rem[s] ;
        val[2 * s] += rem[s] ; val[2 * s + 1] += rem[s] ;
        rem[s] = 0 ;
    }

    void updateRange(int s , int l , int r , int u , int v , int k) {
        if (r < u || v < l) return ;
        if (u <= l && r <= v) {
            val[s] += k ;
            rem[s] += k ;
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
        trans(s , l , r) ;
        int mid = (l+r) / 2 ;
        return max(getMax(2 * s , l , mid , u , v) , getMax(2 * s + 1 , mid + 1 , r , u ,v)) ;
    }
} ;

SegmentTree GreenTree ;

void code ()  {
    scanf("%d%d" , &n , &m) ;
    for (int i = 1 ; i <= m ; i ++) {
        int query , u , v , k ;
        scanf("%d" , &query) ;
        if (query) {
            scanf("%d%d" , &u , &v) ;
            printf("%d\n" , GreenTree.getMax(1,1,n,u,v)) ;
        } else {
            scanf("%d%d%d" , &u , &v , &k) ;
            GreenTree.updateRange(1,1,n,u,v,k) ;
        }
    }
}

int main () {
    #ifdef OFF_LINE
        freopen("QMAX2.inp" , "r" , stdin) ;
        freopen("QMAX2.out" , "w" , stdout) ;
    #endif // OFF_LINE

    code () ;

    return 0 ;
}
