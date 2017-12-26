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
#define oo (long long) 1e15
#define maxN 200005

using namespace std ;

int n , m , a[maxN] ;
string st ;

void enter()
{
    cin >> n >> m;
    cin >>st ;
    forinc(i,1,n) a[i] = (int) st[i-1] - (int) '0' ;
}

long long x[maxN] , g[maxN] , f[maxN] ;

void prepare()
{
    forinc(i,1,n) x[i] = ((long long) x[i-1] * 10 + (long long) i * a[i]) % m ;
}

void process()
{
    prepare();
    forinc(i,1,n) f[i] = f[i-1] + x[i] , f[i] %= m ;
    cout << f[n] << endl ;
}

int main()
{
    freopen("SUM.inp" , "r" , stdin) ;
    freopen("SUM.out" , "w" , stdout) ;
    enter() ;
    process() ;
    return 0 ;
}
