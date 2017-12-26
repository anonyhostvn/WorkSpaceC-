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
#define maxN 100005

using namespace std ;

int n ;
long long a[maxN] , w1 , w2 ;

void enter()
{
    cin >> n >> w1 >> w2 ;
    forinc(i,1,n) cin >> a[i] ;
}

long long cmax[6] , f[maxN][6] ;

void process()
{
    forinc(i,1,5) cmax[i] = -oo ;
    forinc(i,1,n) fordec(j,min(i,5),1) {
        long long w = 0 ;
        if (j == 1 || j == 5) w = a[i] * w1 ; else if (j == 2 || j == 4) w = a[i] * w2 ; else  w = a[i] ;
        f[i][j] = cmax[j-1]  + w ; cmax[j] = max(cmax[j],f[i][j]) ;
    }
    long long res = -oo ;
    forinc(i,5,n) res = max(res,f[i][5]) ;
    cout << res << endl ;
}

int main()
{
    freopen("FIVESET.inp" , "r" , stdin ) ;
    freopen("FIVESET.out" , "w" , stdout) ;
    enter() ;
    process() ;
    return 0 ;
}
