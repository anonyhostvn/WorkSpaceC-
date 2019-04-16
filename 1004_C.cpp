#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)
#define forv(j,u) for (int j = 0 ; j < u.size() ; j++)
#define fi first
#define se second
#define pii pair<int,int>

template <class _T> bool maximize(_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize(_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

const int ooit = 2e9 ;
const long long ooll = 1e15 ;
const int base = 1000000007 ;

using namespace std ;

const int maxN = 100005 ;

int n , a[maxN] ;

void enter () {
    cin >> n ;
    forinc(i,1,n) cin >> a[i] ;
}

int R_first_id[maxN] , L_first_id[maxN] ;

void init () {
    forinc(i,1,n) if (L_first_id[a[i]] == 0) L_first_id[a[i]] = i ;
    fordec(i,n,1) if (R_first_id[a[i]] == 0) R_first_id[a[i]] = i ;
}

struct BIT_tree {
    int BIT[maxN] ;
    BIT_tree () {
        memset(BIT , 0 , maxN) ;
    }
    void update (int id) {
        for (int i = id ; i > 0 ; i -= (i & (-i))) BIT[i] ++ ;
    }
    int get(int id) {
        int res = 0 ;
        for (int i = id ; i <= n ; i += (i & (-i))) res += BIT[i] ;
        return res ;
    }
} tree ;

void process () {
    init() ;
    forinc(i,0,100000) if (R_first_id[i] > 0) tree.update(R_first_id[i]) ;
    long long res = 0 ;
    forinc(i,0,100000) if (L_first_id[i] > 0) res += tree.get(L_first_id[i] + 1) ;
    cout << res << endl ;
}

int main () {
    //freopen("1004_C.inp" , "r" , stdin) ;
    enter () ;
    process () ;
    return 0 ;
}
