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

int n , m   ;
long long salary[maxN] ;
vector<int> ke[maxN] ;

void enter()
{
    scanf("%d%d" , &n , &m) ;
    scanf("%lld" , &salary[1]) ;
    forinc(i,2,n) {
        int x ;
        scanf("%lld%d" , &salary[i] , &x) ;
        ke[x].push_back(i) ;
    }
}

int cnt = 0 , id[maxN] , f[maxN] ;

void dfs(int u)
{
    f[u] = 1 ; id[u] = ++cnt ;
    forv(i,ke[u]) {
        int v = ke[u][i] ;
        dfs(v) ; f[u] += f[v] ;
    }
}

long long BIT[maxN] ;

void update(int id , int x)
{
    for (int i = id ; i <= n ; i += i & -i) BIT[i] += x ;
}

long long get(int id)
{
    long long res = 0 ;
    for (int i = id ; i > 0 ; i -= i & -i) res += BIT[i] ;
    return res ;
}

void process()
{
    dfs(1) ;

    forinc(i,1,m) {
        char ch ; scanf("\n%c" , &ch) ;
        if (ch == 'p') {
            int x , A ;  scanf("%d%d" , &A , &x) ;
            update(id[A]+1,x) ;
            update(id[A] + f[A],-x) ;
        } else {
            int A ; scanf("%d" , &A) ;
            printf("%lld\n" , salary[A] + get(id[A]) ) ;
        }
    }
}

int main()
{
    freopen("SALARY.inp" , "r" , stdin) ;
    freopen("SALARY.out" , "w"  , stdout) ;
    enter() ;
    process() ;
    return 0 ;
}
