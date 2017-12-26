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
#define maxN 305

using namespace std ;

int n , m , a[maxN][maxN] ;

void enter() {
    cin >> n >> m ;
    forinc(i,1,n) forinc(j,1,m) cin >> a[i][j] ;
}

bool era[maxN] ;

int solve() {
    int cnt[maxN] ;
    forinc(i,1,m) cnt[i] = 0 ;
    forinc(i,1,n) {
        bool ok = false ;
        forinc(j,1,m) if (!era[a[i][j]]) {cnt[a[i][j]] ++ ; ok = true ; break ; }
        if (!ok) return ooit ;
    }
    int max_peo = 0 , sport = 0 ;
    forinc(i,1,m) if (max_peo < cnt[i]) sport = i , max_peo = cnt[i] ;
    era[sport] = true ;
    return max_peo ;
}

void process() {
    int res = ooit ;
    forinc(loop,1,m) res = min(res,solve()) ;
    cout << res << endl ;
}

int main() {
    //freopen("agc018_b.inp" , "r" , stdin) ;
    enter() ;
    process() ;
    return 0 ;
}
