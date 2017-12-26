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

using namespace std  ;

ull a , b , k ;

ull multi(ull s , ull n)
{
    if (n == 0) return 0 ;
    if (n == 1) return s ;
    ull tmp = multi(s,n/2) ;
    if (n % 2 == 0) return ((ull) tmp * 2 ) % b ;
    return (((ull) tmp * 2) % b + s) % b;
}

ull power(ull s ,ull n)
{
    if (n == 1) return s ;
    if (n == 0) return 1 ;
    ull tmp = power(s,n/2) ;
    if (n % 2 == 0) return multi(tmp,tmp) ;
    return multi(multi(tmp,tmp) , s) ;
}

void process()
{
    cout << ((multi(a,power(10,k-1)) % b )* 10) / b ;
}

int main()
{
    freopen("DIGIT.inp"  , "r" , stdin) ;
    freopen("DIGIT.out" , "w" , stdout) ;
    cin >> a >> b >> k ;
    process() ;
    return 0 ;
}
