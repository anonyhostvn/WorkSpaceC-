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
#define ooll (long long) 1e15
#define ooit (int) 2e9

template <class _T> bool maximize(_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize(_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

using namespace std ;

#define maxN 1000005

int n , a[maxN] ;

int fastRead() {
    int res = 0 ; char c ;
    for (c = getchar() ; c < '0' || c > '9' ; c = getchar()) ;
    for ( ; c >= '0' && c <= '9' ; c = getchar()) res *= 10 , res += (int) c - (int) '0' ;
    return res ;
}

void enter () {
    //scanf("%d" , &n) ;
    n = fastRead() ;
    forinc(i,1,n) a[i] = fastRead() ;
    //scanf("%d" , &a[i]) ;
}

int nxt[16] ;

int get_bit(int x , int i) {return (x >> i) & 1 ; }
int on_bit(int x , int i) {return x | (1 << i) ; }

void const_array() {
    nxt[0] = 3 ; nxt[3] = 15 ; nxt[15] = 12 ; nxt[12] = 0 ;
    nxt[1] = 7 ; nxt[7] = 14 ; nxt[14] = 8 ; nxt[8] = 1  ;
    nxt[5] = 6 ; nxt[6] = 10 ; nxt[10] = 9 ; nxt[9] = 5 ;
    nxt[2] = 11 ; nxt[11] = 13 ; nxt[13] = 4 ; nxt[4] = 2 ;
}

int deg_90(int x) {
    int res = 0 ;
    forinc(i,0,15) if (get_bit(x,i) == 1) res = on_bit(res,nxt[i]) ;
    return res ;
}

struct node { int val[4]  ; };

vector<pii> b , c ;
bool dd[maxN] ;
vector<node> P ;

void prepare () {
    const_array() ;
    forinc(i,1,n) forinc(j,1,4) b.push_back({a[i],i}) , a[i] = deg_90(a[i]) ;
    sort(b.begin() , b.end()) ;
    c.push_back({b[0].fi,1}) ; dd[b[0].se] = true ;
    forinc(i,1,b.size() -1) if (!dd[b[i].se]) {
        if (b[i].fi == c.back().fi) c.back().se ++ ; else c.push_back({b[i].fi,1}) ;
        dd[b[i].se] = true ;
    }
    for (auto tmp : c) {
        node g = {0,0,0,0} ;
        forinc(i,1,4) {
            tmp.fi = deg_90(tmp.fi) ;
            g.val[i] = tmp.fi ;
        }
        P.push_back(g) ;
    }
}

void process () {
    prepare () ;
    int ans = ooit ;
    forinc(hole_1,0,14) forinc(hole_2,hole_1+1,15) {
        int res = 0 ;
        for (auto tmp : c) {
            int cnt = ooit ;
            forinc(i,1,4) {
                tmp.fi = deg_90(tmp.fi) ;
                minimize(cnt, (1 - get_bit(tmp.fi,hole_1)) + (1 - get_bit(tmp.fi,hole_2)) ) ;
            }
            res += cnt * tmp.se ;
        }
        minimize(ans,res) ;
    }
    cout << ans << endl ;
}

int main () {
    freopen("PUNCH.inp" , "r" , stdin) ;
    freopen("PUNCH.out" , "w" , stdout) ;
    enter () ;
    process () ;
    return 0 ;
}
