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

int n , l , m , a[maxN] , b[maxN] , x[maxN] ;

void enter()
{
    scanf("%d%d" , &n , &l) ;
    forinc(i,1,n) scanf("%d%d"  , &a[i] , &b[i]);
    scanf("%d" , &m) ;
    forinc(i,1,m) scanf("%d" , &x[i]) ;
}

long double v[maxN] ;

void process()
{
    forinc(i,1,n) v[i] = (long double) l / (b[i] - a[i]) ;
    forinc(i,1,m) {
        long double res = oo ;
        int id = 0 ;
        forinc(j,1,n) if (res > (long double) a[j] + (long double) x[i] / v[j]) res = (long double) a[j] + (long double) x[i] / v[j]  , id = j ;
        cout << id << endl ;
    }
}

int main()
{
    freopen("BUS.inp" , "r" , stdin) ;
    //freopen("BUS.out" , "w" , stdout) ;
    enter();
    process() ;
    return 0 ;
}
