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

long long a , b , c , d ;

long long gcd(long long a , long long b)
{
    while (b) {
        long long tmp = a % b ;
        a = b ; b = tmp ;
    }
    return a ;
}

int enter()
{
    cin >> a >>  b >> c >> d ;
    cout << abs(a * d - b * c) - gcd(a,c) - gcd(b,d) + 1 ;
    return 0 ;
}

int main()
{
    freopen("npairs.inp" , "r" , stdin) ;
    freopen("npairs.out" , "w" , stdout) ;
    enter() ;
    return 0 ;
}
