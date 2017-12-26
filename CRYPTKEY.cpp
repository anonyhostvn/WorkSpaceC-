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
#define base (int) 1e9 + 7
#define maxN 50005

using namespace std ;

int n  ;
long long a[maxN] , k ;

vector<long long> factory_prime(long long x)
{
    vector<long long> res ; res.clear() ;
    for (long long i = 2 ; i * i <= x ; i ++) if (x % i == 0) {
        long long tmp = 1 ;
        while (x % i == 0) tmp *= i , x /= i ;
        res.push_back(tmp) ;
    }
    if (res.size() == 0 || x > 1) res.push_back(x) ;
    return res ;
}

long long GCD(long long a , long long b)
{
    while (b != 0) {
        long long tmp = a % b ;
        a = b ; b = tmp ;
    }
    return a ;
}

void enter()
{
    cin >> n ;
    forinc(i,1,n) cin >> a[i] ;
    cin >> k ;
    vector<long long> p = factory_prime(k) ;
    bool ok = true ;
    forv(i,p) {
        long long tmp  = 0 ;
        forinc(j,1,n) if (a[j] % p[i] == 0) tmp = GCD(tmp,a[j]) ;
        ok &= (tmp > 0 && k % tmp == 0) ;
    }
    cout << ((ok) ? "YES" : "NO") << endl ;
}

int main()
{
    //freopen("CRYPTKEY.inp" , "r" , stdin) ;
    int t ; cin >> t ;
    while (t--) enter() ;
    return 0 ;
}
