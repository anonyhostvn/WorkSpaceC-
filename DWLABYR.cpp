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
#define maxN 305

using namespace std ;

int n , m , k ;
long long d[maxN][maxN] , a[maxN][maxN] ;

void enter()
{
    scanf("%d%d%d" , &n , &m , &k) ;
    forinc(i,1,n) forinc(j,1,n) if (i != j) d[i][j] = oo ;
    forinc(i,1,m) {
        int u , v , c ;
        scanf("%d%d%d" , &u , &v , &c) ;
        d[u][v] = min(d[u][v],(long long) c) ;
    }
}

bool active[maxN] ;

void update(int u)
{
    forinc(i,1,n)
    forinc(j,1,n) d[i][j] = min(d[i][j],(long long) d[i][u] + d[u][j]) ;
}

long long get(int u , int v)
{
    if (!active[u] || !active[v]) return -1 ;
    if (d[u][v] == oo) return -1 ;
    return d[u][v] ;
}

void process()
{
    forinc(i,1,k) {
        char ch ;
        scanf("\n%c" , &ch) ;
        if (ch == 'X') {
            int x ; scanf("%d" , &x) ;
            if (!active[x]) update(x) ;
            active[x] = true ;
        } else {
            int u , v ; scanf("%d%d" , &u , &v) ;
            printf("%lld" , get(u,v)) ; //printf(" %d %d " , u, v) ;
            printf("\n") ;
        }
    }
}

int main()
{
    freopen("DWLABYR.inp" , "r" , stdin) ;
    freopen("DWLABYR.out" , "w" , stdout) ;
    enter() ;
    process() ;
    return 0 ;
}
