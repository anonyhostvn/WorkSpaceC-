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
#define maxN 3005

using namespace std ;

int  r , c , h , w , a[maxN][maxN] ;

void enter() {
    cin >> r >> c >> h >> w ;
    forinc(i,1,r) forinc(j,1,c) cin >> a[i][j];
}

int g[maxN][maxN] ;

void Build_(int H) {
    forinc(i,1,r) forinc(j,1,c) g[i][j] = 0 ;
    forinc(i,1,r) forinc(j,1,c) g[i][j] = g[i-1][j] + g[i][j-1] - g[i-1][j-1] + (int) (a[i][j] > H) ;
}

int get_g(int x , int y , int u , int v ){return g[u][v] - g[u][y-1] - g[x-1][v] + g[x-1][y-1] ; }

bool check(int H) {
    Build_(H) ;
    forinc(i,1,r-h+1) forinc(j,1,c-w+1) if (get_g(i,j,i+h-1,j+w-1) <= (h * w / 2)) return true ;
    return false ;
}

void process() {
    int L = 1 , R = r * c , res = 0 ;
    while (L <= R) {
        int mid = (L+R) / 2 ;
        if (check(mid)) {R = mid - 1 ; res = mid ; } else L = mid + 1 ;
    }
    cout << res << endl ;
}

int main() {
    //freopen("ioi1013.inp" , "r" , stdin) ;
    ios_base::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    enter() ;
    process() ;
    return 0 ;
}
