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
#define oo (int) 1e9 + 7

using namespace std ;

int main()
{
    //freopen("873A.inp" , "r" , stdin) ;
    int n , k , x ; cin >> n >> k >> x ;
    int res = k * x ;
    forinc(i,1,n) {
        int tmp = 0 ; cin >> tmp ;
        if (i <= n-k) res += tmp ;
    }
    cout << res  ;
    return 0 ;
}
