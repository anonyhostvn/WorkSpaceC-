#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)
#define forv(i,u) for (int j = 0 ; j < ke[u].size() ; j++)
#define oo 1000000000000000000

using namespace std ;

int n , k , trace[3001][3001] ;
long long a[3001] , f[3001][3001] ;
bool group[3001] ;

int vtrace(int n , int k)
{
    if (n == 0) return 0 ;

    if (trace[n][k] == 1) vtrace(n-1,k) ; else vtrace(n-1,k-1) ;

    if (trace[n][k] == 0) group[n] = true ;

    return 0 ;
}

int process()
{
    forinc(i,0,n)
    forinc(j,0,n) f[i][j] = oo ;
    f[0][0] = 0;

    forinc(i,0,n-1)
    forinc(j,0,k)
    if (f[i][j] < oo)
    {
        if (i+1-j<=n-k && abs(f[i+1][j]) > abs(f[i][j] - a[i+1]))
        {
            f[i+1][j] = f[i][j] - a[i+1] ;
            trace[i+1][j] = 1 ;
        }
        if (j+1 <= k && abs(f[i+1][j+1]) > abs(f[i][j] + a[i+1]))
        {
            f[i+1][j+1] = f[i][j] + a[i+1] ;
            trace[i+1][j+1] = 0 ;
        }
    }

    vtrace(n,k) ;

    long long res = 0 ;

    //forinc(i,1,n) if (group[i])cout << i << endl ;

    forinc(i,1,n)
    if (group[i])
        forinc(j,1,n)
            if (!group[j]) res = res + abs(a[i]-a[j]) ;

    cout << res  ;

    return 0 ;
}

int test()
{
    pair<int , int> b[3001] ;
    forinc(i,1,n)
    {
        b[i].first = a[i] ;
        b[i].second = i ;
    }

    sort(b+1,b+1+n);
    forinc(i,1,n) cout << b[i].first << " " << b[i].second << endl ;
}

int main()
{
    freopen("faircut.inp" , "r" , stdin) ;

    cin >> n >> k ;
    forinc(i,1,n) cin >> a[i] ;

    process();
    //test() ;

    return 0 ;
}
