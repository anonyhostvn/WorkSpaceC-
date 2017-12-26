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

int n , l , t[maxN] , v[maxN] ;

void enter () {
    cin >> l >> n ;
    forinc(i,1,n) cin >> t[i] >> v[i] ;
}

struct node {
    int pos , w ; long double cwin ;
};

int m = 0 ;
node b[maxN] ;
map<long double , int> f ;

const long long get_(int pos_1 , int pos_2) {
    return (long long) l * (v[pos_2] - v[pos_1]) + (long long) v[pos_2] * v[pos_1] * (t[pos_1] - t[pos_2])  ;
}

void prepare () {
    forinc(i,1,n) b[i].pos = i  ; //, b[i].cwin = (long double) (l / v[i]) + t[i] , f[b[i].cwin] = 0 ;
    //int cnt = 1 ; for (auto& i : f) i.se = ++cnt ; m = cnt ;
    //forinc(i,1,n) b[i].cwin = f[b[i].cwin] ;
    sort(b+1 , b + 1 + n , [] (node a , node b) {
         return  get_(a.pos,b.pos) < 0 ;
    }) ;

    int cnt = 1 ; b[1].w = 1 ;
    forinc(i,2,n) {
        if (get_(b[i].pos,b[i-1].pos) != 0) cnt ++ ;
        b[i].w = cnt ;
    } m = cnt ;
    sort(b + 1 , b + 1 + n , [] (node a , node b) {return t[a.pos] < t[b.pos] ; } ) ;
}

int BIT[maxN] ;

void update_BIT(int i , int x) {
    for ( ; i > 0 ; i -= i & -i) maximize(BIT[i],x) ;
}

int get_BIT(int i) {
    int res = 0 ;
    for ( ; i <= m ; i += i & -i) maximize(res,BIT[i]) ;
    return res ;
}

void process () {
    prepare () ;

    //forinc(i,1,n) cout << b[i].pos << " " << b[i].w << endl ;

    int res = 0 ;
    forinc(i,1,n) {
        int tmp = get_BIT(b[i].w + 1) ;
        res = max(res,tmp + 1) ;
        update_BIT(b[i].w,tmp + 1) ;
    }

    cout << res << endl ;
}

int main () {
    freopen("WALKING.inp" , "r" , stdin) ;
    freopen("WALKING.out" , "w" , stdout) ;
    enter () ;
    process () ;
    return 0 ;
}
