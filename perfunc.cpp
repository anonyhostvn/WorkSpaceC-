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

int enter()
{
    long long a , b , res = 0 ;
    cin >> a >> b ;
    forinc(i,1,a) {
        long long tmp = (int) sqrt((long long) i * i + b) ;
        res += tmp - i ;
    }
    cout << res ;
    return 0 ;
}

int main()
{
    freopen("perfunc.inp" , "r" , stdin) ;
    freopen("perfunc.out" , "w" , stdout) ;
    enter() ;
    return 0 ;
}
