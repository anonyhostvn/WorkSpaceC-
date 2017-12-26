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

using namespace std ;

int n , q , a[100001] , ql[100001], qr[100001] , t[400001] , nmax = 0 ;
pii c[400001] ;

int enter()
{
    cin >> n >> q ;
    forinc(i,1,n) cin >> a[i] ;
    forinc(i,1,q) cin >> ql[i] >> qr[i] ;
    return 0 ;
}

int mini()
{
    forinc(i,1,n) {
        c[i] .fi = a[i] ;
        c[i].se = i ;
    }
    int cnt = n ;
    forinc(i,1,q) {
        c[++cnt].fi = ql[i] ;
        c[cnt].se = -( i + n ) ;
        c[++cnt].fi = qr[i] ;
        c[cnt].se = i + n ;
    }
    sort(c+1,c+1+cnt) ;
    c[0].fi = -1 ; int d = 0 ;
    forinc(i,1,cnt){
        if (c[i].fi != c[i-1].fi) ++d ;
        if (abs(c[i].se) <= n) a[c[i].se] = d ;
        else {
            if (c[i].se < 0) ql[abs(c[i].se)-n] = d ; else qr[c[i].se-n] = d ;
        }
    }
    nmax = d ;
    return 0 ;
}

int update(int id , int x)
{
    for (int i = id ; i <= nmax ; i += i & -i) t[i] += x ;
    return 0 ;
}

int get(int id)
{
    int res = 0 ;
    for (int i = id ; i > 0 ; i -= i & -i) res += t[i] ;
    return res ;
}

int process()
{
    mini() ;
    forinc(i,1,n)  update(a[i],1) ;
    forinc(i,1,q) cout << get(qr[i]) - get(ql[i]-1) << endl ;
    return 0 ;
}

int main()
{
    freopen("haybales.in", "r" , stdin) ;
    freopen("haybales.out" , "w" , stdout) ;
    enter() ;
    process() ;
    return 0 ;
}
