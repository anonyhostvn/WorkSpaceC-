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
#define maxN 500001
#define maxA 1000001

using namespace std ;

int n , x , y , a[maxN] , g[maxA] , m = 0  ;
long long f[maxA] ;

void enter()
{
    cin >> n >> x >> y ;
    forinc(i,1,n) cin >> a[i] , m = max(m,a[i]) ;
}

void prepare()
{
    forinc(i,1,n) f[i] ++ , g[i] += a[i] ;
    forinc(i,1,m) f[i] += f[i-1] , g[i] += g[i-1] ;
}

void process()
{
    prepare() ;

}

int main()
{
    return 0 ;
}
