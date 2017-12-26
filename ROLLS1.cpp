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

int n , m ;
map<int,int> f ;

void enter () {
    cin >> n >> m ;
    long long res = 0 , ans = ooll ;
    forinc(i,1,n) { int x ; cin >> x ; f[(x % m + m) % m] ++ ; res += (x % m + m) % m ; }
    int last = 0 ;
    for (auto i : f)
        res += (long long) n * abs(i.fi - last) ,
        res -= (long long) i.se * m , minimize(ans,res) ,
        last = i.fi ;
    cout << ans << endl ;
}

int main () {
    freopen("Test.inp" , "r" , stdin) ;
    enter() ;
    return 0 ;
}
