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
#define maxN 200001

using namespace std ;

int n ;
pii a[maxN] ;
priority_queue<pii> q ;

int enter()
{
    cin >> n ;
    forinc(i,1,n) cin >> a[i].fi >> a[i].se ;
    sort(a+1,a+1+n) ;
    q.push(mk(-a[1].se,1)) ;
    forinc(i,2,n) {
        if (a[i].fi <= -q.top().fi) {
            if (q.size() == 2) {cout << "NO" ; return 0 ; }
        } else if (q.size() > 0) {
            q.pop() ;
            if (q.size() > 0 && a[i].fi > -q.top().fi) q.pop() ;
        }
        q.push(mk(-a[i].se,i)) ;
    }
    cout << "YES" ;
    return 0 ;
}

int main()
{
    //freopen("845C.inp" , "r" , stdin) ;
    enter() ;
    return 0 ;
}
