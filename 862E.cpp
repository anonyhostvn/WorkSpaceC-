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
#define maxN 100001
#define oo 200000000000000000

using namespace std ;

int n , m , q ;
long long suma = 0 , b[maxN] , ans[maxN] ;
vector<pair<long long , int> > qsum ;
vector<long long> seg ;

int enter()
{
    cin >>  n >> m >> q ;
    forinc(i,1,n) {
        int x  ; cin >> x ;
        suma += pow(-1,i-1) * x ;
    }
    long long sum = 0 ;
    forinc(i,1,m) {
        int x = 0 ; cin >> x ;
        b[i] = b[i-1] + pow(-1,i-1) * x  ;
    }
    return 0 ;
}

int prepare()
{
    forinc(i,0,m-n) if (i % 2 == 0) seg.push_back(b[n+i] - b[i]) ; else seg.push_back(b[i]-b[i+n]) ;
    sort(seg.begin(),seg.end()) ;
    qsum.push_back(mk(suma,0)) ;
    forinc(i,1,q) {
        int x , l , r ; cin >> l >> r >> x ;
        if ((r-l+1) % 2 == 0) qsum.push_back(mk(suma,i)) ;
        else {
            suma += pow(-1,l-1) * x ;
            qsum.push_back(mk(suma,i)) ;
        }
    }
    sort(qsum.begin(),qsum.end()) ;
    return 0 ;
}

int process()
{
    prepare() ;
    //forv(i,qsum) cout << qsum[i].fi << " " << qsum[i].se << endl ;
    //forv(i,seg) cout << seg[i] << endl ;
    int j = 0 ;
    forv(i,qsum) {
        long long res = oo ;
        while (j <= m-n-1 && seg[j] <= qsum[i].fi) j ++ ;
        if (j > 0) res = min(res,abs(qsum[i].fi-seg[j-1])) ;
        if (j <= m-n) res = min(res,abs(qsum[i].fi-seg[j])) ;
        ans[qsum[i].se] = res ;
    }
    forinc(i,0,q) cout << ans[i] << endl ;
    return 0 ;
}

int main()
{
    //freopen("862E.inp" , "r" , stdin) ;
    enter() ;
    process() ;
    return 0 ;
}
