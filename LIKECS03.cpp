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
#define maxA (1 << 20) + 1

using namespace std ;

int n , k  ;
bool dd[maxA] ;

void enter()
{
    memset(dd,false,sizeof(dd))  ;
    cin >> n >> k ;
    forinc(i,1,n) {
        int x ; cin >> x ;
        dd[x] = true ;
    }
    int res = 0 ;
    forinc(i,0,k-1) if (!dd[1<<i]) res ++ ;
    cout << res << endl ;
}

int main()
{
    //freopen("likecs03.inp" , "r" , stdin) ;
    int t = 0 ; cin >> t ;
    while (t--) enter() ;
    return 0 ;
}
