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
#define maxN 1005

template <class _T> bool maximize(_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize(_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

using namespace std ;

int n , m , a[maxN][maxN] ;

void enter () {
    cin >> m >> n ;
    forinc(i,1,m) forinc(j,1,n) {
        char ch ; cin >> ch ;
        a[i][j] = (ch == 'B') ? 1 : 0 ;
    }
}

int lab[maxN * maxN] ;

int get_root(int u) {
    if (u == lab[u]) return lab[u] ;
    lab[u] = get_root(lab[u]) ;
    return lab[u] ;
}

void uni(int u , int v){
    lab[get_root(u)] = get_root(v) ;
    get_root(u) ;
}

const int gox[4] = {-1 , 0 , +1 , 0 } ;
const int goy[4] = {0 , +1 , 0 , -1 } ;

void build() {
    forinc(i,1,m) forinc(j,1,n) lab[(i-1) * n + j] = (i-1) * n + j ;
    forinc(i,1,m) forinc(j,1,n) {
        forinc(k,0,3) {
            int cx = i + gox[k] , cy = j + goy[k] ;
            if (cx > 0 && cy > 0 && cx <= m && cy <= n && a[i][j] == a[cx][cy]) uni((i-1) * n + j , (cx - 1) * n + cy) ;
        }
    }
}

void floodfill(int x , int y , int c) {
    if (a[x][y] == c) return ;
    int troot = get_root((x - 1) * n + y) ;
    forinc(i,1,m) forinc(j,1,n) if (get_root((i-1) * n + j) == troot) a[i][j] = c ;
}

void solve () {
    map<int,int> f ;
    forinc(i,1,m*n) f[get_root(i)] ++ ;
    int cnt = f.size() , maxc = 0 ;
    for (auto tmp : f) maximize(maxc,tmp.se) ;
    cout << cnt << " " << maxc << endl ;
}

void trau () {
    int q ; cin  >> q ; build() ;
    forinc(i,1,q) {
        char ch ; cin >> ch ;
        int x , y , c ; cin >> x >> y ; c = (ch == 'B') ? 1 : 0 ;
        floodfill(x,y,c) ;
        build() ;
        solve() ;
    }
}

int num[maxN] ;
int cnt = 0 ;

void prepare () {
    map<int,int> f ;
    forinc(i,1,m) forinc(j,1,n) num[get_root((i-1) * n + j)] ++ , f[get_root((i-1) * n + j)] = 0 ;
    for (auto tmp : f) cnt ++ ;
    forinc(i,1,m) forinc(j,1,n)
}

void process () {
    build() ;
    prepare () ;
    int q ; cin >> q ;
    forinc(i,1,q) {
        char ch ; cin >> ch ;
        int x , y , c ; cin >> x >> y ; c = (ch == 'B') ? 1 : 0 ;
    }
}

int main () {
    freopen("FFILL.inp" , "r" , stdin) ;
    freopen("FFILL.out" , "w" , stdout) ;
    enter () ;
    trau () ;
    return 0 ;
}
