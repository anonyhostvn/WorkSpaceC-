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
#define maxN 1005

using namespace std ;

int n , a[2*maxN] ;

void enter() {
    cin >> n ;
    if (n <= 1000) forinc(i,1,2*n) cin >> a[i] ;
    if (n <= 1000) sort(a+1,a+1+2*n) ;
}

set<int> s ;
set<int> :: iterator it ;

int solve(int u) {
    int h = abs(a[u] - a[1]) ; s.clear() ;
    forinc(i,1,2 * n) if (i != 1 && i != u) s.insert(a[i]) ;
    while (!s.empty()) {
        it = s.find((*s.begin()) + h) ;
        if (it == s.end()) return 0 ;
        s.erase(it) ; s.erase(s.begin()) ;
    }
    return 1 ;
}

void sub_1() {
    int res = 0 ;
    forinc(i,2,2*n) res += solve(i) ;
    cout << res << endl ;
}

void sub_2() {
    long long res = 1 ;
    for (int i = 2 ; i * i <= n ; i ++) if (n % i == 0) {
        int cnt  = 0 ;
        while (n % i == 0) cnt ++ , n /= i ;
        res *= (long long) (cnt + 1) ;
    }
    if (n > 1) res *= 2 ;
    cout << res << endl ;
}

void process() {
    if (n <= 1000) sub_1() ; else sub_2() ;
}

int main() {
    freopen("GRN.inp" , "r" , stdin) ;
    freopen("GRN.out" , "w" , stdout) ;
    enter() ;
    process() ;
    return 0 ;
}
