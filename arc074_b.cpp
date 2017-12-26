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
#define ooll (long long) 1e18
#define ooit (int) 2e9
#define maxN 100005

using namespace std ;

int n , a[3 * maxN] ;

void enter() {
    cin >> n ;
    forinc(i,1,3*n) cin>> a[i] ;
}

long long f[3 * maxN] , g[3 * maxN] ;

void build_1() {
    priority_queue<int> q ;
    long long sum = 0 ;
    forinc(i,1,n) sum += a[i] , q.push(-a[i]) ; f[n] = sum ;
    forinc(i,n+1,3*n) {
        int tmin = -q.top() ;
        if (tmin < a[i]) sum -= tmin , sum += a[i] , q.pop() , q.push(-a[i]) ;
        f[i] = sum ;
    }
    while (!q.empty()) q.pop() ;
    sum = 0 ; fordec(i,3*n,2*n+1) sum += a[i] , q.push(a[i]) ; g[2 * n + 1] = sum ;
    fordec(i,2*n,1) {
        int tmax = q.top() ;
        if (tmax > a[i]) sum -= tmax , sum += a[i] , q.pop() , q.push(a[i]) ;
        g[i] = sum ;
    }
}

void process() {
    build_1() ;
    long long res = -ooll ;
    forinc(i,n,2*n) res = max(res,f[i] - g[i+1]) ;
    cout << res << endl ;
}

int main() {
    //freopen("arc074_b.inp" , "r" , stdin) ;
    //freopen("arc074_b.out" , "w" , stdout) ;
    enter() ;
    process() ;
    return 0 ;
}
