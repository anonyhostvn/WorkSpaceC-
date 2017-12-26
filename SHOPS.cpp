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
#define maxN 500005

using namespace std ;

typedef pair<long long , int> pli ;
int n , s ;
long long sum[maxN] ;

int get_input() {int x ; scanf("%d" , &x); return x ; }

void enter() {
    n = get_input() ; s = get_input() ;
    forinc(i,1,n) sum[i] = sum[i-1] + (long long) get_input() ;
}

map<long long , int> f ;
map<long long , int> :: iterator it ;

int tsum[maxN] , m = 0 ;

void prepare() {
    forinc(i,0,n) f[sum[i]] = 0 , f[sum[i] + s] = 0 ;
    int cnt = 0 ;
    for (auto& it : f) it.se = ++cnt ; m = cnt ;
    forinc(i,0,n) tsum[i] = f[sum[i]+s] , sum[i] = f[sum[i]] ;
    //forinc(i,0,n) cout << sum[i] << " " ; cout << endl ;
}

int BIT[2 * maxN] ;

void update(int i , int x) {
    for ( ; i > 0 ; i -= i & -i) BIT[i] = min(BIT[i],x) ;
}

int get(int i) {
    int res = ooit ;
    for ( ; i <= m ; i += i & -i) res = min(res,BIT[i]) ;
    return res ;
}

void process() {
    prepare() ;
    forinc(i,1,m) BIT[i] = ooit ;
    int res = 0 , tres = 0 ;
    forinc(i,0,n) {
        int t = get(sum[i]) ;
        if (i - t > res) res = i - t , tres = t + 1 ; ///else if (i - t == res) tres = min(tres,t+1) ;
        update(tsum[i],i) ;
    }
    cout << res << " " << tres << endl ;
}

int main() {
    ios_base::sync_with_stdio(false) ; cin.tie() ; cout.tie() ;
    freopen("SHOPS.inp" , "r" , stdin) ;
    freopen("SHOPS.out" , "w" , stdout) ;
    enter() ;
    process() ;
    return 0 ;
}
