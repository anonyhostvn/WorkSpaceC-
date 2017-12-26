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
#define maxN 1000005

using namespace std ;

int n , a[maxN];
string st ;

void enter()
{
    cin >> st ;
    n = st.length() ;
    forinc(i,1,n) a[i] = (int) st[i-1] - (int) '0' ;
}

void process()
{
    long long res = 0 , x = 0 ;
    forinc(i,1,n) x *= 10 , x %= base , x += (long long) a[i] * i , x %= base , res += x , res %= base;
    cout << res << endl ;
}

int main()
{
    //freopen("C11SUM.inp" , "r" , stdin) ;
    enter() ;
    process() ;
    return 0 ;
}
