#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)
#define forv(j,u) for (int j = 0 ; j < u.size() ; j++)
#define pb push_back
#define pf push_front
#define fi first
#define se second

using namespace std ;

int k , n , a[100001] , b[100001];
string st ;

int enter()
{
    cin >> k ;
    cin >> st ;
    n = st.length() ;
    forinc(i,0,n-1) a[i+1] = (int) st[i]  - (int) '0' ;
}

int process()
{
    int sum = 0 , res = 0 ;
    forinc(i,1,n) sum += a[i] ;
    forinc(i,1,n) b[i] = 9 - a[i] ;
    sort(b+1,b+1+n,greater<int >() ) ;
    forinc(i,1,n) {
        if (sum  >= k) break ;
        sum += b[i] ;
        if (b[i] > 0) res ++ ;
    }
    cout << res ;
}

int main()
{
    //freopen("835B.inp" , "r" , stdin) ;
    enter() ;
    process() ;
}
