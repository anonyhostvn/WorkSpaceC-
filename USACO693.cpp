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

int n , a[maxN] ;

void enter() {
    cin >> n ;
    forinc(i,1,n) cin >> a[i] ;
}

void mini() {
    pii b[maxN] ;
    forinc(i,1,n) b[i].fi = a[i] , b[i].se = i ;
    sort(b+1,b+1+n) ;
    int cnt = 1 ; a[b[1].se] = 1;
    forinc(i,2,n) {
        if (b[i].fi != b[i-1].fi) cnt ++ ;
        a[b[i].se] = cnt ;
    }
}

int BIT[maxN] ;
inline void update(int i , int x) {for ( ; i > 0 ; i -= i & -i) BIT[i] += x ;}
inline int get(int i) {
    int res = 0 ;
    for ( ; i <= n ; i += i & -i) res += BIT[i] ;
    return res ;
}

inline void reset() {forinc(i,1,n) BIT[i] = 0 ; }

int L[maxN] , R[maxN] ;

void prepare() {
    forinc(i,1,n) L[i] = get(a[i]) , update(a[i],1) ;
    reset() ;
    fordec(i,n,1) R[i] = get(a[i]) , update(a[i],1) ;
}

void process() {
    mini() ;
    prepare() ;
    int res =0  ;
    forinc(i,1,n) if ((long double) max(L[i],R[i]) / min(L[i],R[i]) > 2) res ++ ;
    cout << res ;
}

int main () {
    freopen("bphoto.in" , "r" , stdin) ;
    freopen("bphoto.out" , "w" , stdout) ;
    enter() ;
    process() ;
    return 0 ;
}
