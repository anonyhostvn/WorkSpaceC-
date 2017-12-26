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
#define ull unsigned long long

using namespace std ;

ull x , n , m ;

ull multi(ull x , ull y)
{
    x %= m ; y %= m ;
    long double q = (long double) x * y / m ;
    long long r = (long long) ((long long) x * (long long) y - (long long) q * (long long) m) % (long long) m ;
    if (r < 0) r += m ;
    return r ;
}

ull f(ull p , ull n)
{
    if (n == 0) return 0 ;
    if (n == 1) return 1 ;
    if (n % 2 != 0) return (1 + multi(p,f(p,n-1))) % m ;
    ull tmp = f(p,n/2) ; if (n % 2 == 0) return multi(tmp,multi(tmp,p-1) + 2);
}

void process()
{
    cin >> x >> n >> m ;
    ull p = 1 ; while (p <= x) p *= 10 ;
    cout << multi(x % m,f(p,n) % m) << endl ;
}

int main()
{
    freopen("REMAINDER.inp" , "r" , stdin) ;
    freopen("REMAINDER.out" , "w" , stdout) ;
    int t = 0 ; cin >> t ;
    while (t--) process() ;
    return 0 ;
}
