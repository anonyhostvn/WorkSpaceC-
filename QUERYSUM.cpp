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

int n , m ,a[maxN] ;
long long BIT[maxN] ;

void update(int id , int x)
{
    for (int i = id ; i <= n; i += i & -i) BIT[i] += x ;
}

long long get(int id)
{
    long long res = 0 ;
    for (int i = id ; i > 0 ; i -= i & -i) res += BIT[i] ;
    return res ;
}

void enter()
{
    scanf("%d%d" , &n ,&m) ;
    forinc(i,1,n) scanf("%d" , &a[i]) ;
}

void process()
{
    forinc(i,1,m) {
        char ch ; scanf("\n%c" , &ch) ;
        if (ch == 'S') {
            int id , x ; scanf("%d%d" , &id , &x) ;
            update(id,-a[id]) ;
            update(id,x) ; a[id] = x ;
        } else {
            int u , v ; scanf("%d%d" , &u , &v) ;
            printf("%lld" , get(v) - get(u-1)) ; printf("\n") ;
        }
    }
}

int main()
{
    freopen("QUERYSUM.inp" , "r" , stdin) ;
    freopen("QUERYSUM.out" , "w" , stdout) ;
    enter() ;
    process() ;
    return 0 ;
}
