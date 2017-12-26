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
#define maxN 1000005

template <class _T> bool maximize(_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize(_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

using namespace std ;

int n , a[maxN]  , xrot , yrot ;
string st ;

void enter () {
    cin >> n ;
    cin >> st ;
    forinc(i,1,n) if (st[i-1] == 'U') a[i] = 1 ; else if (st[i-1] == 'R') a[i] = 2 ; else if (st[i-1] == 'D') a[i] = 3 ;
    cin >> xrot >> yrot ;
}

int ans[4]  , pos[4] ;

void prepare () {
    forinc(i,1,n) if (pos[a[i]] == 0) pos[a[i]] = i ;
}

bool solve(int x , int direct) {
    int undirect = direct + 2  ;
    if (x < 0) swap(direct , undirect) ;
    ans[undirect] = 0 ; x = abs(x) ;

    int cnt = 0 ; if (cnt == x) {ans[direct] = 0 ; return true ; }

    forinc(i,1,n) {
        cnt += (int) (a[i] == direct) ;
        if (cnt == x) { ans[direct] = i ; return true ; }
    }

    return false ;
}

void process () {
    prepare () ;
    if (!solve(xrot,0)) {cout << -1 << endl ; return ; }
    if (!solve(yrot,1)) {cout << -1 << endl ; return ; }
    forinc(i,0,3) cout << ans[i] << " " ; cout << endl ;
}

int main () {
    freopen("ROBOT.inp" , "r" , stdin) ;
    //freopen("ROBOT.out" , "w" , stdout) ;
    enter() ;
    process () ;
    return 0 ;
}
