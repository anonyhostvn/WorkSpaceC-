
struct TsegmentTree {
    long long val[4  * maxN] , rem[4 * maxN] ;

    void set_node (int s , int l , int r , int x) {
        rem[s] += x ;
        val[s] += x * (r - l + 1) ;
    }

    void trans(int s , int l , int r) {
        if (rem[s] == 0) return ;
        rem[2 * s] += rem[s] ; rem[2 * s + 1] += rem[s] ;
        int mid = (l+r) / 2 ;
        val[2 * s] += rem[s] * (mid - l + 1) ; val[2 * s + 1] += rem[s] * (r - mid) ;
        rem[s] = 0 ;
    }

    void update(int s , int l , int r , int u , int v , long long x) {
        if (r < u || v < l) return ;
        if (u <= l && r <= v) {
            set_node(s,l,r,x) ;
            return ;
        }

        trans(s,l,r) ;
        int mid = (l+r) / 2 ;

        update(2 * s , l , mid , u , v , x) ;
        update(2 * s + 1 , mid + 1 , r , u , v , x) ;
        val[s] = val[2 * s] + val[2 * s + 1] ;
    }

    long long get(int s , int l , int r , int u , int v) {
        if (r < u || v < l) return 0 ;
        if (u <= l && r <= v) return val[s] ;
        trans(s , l , r) ;
        int mid = (l+r) / 2 ;
        return get(2 * s , l , mid , u , v) + get(2 * s  + 1 , mid + 1 , r , u , v) ;
    }
} tree ;

void prepare () {
    sort(a + 1 , a + 1 + n , [] (pii a , pii b) {
         return a.se < b.se ;
         } ) ;
    forinc(i,1,n) tree.update(1,1,n,i,i,-a[i].fi) ;
}
