#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i--)
#define forv(i,u) for (int i = 0 ; i < u.size() ; i ++)
#define pii pair<int,int>
#define fi first
#define se second
#define oo (long long) 1e18

using namespace std  ;

long long a , k , b , m , n , maxday = 0 ;

bool check(long long mid)
{
    if (mid == 0) return false ;
    long long daya = mid - mid / k , dayb = mid - mid / m ;
    if (a > n / daya || b > n / dayb || a * daya > n - b * dayb) return true;
    return  a * daya + b * dayb >= n ;
}

void enter()
{
    cin >> a >> k >> b >> m >> n ;
    maxday = max(oo / a , oo / b) ;
    long long l = 0 , r = oo , res = 0 ;
    while (l <= r) {
        long long mid = (l+r) / 2 ;
        if (check(mid)) res = mid , r = mid - 1 ;
        else l = mid + 1 ;
    }
    cout << res << endl ;
}
int main()
{
    //freopen("renew.inp" , "r" , stdin) ;
    enter() ;
    return 0 ;
}

