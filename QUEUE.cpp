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

#define maxN 50005

int n ;
pii a[maxN] ;

void enter () {
    cin >> n ;
    forinc(i,1,n) cin >> a[i].fi >> a[i].se ;
}

vector<int> b ;

void prepare () {
    forinc(i,1,n) if (n % i == 0) b.push_back(i) ;
}

long long solve(int r , int c) {
    long long res = 0 ;

    sort(a + 1 , a + 1 + n , [] (pii a , pii b) {return a.se < b.se ; } ) ;
    vector<int> f ; forinc(i,0,r-1) forinc(j,1,c) f.push_back(a[i * c + j].se - i) ; sort(f.begin() , f.end()) ;
    int median = f[f.size() / 2] ; forinc(i,0,r-1) forinc(j,1,c) res += abs(a[i * c + j].se - i - median) ;

    sort(a + 1 , a + 1 + n) ; f.clear() ;
    forinc(i,0,c-1) forinc(j,1,r) f.push_back(a[i * r + j].fi - i) ; sort(f.begin() , f.end()) ;
    median = f[f.size() / 2] ; forinc(i,0,c-1) forinc(j,1,r) res += abs(a[i * r + j].fi - i - median) ;

    return res ;
}

void process () {
    prepare () ;
    long long res = ooll ;
    for (auto tmp : b) minimize(res,solve(tmp,n / tmp)) ;
    cout << res << endl ;
}

int main () {
    freopen("QUEUE.inp" , "r" , stdin) ;
    freopen("QUEUE.out" , "w" , stdout) ;
    enter () ;
    process () ;
    return 0 ;
}
