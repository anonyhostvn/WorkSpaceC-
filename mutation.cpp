#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)
#define forv(j,u) for (int j = 0 ; j < u.size() ; j++)

using namespace std ;

int n , m , a[100001]  , dd[100001] ;

int enter()
{
    cin >> n >> m ;
    forinc(i,1,n) cin >> a[i] ;
}

int process()
{
    int dem = n ,  maxn = n ;
    while (m > 0) {
        m-- ;
        int cnt = 0 ;
        forinc(i,1,maxn) dd[i] = 0 ;
        forinc(i,1,dem) dd[a[i]] ++  ;
        forinc(i,1,maxn) if (dd[i] > 0) cnt = i ;
        maxn = 0 ; dem = cnt ;
        forinc(i,1,dem) {a[i] = dd[i] ; maxn = max(maxn,dd[i]) ; }
        if (a[1] == 1 && dem == 1) break ;
    }

    forinc(i,1,dem) cout << a[i] << " " ;
    forinc(i,1,n-dem) cout << 0 << " " ;
}

int main()
{
    freopen("mutation.inp" , "r" , stdin) ;
    freopen("mutation.out" , "w" , stdout) ;

    enter() ;
    process() ;
}
