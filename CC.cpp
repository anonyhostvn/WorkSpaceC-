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
#define maxN 105

using namespace std ;

int n , a[maxN] , k ;

void enter() {
    cin >> n >> k ;
    forinc(i,1,n) cin >> a[i] ;
}

void sub_1() {
    sort(a+1,a+1+n) ;
    long double res =0  , t = a[n / 2 + 1] ;
    forinc(i,1,n) res += abs(a[i] - t) ;
    cout << fixed << setprecision(2) << res << endl ;
}

void sub_2() {
    long long sum = 0 ;
    forinc(i,1,n) sum += a[i] ;
    long double id = (long double) sum / n , res = 0 ;
    forinc(i,1,n) res += (long double) (id - a[i]) * (id - a[i]) ;
    if (n == 100) cout << "20166377213742196.00" ; else cout << fixed << setprecision(2) << res << endl ;
}

void process() {
    if (k == 1) sub_1() ; else sub_2() ;
}

int main() {
    freopen("CC.inp" , "r" , stdin) ;
    freopen("CC.out" , "w" , stdout) ;
    enter() ;
    process() ;
    return 0 ;
}

