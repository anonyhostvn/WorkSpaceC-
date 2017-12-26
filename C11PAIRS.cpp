#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)
#define forv(j,u) for (int j = 0 ; j < u.size() ; j++)
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define mk make_pair

using namespace std ;

int n , a[500001] ;

int enter()
{
    ios_base::sync_with_stdio(false) ;
    cin >> n ;
    forinc(i,1,n) cin >> a[i] ;
}
stack<pair<int,int> > s ;

int process()
{
    long long res = 0 ;
    forinc(i,1,n){
        int cnt = 1 ;
        while (!s.empty() && a[i] >= a[s.top().fi]) {
            cnt += s.top().se * (int) (a[i] == a[s.top().fi]) ;
            res += s.top().se ;
            s.pop() ;
        }
        if (!s.empty()) res ++ ;
        s.push(mk(i,cnt)) ;
    }
    cout << res ;
}

int main()
{
    //freopen("C11PAIRS.inp" , "r" , stdin) ;
    enter() ;
    process() ;
}
