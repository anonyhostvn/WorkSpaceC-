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

#define maxN 100005

struct node {
    int h , s, e ;
} per[maxN] ;

struct node_2 {
    int h , t ;
} tourist[maxN] ;

int h , c , q ;

int fastRead() {
    char c ; int res = 0 ;
    for (c = getchar() ; c < '0' || c > '9' ; c = getchar()) ;
    for ( ; c >= '0' && c <= '9' ; c = getchar()) res*= 10 , res += c - '0' ;
    return res ;
}

void enter () {
    h = fastRead() ; c = fastRead() ; q = fastRead();
    forinc(i,1,c) per[i].h = fastRead() , per[i].s = fastRead() , per[i].e = fastRead() ;
    forinc(i,1,q) tourist[i].h = fastRead() , tourist[i].t = fastRead() ;
}

map<int,int> rr ;

void prepare () {
    rr[h] = 0 ;
    forinc(i,1,c) rr[per[i].s] = 0 , rr[per[i].e] = 0 ;
    forinc(i,1,q) rr[tourist[i].t] = 0 ;

    int cnt = 0 ;
    for (auto &tmp : rr) tmp.se = ++cnt ;
    h = rr[h] ;
    forinc(i,1,c) per[i].s = rr[per[i].s] , per[i].e = rr[per[i].e] ;
    forinc(i,1,q) tourist[i].t = rr[tourist[i].t] ;
}

struct Tinterval {
    int val[4 * 4 * maxN] , rem[4 *4 * maxN];

    void reset() {
        memset(val , 0 , sizeof(val)) ;
        memset(rem , 0 , sizeof(rem)) ;
    }

    void set_node (int s , int k) {
        maximize(val[s] , k) ;
        maximize(rem[s] , k) ;
    }

    void trans(int s) {
        if (rem[s] == 0) return ;
        set_node(2 * s , rem[s]) ;
        set_node(2 * s + 1 , rem[s]) ;
        rem[s] = 0 ;
    }

    void update(int s , int l , int r , int u , int v , int k) {
        if (r < u || v < l) return ;
        if (u <= l && r <= v) {
            set_node(s,k) ;
            return ;
        }
        trans(s) ;

        int mid = (l+r) / 2 ;
        update(2 * s , l , mid , u , v , k) ;
        update(2 * s + 1 , mid + 1 , r , u , v , k) ;
        val[s] = max(val[2 * s] , val[2 * s + 1]) ;
    }

    int get(int s , int  l , int r , int u , int v) {
        if (r < u || v < l) return 0 ;
        if (u <= l && r <= v) return val[s] ;
        trans(s) ; int mid = (l+r) / 2 ;
        return max(get(2 * s , l , mid , u , v) , get(2 * s + 1 , mid + 1 , r , u ,v)) ;
    }
} tree ;

void Build_IT() {
    tree.reset() ;
    forinc(i,1,c) tree.update(1,1,h,per[i].s,per[i].e,per[i].h) ;
}

void process () {
    prepare () ;
    Build_IT() ;
    forinc(i,1,q) {
        int maxH = tree.get(1,1,h,tourist[i].t,tourist[i].t) ;
        if (maxH == 0 || maxH < tourist[i].h) cout << "YES" ; else cout << "NO" ; cout << endl ;
    }
}

int main () {
    freopen("VISITING.inp" , "r" , stdin) ;
    freopen("VISITING.out" , "w" , stdout) ;
    enter () ;
    process () ;
    return 0 ;
}
