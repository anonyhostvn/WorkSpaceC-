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

int n , q , BIT[maxN] ;

void update(int id , int x)
{
    for (int i = id ; i <= n ; i += i & -i) BIT[i] += x ;
}

int get(int id)
{
    int res = 0 ;
    for (int i = id ; i > 0 ; i -= i & -i) res += BIT[i] ;
    return res ;
}

void enter()
{
    cin >> n >> q ;
    forinc(i,1,n) {
        int x ; cin >> x ;
        update(i,x) ;
        update(i+1,-x) ;
    }
    forinc(i,1,q) {
        int u , v , x ; cin >> u >> v >> x ;
        ++u ; ++v ;
        update(u,x) ;
        update(v+1,-x) ;
    }
    cin >> q ;
    forinc(i,1,q) {
        int x ; cin >> x ; ++x ;
        cout << get(x) << endl ;
    }
    forinc(i,1,n) BIT[i] = 0 ;
}

int main()
{
    //freopen("UPDATEIT.inp" , "r" , stdin) ;
    int t = 0 ; cin >> t ; cout << t << endl ;
    while (t--) enter() ;
    return 0 ;
}
