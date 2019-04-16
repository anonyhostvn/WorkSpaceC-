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

int fastRead() {
    char c ; int res = 0 ;
    for (c = getchar() ; c < '0' || c > '9' ; c = getchar()) ;
    for ( ; c >= '0' && c <= '9' ; c = getchar()) res*= 10 , res += c - '0' ;
    return res ;
}

#define maxN 300005

int n  ;
pii a[maxN] ;

void enter () {
    n = fastRead() ;
    forinc(i,1,n) a[i].fi = fastRead() , a[i].se = fastRead() ;
}

void prepare () {
    sort(a + 1 , a + 1 + n , [] (pii a , pii b) {
         return a.se < b.se ;
         }) ;

    //forinc(i,1,n) cout << a[i].fi << " " << a[i].se << endl ;
}

int solve(int id) {
    long long sum = a[id].se - a[id].fi ;
    vector<int> p ;
    forinc(i , id + 1 , n) p.push_back(a[id].se - a[i].fi) ;
    sort(p.begin() , p.end() , [] (int a , int b) {
         return a < b ;
         }) ;

    int res = 1 ;
    while (!p.empty() && p.back() >= 0) sum += p.back() , p.pop_back()  , res ++ ;
    while (!p.empty() && sum + p.back() >= 0) sum += p.back() , p.pop_back() , res ++ ;
    if (sum >= 0) return res ; return 0 ;
}

void sub1 () {
    prepare () ;

    int res = 0 ;
    forinc(i,1,n) maximize(res , solve(i)) ;

    cout << res << endl ;
}

int f[maxN] ;
priority_queue<int> s ;

bool check(int len) {
    s.clear() ;
    fordec(i,n,n-len+1) f[i] = f[i+1] + a[i].fi , s.insert() ;
}

void sub2 () {
    prepare () ;

    int l = 1 , r = n , res = 0 ;
    while (l <= r) {
        int mid = (l+r) / 2 ;
        if (check(mid)) l = mid + 1 , res = mid ; else r = mid - 1 ;
    }

    cout << res << endl ;
}

void process () {
}

int main () {
    freopen("BACTERIUM.inp" , "r" , stdin) ;
    freopen("BACTERIUM.out" , "w" , stdout) ;
    enter () ;
    process () ;
    return 0 ;
}
