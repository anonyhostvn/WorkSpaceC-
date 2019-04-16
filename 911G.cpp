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
#define pli pair<long long , int>

template <class _T> bool maximize(_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize(_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

const int ooit = 2e9 ;
const long long ooll = 1e15 ;

using namespace std ;

#define maxN 200005

int fastRead() {
    char c ; int res = 0 ;
    for (c = getchar() ; c < '0' || c > '9' ; c = getchar()) ;
    for ( ; c >= '0' && c <= '9' ; c = getchar()) res*= 10 , res += c - '0' ;
    return res ;
}

void WriteInt(int x)
{
    if (x > 9) WriteInt(x / 10);
    putchar(x % 10 + '0');
}

int n , a[maxN] ;

void enter () {
    n = fastRead() ;
    forinc(i,1,n) a[i] = fastRead() ;
}

#define maxA 105

struct node {
    int f[maxA] ;
    void reset() { forinc(i,1,100) f[i] = i ; }
} val[4 * maxN] ;

void init(int s , int l , int r) {
    val[s].reset() ;
    if (l == r) return ;
    int mid = (l+r) / 2 ;
    init(2 * s , l , mid) ;
    init(2 * s + 1 , mid + 1 , r) ;
}

void set_node(int s , int a , int b) { forinc(i,1,100) if (val[s].f[i] == a) val[s].f[i] = b ; }

void trans(int s) {
    forinc(i,1,100) val[2*s].f[i] = val[s].f[val[2*s].f[i]] , val[2 * s + 1].f[i] = val[s].f[val[2 * s + 1].f[i]] ;
    val[s].reset() ;
}

void update(int s , int l , int r , int u , int v , int a , int b) {
    if (r < u || v < l) return ;
    if (u <= l && r <= v) {
        set_node(s,a,b) ;
        return ;
    }
    trans(s) ; int mid = (l+r) / 2 ;
    update(2 * s , l , mid , u , v, a , b) ;
    update(2 * s +1 , mid + 1 , r , u , v , a , b) ;
}

int get(int s , int l , int r , int i , int x) {
    if (r < i || i < l) return 0 ;
    if (l == r) return val[s].f[x] ;
    trans(s) ;
    int mid = (l+r) / 2;
    return max(get(2 * s , l , mid , i , x) , get(2 * s  + 1 , mid + 1 , r , i , x)) ;
}

void process () {
    init(1,1,n) ;
    //forinc(i,1,n) cout << get(1,1,n,i,a[i]) << " " ; cout << endl ;
    int q = 0 ; cin >> q ;
    forinc(i,1,q) {
        int l = fastRead() , r = fastRead() , a = fastRead() , b = fastRead() ;
        update(1 , 1 , n , l , r , a , b) ;
    }

    forinc(i,1,n) WriteInt(get(1 , 1 , n , i , a[i])) , putchar(' ') ; cout << endl ;
}

int main () {
    //freopen("911G.inp" , "r", stdin) ;
    enter () ;
    process () ;
    return 0 ;
}
