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

using namespace std ;

int n , k ;

void enter() {
    cin >> n >> k ; int tmp = 0 ;
    if (n < k) { cout << 2 * k << endl ; return ; }
    if (n % k == 0) {cout << n / k * 2 << endl ; return ; }
    int res = (n / k - 1) * 2 ; n = n % k + k ;
    res += 2 + (n - n % k) / k ;
    cout << res << endl ;
}

int main() {
    freopen("test.inp" , "r" , stdin) ;
    //freopen("test.out" , "w" , stdout) ;
    enter() ;
    return 0 ;
}

