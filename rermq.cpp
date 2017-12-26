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
#define oo (int) 1e9 + 7
#define maxN 100005

using namespace std ;

struct node {
    int l , r , p ;
};
int n , m ;
node a[maxN] ;

void enter()
{
    cin >> n >> m ;
    forinc(i,1,m) cin >> a[i].l >> a[i].r >> a[i].p ;
}

bool cmp(node a , node b)  {return a.p > b.p ; }
set<int> f ;
set<int> :: iterator it ;
int b[maxN] , g[maxN][20] ;

void rmq()
{
    int l = log2(n) ;
    fordec(i,n,1) {
        g[i][0] = b[i] ;
        forinc(j,1,l) if (i + (1 << j) - 1 <= n) g[i][j] = min(g[i][j-1],g[i + (1 << (j-1))][j-1]) ;
    }
}

int get(int u , int v)
{
    int k = log2(v-u+1) ;
    return min(g[u][k],g[v - (1 << k) + 1][k]) ;
}

bool check()
{
    rmq() ;
    forinc(i,1,n) if (get(a[i].l,a[i].r) != a[i].p) return false ;
    return true ;
}

void process()
{
    sort(a+1,a+1+m,cmp) ;
    forinc(i,1,n) f.insert(i) ;
    forinc(i,1,m) while (1) {
        it = f.lower_bound(a[i].l) ;
        if (it != f.end() && (*it) <= a[i].r) b[(*it)] = a[i].p , f.erase(it) ; else break ;
    }
    if (!check()) cout << "inconsistent" << endl ;
    else {
        cout << "consistent" << endl ;
        forinc(i,1,n) cout << b[i] << " " ;
    }
}

int main()
{
    freopen("rermq.inp" , "r" , stdin) ;
    freopen("rermq.out" , "w" , stdout) ;
    enter() ;
    process() ;
    return 0 ;
}
