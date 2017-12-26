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
#define maxN 100005

using namespace std ;

int n , k , m , a[maxN] ;

void enter() {
    cin >> n >> k >> m ;
    forinc(i,1,n) cin >> a[i] ;
}

vector<pii> s ;
int p = -1 , t = 0 , sum = 0 , tsum = 0 ;

void prepare() {
    s.push_back({a[1],1}) ;
    if (s.back().se == k) s.pop_back() ;
    forinc(i,2,n) {
        if (s.back().fi == a[i]) s.back().se ++ ; else s.push_back({a[i],1}) ;
        if (s.back().se == k) s.pop_back() ;
    }
    t = s.size() ;
    forv(i,s) if (s[i].fi != s[t-i-1].fi || s[i].se + s[t-i-1].se != k) {
        if (s[i].fi == s[t-1-i].fi && s[i].se + s[t-i-1].se >= k) tsum += (long long) ((s[i].se + s[t-i-1].se) / k) * k ;
        break ; }
    else p = i , tsum += k ;
    forv(i,s) sum += s[i].se ;
    if (p >= t / 2) p = t - 1 ;
}

void process() {
    prepare() ;
    //cout << p << endl ;
    //cout << t / 2 - 1 << endl ;
    if (p == t - 1) {
        if (m % 2 == 0) cout << 0 << endl ; else cout << sum << endl ;
        return ;
    }
    if (t % 2 != 0 && p == t / 2 - 1) {
        int tmp = ((long long) s[t/2].se * m) % k ; //cout << s[t/2].se * 9 << endl ;
        cout << sum - s[t/2].se + tmp ;
        return ;
    }
    if (p != -1 && t % 2 == 0 && p == t / 2 - 1) {cout << sum << endl ; return ; }
    cout << tsum << endl ;
    cout << (long long) n * m - (long long) tsum * (m-1) << endl ;
}

int main() {
    //freopen("878B.inp" , "r" , stdin) ;
    enter() ;
    process() ;
    return 0 ;
}
