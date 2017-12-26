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

int n , c ;
long long t[2][100001] ;

int upd(int id , int x , long long k)
{
    for (int i = x ; i <= n ; i += i & -i) t[id][i] += k ;
    return  0 ;
}

long long getpd(int id , int x)
{
    long long res = 0 ;
    for (int i = x ; i > 0 ; i -= i & -i) res += t[id][i] ;
    return res ;
}

int update(int p , int q , int v)
{
    upd(0,p,v) ;
    upd(0,q+1,-v) ;
    upd(1,p,(long long)(1-p)*v) ;
    upd(1,q+1,(long long) v*q)  ;
    return 0 ;
}

long long get(int i)
{
    return (long long) getpd(0,i) * i + getpd(1,i) ;
}

int enter()
{
    forinc(i,1,n) {
        t[0][i] = 0 ;
        t[1][i] = 0 ;
    }
    cin >> n >> c ;
    forinc(i,1,c) {
        int command ; cin >> command ;
        if (command == 0) {
            int p , q ,v ; cin >> p >> q >> v ;
            update(p,q,v) ;
        }
        else {
            int u , v ; cin >> u >> v ;
            cout << get(v) - get(u-1) << endl ;
        }
    }
    return 0 ;
}

int main()
{
    //freopen("HORRIBLE.inp" , "r" , stdin) ;
    int t ; cin >> t ;
    while (t--) enter() ;
    return 0 ;
}
