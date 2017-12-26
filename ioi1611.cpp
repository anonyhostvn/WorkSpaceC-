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
#define maxN 200005

using namespace std ;

int n , l , u ;
pii a[maxN] ;
long long s[maxN] ;

void enter() {
    cin >> n >> l >> u ;
    forinc(i,1,n) cin >> a[i].fi ;
    forinc(i,1,n) a[i].se = i - 1 ;
    sort(a+1,a+1+n) ;
    forinc(i,1,n) s[i] = s[i-1] + a[i].fi ;
}

void process() {
    int k = 0 , Lres = 0 , Rres = -1 ;
    forinc(i,1,n) if (s[i] <= u && s[n] - s[n-i] >= l) {k = i ; break ; }
    if (k > 0) forinc(i,1,n-k+1) if (s[i+k-1] - s[i-1] >= (long long) l && s[i+k-1] - s[i-1] <= (long long) u) { Lres = i ; Rres = i + k - 1 ; }
    vector<int> ans ; forinc(i,Lres,Rres) ans.push_back(a[i].se) ; sort(ans.begin(),ans.end()) ;
    cout << ans.size() << endl ;
    for (auto i : ans) cout << i << " " ;
}

int main(){
    //freopen("ioi1611.inp" , "r" , stdin) ;
    enter() ;
    process() ;
    return 0 ;
}
