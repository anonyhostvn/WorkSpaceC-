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

template <class _T> bool maximize(_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize(_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

using namespace std ;

typedef pair<long long , int> pli ;

#define maxN 100005

int n , a[maxN];

int fastRead() {
    char c ; int res = 0 ;
    for (c = getchar() ; c < '0' || c > '9' ; c = getchar()) ;
    for ( ; c >= '0' && c <= '9' ; c = getchar()) res *= 10 , res += c - '0' ;
    return res ;
}

void enter () {
    n = fastRead() ;
    forinc(i,1,n) a[i] = fastRead() ;
}

long long sum = 0 , q = 0 , r = 0 , b[maxN]  ;

void prepare () {
    forinc(i,1,n) sum += a[i] ;
    q = sum / n ; r = sum % n ;
    forinc(i,1,n) a[i] -= q ;
    forinc(i,1,n) b[i] = b[i-1] + a[i] ;
}

struct TsegmentTree{
    pli val[4 * maxN] ;
    long long rem[4 * maxN] ;

    void Init() {
        memset(val , 0 , sizeof(val)) ;
        memset(rem , 0 , sizeof(rem)) ;
    }

    pli combine (pli a , pli b) {
        pli res = (a.fi > b.fi) ? a : b ;
        return res ;
    }

    void Update_node(int s , pli k) {
        val[s].fi += k.fi ;
        val[s].se = (val[s].se == 0) ? k.se : val[s].se ;
        rem[s] += k.fi ;
    }

    void trans(int s) {
        if (rem[s] == 0) return ;
        Update_node(2 * s , {rem[s] , 0 }) ;
        Update_node(2 * s + 1 , {rem[s] , 0})  ;
        rem[s] = 0 ;
    }

    void update(int s , int l , int r , int u , int v , pli k) {
        if (r < u || v < l) return ;
        if (u <= l && r <= v) { Update_node(s , k) ; return ; }
        int mid = (l+r) / 2 ;  trans(s) ;
        update(2 * s , l , mid , u , v  , k) ;
        update(2 * s + 1 , mid + 1 , r , u , v , k) ;
        val[s] = combine(val[2*s] , val[2 * s + 1]) ;
    }

    pli get(int s ,int l , int r , int u , int v) {
        if (r < u || v < l) return {-ooll , -ooll} ;
        if (u <= l && r <= v) return val[s] ;
        int mid = (l+r) / 2 ; trans(s) ;
        return combine(get(2 * s , l , mid , u , v) , get(2 * s + 1 , mid + 1 , r , u , v)) ;
    }
} ;

TsegmentTree treeW , treeB ;

void Init_Tsegment () {
    forinc(i,1,n)
        treeB.update(1 , 1 , n , i , i , {b[i] <= 0 ? -ooll : -b[i] , i}) ;
    long long sum = 0 ;
    fordec(i,n,1) {
        sum += (b[i] > 0) ? 1 : -1 ;
        treeW.update(1 , 1 , n , i , i , {sum , i}) ;
    }
}

struct T_BIT_Tree{
    int val[maxN] ;

    void init() {
        memset(val , 0 , sizeof(val)) ;
    }

    void update(int i , int x) {
        for ( ; i <= n ; i += i & -i) val[i] += x ;
    }

    int get(int i) {
        int res = 0 ;
        for ( ; i > 0 ; i -= i & -i) res += val[i] ;
        return res ;
    }
} ;

T_BIT_Tree treeS ;

void process () {
    prepare () ;
    Init_Tsegment() ;
    forinc(i,1,r) {
        pli tmp = treeW.get(1,1,n,1,n) ;  int id = tmp.se ; treeS.update(id , 1) ;
        treeW.update(1,1,n,id,id,{-ooll , 0}) ;
        treeB.update(1 , 1 , n , id , n , {1 , 0}) ;
        while (true) {
            pli tmp = treeB.get(1 , 1, n , 1 , n) ;
            if (tmp.fi < 0) break ;
            treeW.update(1 , 1 , n , 1 , tmp.se , {-2 , 0 }) ;
            treeB.update(1 , 1 , n , tmp.se , tmp.se , {-ooll , 0}) ;
        }
    }

    long long res = 0 ;
    forinc(i,1,n) res += abs(b[i] - treeS.get(i)) ;
    cout << res << endl ;
}

int main () {
    freopen("ARRANGE.inp" , "r" , stdin) ;
    freopen("ARRANGE.out" , "w" , stdout) ;
    enter () ;
    process () ;
    return 0  ;
}
