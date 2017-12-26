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

using namespace std ;

int n , m , q  ;
long long t[4][1001][1001] ;

int upd(int id , int x , int y , long long k)
{
    for (int i = x ; i <= n ; i += i & -i)
        for (int j = y ; j <= m ; j += j & -j) t[id][i][j] += k ;
    return 0 ;
}

long long getpd(int id , int x , int y)
{
    long long res = 0 ;
    for (int i = x ; i > 0 ; i -= i & -i)
        for (int j = y ; j > 0 ; j -= j & -j) res += t[id][i][j] ;
    return res ;
}

int up_hs(int id , long long a , long long b , long long x , long long y , long long w)
{
    upd(id,a,b,w) ;
    upd(id,a,y+1,-w) ;
    upd(id,x+1,b,-w) ;
    upd(id,x+1,y+1,w) ;
    return 0 ;
}

int update(long long  a , long long b , long long x , long long y , long long w)
{
    long long bk = b - 1 , ak = a-1 ;
    up_hs(0,a,b,x,y,-w * bk) ;
    up_hs(1,a,b,x,y,-w * ak) ;
    up_hs(2,a,b,x,y,w) ;
    up_hs(3,a,b,x,y,w * ak * bk) ;

    up_hs(0,a,y+1,x,m,w * (y-bk)) ;
    up_hs(3,a,y+1,x,m,w * (bk-y) * ak) ;

    up_hs(1,x+1,b,n,y,w * (x-ak)) ;
    up_hs(3,x+1,b,n,y,w * (ak-x) * bk) ;

    up_hs(3,x+1,y+1,n,m,w * (x-ak) * (y-bk)) ;
    return 0 ;
}

long long getsum(int x , int y)
{
    return x * getpd(0,x,y) + y * getpd(1,x,y) + x * y * getpd(2,x,y) + getpd(3,x,y) ;
}

long long solve(int a , int b , int x , int y)
{
    return getsum(x,y) - getsum(a-1,y) - getsum(x,b-1) + getsum(a-1,b-1) ;
}

int enter()
{
    cin >> n >> m >> q ;
    forinc(i,1,q) {
        int command = 0 ; cin >> command ;
        if (command == 1) {
            int a , b , x , y , w ; cin >> a >> b >> x >> y >> w ;
            update(a,b,x,y,w) ;
        }
        else {
            int a,b,x,y ; cin >> a >> b >> x >> y ;
            cout << solve(a,b,x,y) << endl ;
        }
    }
    return 0 ;
}

int main()
{
    //freopen("HSPC14K.inp" , "r" , stdin) ;
    enter() ;
    return 0 ;
}
