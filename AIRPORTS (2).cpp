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
    int a , b , pos ;
} contract[maxC] ;

void enter () {
    n = fastRead() ; m = fastRead() ; c = fastRead() ;
    forinc(i,1,m) edge[i].u = fastRead() , edge[i].v = fastRead() , edge[i].c = fastRead() ;
    forinc(i,1,c) contract[i].b = fastRead() , contract[i].a = fastRead() , contract[i].pos = i ;
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

int slt = 0 , S ;
vector<int> wei_edge ;
long long f[maxM] ;

void prepare () {
    forinc(i,1,n) lab[i] = i ; wei_edge.push_back(0) ;
    forinc(i,1,m) if (get_root(edge[i].u) != get_root(edge[i].v)) {
        wei_edge.push_back(edge[i].c) ;
        uni(edge[i].u , edge[i].v) ;
    }
    sort(wei_edge.begin() , wei_edge.end()); f[0] = wei_edge[0] ; S = wei_edge.size() - 1 ;
    forinc(i,1,S) f[i] = f[i-1] + wei_edge[i] ;
    sort(contract + 1 , contract + 1 + c , [] (node_ p , node_ q){
         return p.b > q.b ;
         } ) ;
    //forinc(i,1,c) cout << contract[i].a << " " << contract[i].b << endl ;
    slt = n - wei_edge.size() + 1  ;
}

long long ans[maxC] ;

void process () {
    prepare () ;

    forinc(i,1,c) {
        while (wei_edge.size() > 1 && wei_edge.back() >= contract[i].b) wei_edge.pop_back() ;
        if (contract[i].a < slt) ans[contract[i].pos] = -1 ; else {
            int num_e = max((int) wei_edge.size() - 1 , n - contract[i].a) ;
            long long res = f[num_e] + (long long ) contract[i].b * (n - num_e) ;
            ans[contract[i].pos] = res ;
        }
    }

    forinc(i,1,c) cout << ans[i] << endl ; //printf("%lld\n" , &ans[i]) ;
}

int main () {
    freopen("AIRPORTS.inp" , "r" , stdin) ;
    freopen("AIRPORTS.out" , "w" , stdout) ;
    enter () ;
    process () ;
    return 0 ;
}