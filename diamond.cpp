#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)
#define forv(i,u) for (int j = 0 ; j < ke[u].size() ; j++)

using namespace std ;

int n , a[100001]  , k ;

int enter()
{
    cin >> n >> k ;
    forinc(i,1,n) cin >> a[i] ;
}

int fin(int x , int i )
{
    int l = i , r = n , res = 0 ;

    while (l <= r)
    {
        int mid = (l+r) / 2 ;
        if (a[mid] - x <= k)
        {
            l = mid + 1 ;
            res = mid ;
        }
        else r = mid - 1 ;
    }

    return res ;
}

int process()
{
    int res = 0 ;

    sort(a+1,a+n+1) ;
    forinc(i,1,n)
    {
        int t = fin(a[i],i) ;
        res = max(res,t-i+1) ;
    }

    cout << res ;
}

int main ()
{

    freopen("diamond.inp" , "r" , stdin) ;
    freopen("diamond.out" , "w" , stdout) ;

    enter() ;
    process() ;

}
