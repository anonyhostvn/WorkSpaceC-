#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)
#define forv(j,u) for (int j = 0 ; j < u.size() ; j++)
#define pb push_back
#define pf push_front
#define fi first
#define se second

using namespace std ;

int n , m, p[1001] ;

int enter()
{
    cin >> n >> m ;
    forinc(i,1,m) cin >> p[i] ;
    return 0 ;
}

int process()
{
    sort(p+1,p+1+m) ;
    long long res = 0 , tres = 0 ;
    forinc(i,1,m) if (res < (long long)p[i] * min(n,(m-i+1))) {
        res = (long long) p[i] * min(n,(m-i+1)) ;
        tres =  p[i] ;
    }
    cout << tres << " " << res ;
    return 0 ;
}

int main()
{
    //freopen("AUCTION.inp" , "r" , stdin) ;
    enter() ;
    process() ;
}
