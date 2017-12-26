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
#define maxN 100005

template <class _T> bool maximize(_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize(_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

using namespace std ;

int n , m , T[maxN] , q , maxc = 0 ;
vector<pii> ke[maxN] ;

void enter () {
    cin >> n >> m >> q ;
    forinc(i,1,n) cin >> T[i] ;
    forinc(i,1,m) {
        int u  , v  , c  ; cin >> u >> v >> c ;
        ke[u].push_back({v,c}) ;
        ke[v].push_back({u,c}) ; maximize(maxc , c) ;
    }
}

bool dd[maxN] ;

bool check(int x , int y , int k , int mid) {
    forinc(i,1,n) dd[i] = false ;
    queue<int> q ; q.push(x) ; dd[x] = true ;

    while (!q.empty()) {
        int u = q.front() ; q.pop() ;
        for (auto tmp : ke[u]) if (!dd[tmp.fi] && tmp.se <= mid) dd[tmp.fi] = true , q.push(tmp.fi) ;
    }
    if (!dd[y]) return false ;

    map<int,int> f ; f.clear() ;
    forinc(i,1,n) if (dd[i]) f[T[i]] = 0 ;
    int cnt = f.size() ;

    return cnt >= k ;
}

int solve(int x , int y , int k) {
    int L = 0 , R = maxc , res = -1 ;
    while (L <= R) {
        int mid = (L+R) / 2 ;
        if (check(x,y,k,mid)) R = mid - 1 , res = mid ; else L = mid + 1 ;
    }

    return res ;
}

void process () {
    forinc(i,1,q) {
        int x , y , k ; cin >> x >> y >> k ;
        cout << solve(x,y,k) << endl ;
    }
}

int main () {
    freopen("TRAVEL.inp" , "r" , stdin) ;
    //freopen("TRAVEL.out" , "w" , stdout) ;
    enter () ;
    process () ;
    return 0 ;
}
