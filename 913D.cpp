#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)
#define forv(j,u) for (int j = 0 ; j < u.size() ; j++)
#define fi first
#define se second
#define pii pair<int,int>
#define pli pair<long long , int>

template <class _T> bool maximize(_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize(_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

const int ooit = 2e9 ;
const long long ooll = 1e15 ;

using namespace std ;


int fastRead() {
    char c ; int res = 0 ;
    for (c = getchar() ; c < '0' || c > '9' ; c = getchar()) ;
    for ( ; c >= '0' && c <= '9' ; c = getchar()) res*= 10 , res += c - '0' ;
    return res ;
}

#define maxN 200005

struct node {
    int a , t , pos ;
    bool operator < (node &other) {
        return t < other.t ;
    };
};

int n , T ;
node c[maxN] ;

void enter () {
    n = fastRead() ; T = fastRead() ;
    forinc(i,1,n) c[i].a = fastRead() , c[i].t = fastRead() , c[i].pos = i ;
}

vector<int> ans ;

bool check(int X) {
    int cnt = 0 ; long long stime = 0 ;
    forinc(i,1,n) if (c[i].a >= X) {
        if (stime + c[i].t > T) break ;
        stime += c[i].t ; cnt ++ ;
    }

    return cnt >= X ;
}

void process () {
    sort(c + 1 , c + 1 + n) ;
    int l = 0 , r = n , res = -1 ;

    while (l <= r) {
        int mid = (l+r) / 2 ;
        if (check(mid)) l = mid + 1 , res = mid ; else r = mid - 1 ;
    }

    cout << res << endl ;

    vector<int> ans ; long long stime = 0 ; int cnt = 0  ;
    forinc(i,1,n) if (c[i].a >= res) {
        if (stime + c[i].t > T) break  ;
        stime += c[i].t ; ans.push_back(c[i].pos) ; cnt ++ ;
        if (cnt >= res) break ;
    }

    cout << ans.size() << endl ;
    for (auto tmp : ans) cout << tmp << " " ; cout << endl ;
}

int main () {
    //freopen("913.inp" , "r" , stdin) ;

    enter () ;
    process () ;
    return 0 ;
}
