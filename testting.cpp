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
#define maxN 10005

using namespace std ;

int n , q ;
long long f[maxN] ;

void enter()
{
    cin >> n >> q ;
    forinc(i,1,q) {
        int u , v , x ; cin >> u >> v >> x ;
        ++u ; ++v ; f[u] += x ; f[v+1] -= x ;
    }
    forinc(i,1,n) f[i] += f[i-1] ;
    cin >> q ;
    forinc(i,1,q) {
        int x ; cin >> x ; ++x ;
        cout << f[x] << endl ;
    }
    forinc(i,1,n) f[i] = 0 ;
}

int main()
{
    //freopen("testting.inp" , "r" , stdin) ;
    ios_base::sync_with_stdio(false) ;
    cin.tie(0) ; cout.tie(0) ;
    int t = 0 ; cin >> t ;
    while (t--) enter() ;
    return 0 ;
}
