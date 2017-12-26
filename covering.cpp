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

int n ;
pii a[100001] ;

int enter()
{
    cin >> n ;
    forinc(i,1,n) cin >> a[i].se >> a[i].fi ;
    sort(a+1,a+1+n) ;
    return 0 ;
}

vector <int> s ;

int process()
{
    forinc(i,1,n){
        while (s.size() > 0 && a[i].se >= a[s.back()].se) s.pop_back() ;
        s.pb(i) ;
    }
    long long res = (long long) a[s[0]].fi * a[s[0]].se ;
    for (int i = 1 ; i < s.size() ; i ++) res += (long long) (a[s[i]].fi - a[s[i-1]].fi) * a[s[i]].se ;
    cout << res ;
    return 0 ;
}

int main()
{
    freopen("covering.inp" , "r" , stdin) ;
    freopen("covering.out" , "w" , stdout) ;
    enter() ;
    process() ;
    return 0 ;
}
