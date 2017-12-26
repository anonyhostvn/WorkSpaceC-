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

#define maxN 200005

int n , a[maxN] ;

int fastRead() {
    int res = 0 ; char c ;
    for (c = getchar() ; c < '0' || c > '9' ; c = getchar()) ;
    for ( ; c >= '0' && c <= '9' ; c = getchar()) res *= 10 , res += c - '0' ;
    return res ;
}

void enter () {
    n = fastRead() ;
    forinc(i,1,n) a[i] = fastRead() ;
}

set<pii> tseg ;
set<int> cid ;
int L[maxN] ;

void prepare () {
    int cnt = 1 , start = 1 ;
    forinc(i,2,n) if (a[i] == a[i-1]) cnt ++ ; else L[start] = cnt , tseg.insert({-cnt , start}) , cid.insert(start) , start = i , cnt = 1 ;
    tseg.insert({-cnt , start}) ; cid.insert(start) ; L[start] = cnt ;
}

void update(int id) {
    auto it = cid.lower_bound(id) ;
    if (it == cid.begin()) { cid.erase(it) ; return ; }

    auto pre = it , nxt = it ; pre-- ; nxt++ ;
    if (nxt == cid.end()) {cid.erase(it) ; return ; }

    if (a[*pre] != a[*nxt]) {cid.erase(it) ; return ; }

    int c_nxt = *nxt , c_pre = *pre ;
    cid.erase(c_nxt) ; cid.erase(id) ;
    tseg.erase(tseg.find({-L[c_pre],c_pre})) ;
    tseg.erase(tseg.find({-L[c_nxt],c_nxt})) ;
    L[c_pre] += L[c_nxt] ; tseg.insert({-L[c_pre] , c_pre}) ;
}

void process () {
    prepare () ;

    int ans = 0 ;
    while (!tseg.empty()) {
        ans ++ ;
        auto tmp = tseg.begin() ; int t = (*tmp).se ; tseg.erase(tmp) ;
        update(t) ;
    }

    cout << ans << endl ;
}

int main () {
    //freopen("899E.inp" , "r" , stdin) ;
    enter () ;
    process () ;
    return 0 ;
}
