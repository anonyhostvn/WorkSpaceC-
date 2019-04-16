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

template <class _T> bool maximize(_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize(_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

const int ooit = 2e9 ;
const long long ooll = 1e15 ;

using namespace std ;


int fastRead() {
    char c ; int res = 0 ;
    for (c = getchar() ; c < '0' || c > '9' ; c = getchar()) ;
    for ( ; c >= '0' && c <= '9' ; c = getchar()) res*= 10 , res += c - '0' ;
    return res ;
}

#define maxM 400005
#define maxC 500005
#define maxN 200005

int n , m , c ;
struct node {
    int u , v , c ;
} edge[maxM] ;

struct node_{
    int a , b ;
} contract[maxC] ;

void enter () {
    n = fastRead() ; m = fastRead() ; c = fastRead() ;
    forinc(i,1,m) edge[i].u = fastRead() , edge[i].v = fastRead() , edge[i].c = fastRead() ;
    forinc(i,1,c) contract[i].b = fastRead() , contract[i].a = fastRead() ;
    sort(edge + 1 , edge + 1 + m , [] (node a , node b) {
         return a.c < b.c ;
         }) ;
}

int lab[maxN] ;

int get_root(int u) {
    if (u == lab[u]) return u ;
    lab[u] = get_root(lab[u]) ;
    return lab[u] ;
}

void uni(int u , int v) {
    lab[get_root(u)] = get_root(v) ;
    get_root(u) ;
}

int slt = 0 , wei_edge[maxM] , cnt = 0 ;
long long f[maxM] ;

void prepare () {
    forinc(i,1,n) lab[i] = i ;
    forinc(i,1,m) if (get_root(edge[i].u) != get_root(edge[i].v)) {
        wei_edge[++cnt] = edge[i].c ;
        uni(edge[i].u , edge[i].v) ;
    }

    sort(wei_edge + 1 , wei_edge + 1 + cnt) ;
    forinc(i,1,cnt) f[i] = f[i-1] + wei_edge[i] ;

    slt = n - cnt  ;
}

int find_(int x , int a) {
    int l = max(n-a,0) , r = cnt , res = 0 ;
    while (l <= r) {
        int mid = (l+r) / 2 ;
        if (wei_edge[mid] <= x) res = mid ,  l = mid + 1 ; else r = mid - 1 ;
    }
    return res ;
}

void process () {
    prepare () ;

    forinc(i,1,c) {
        if (contract[i].a < slt) printf("-1\n") ;
        else if (contract[i].a == slt) {
            long long res = f[cnt] + (long long) contract[i].a * contract[i].b ;
            printf("%lld\n" , res) ;
        }
        else {
            int nume = find_(contract[i].b,contract[i].a)  ;
            long long res = f[nume] + (long long) contract[i].b * (n - nume) ;
            printf("%lld\n" , res) ;
        }
    }
}

int main () {
    freopen("AIRPORTS.inp" , "r" , stdin) ;
    freopen("AIRPORTS.out" , "w" , stdout) ;
    enter () ;
    process () ;
    return 0 ;
}
