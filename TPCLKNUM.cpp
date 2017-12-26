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
#define base 1000000007
#define maxN 100005

using namespace std ;

int n , k ;
long long f[maxN] , s[maxN] ;

long long get(int l , int r)
{
    long long res = 0 ;
    if (l <= 0) return s[r] ;
    return (s[r] - s[l-1] + base) % base ;
}

long long all_num()
{
    if (n == 1) return 10 ;
    long long res = 9 ;
    forinc(i,1,n-1) res *= 10 , res %= base ;
    return res ;
}

void enter()
{
    cin >> n >> k ;
    f[0] = 1 ; s[0] = 1 ;
    f[1] = 8 ; s[1] = 9 ;
    forinc(i,2,n) {
        f[i] = get(i-k,i-1) * 9 ; f[i] %= base ;
        s[i] = s[i-1] + f[i] ; s[i] %= base ;
    }
    cout << (all_num() - get(n-k+1,n) + base) % base << endl ;
}

int main()
{
    //freopen("TPCLKNUM.inp", "r" ,  stdin) ;
    enter() ;
    return 0 ;
}
