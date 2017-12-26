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
#define maxN 200005

using namespace std ;

int n , a[maxN] , b[maxN] ;

void enter() {
    cin >> n ;
    forinc(i,1,n) cin >> a[i] ;
    forinc(i,1,n) cin >> b[i] ;
}

int f[maxN][20] , g[maxN][20] ;

void rmq() {
    forinc(i,1,n) f[i][0] = a[i] , g[i][0] = b[i] ;
    int l = log2(n) ;
    forinc(j,1,l) forinc(i,1,n) if (i + (1 << (j-1)) <= n) f[i][j] = max(f[i][j-1],f[i+(1 << (j-1))][j-1]) ;
    forinc(j,1,l) forinc(i,1,n) if (i + (1 << (j-1)) <= n) g[i][j] = min(g[i][j-1],g[i+(1 << (j-1))][j-1]) ;
}

int get_max_a(int u , int v) {
    int l = log2(v-u+1) ;
    return max(f[u][l],f[v-(1 << l) + 1][l]) ;
}

int get_min_b(int u , int v) {
    int l = log2(v-u+1) ;
    return min(g[u][l],g[v-(1 << l) + 1][l]) ;
}

int find_(int cl){
    int l = cl , r = n , res = -1 ;
    while (l <= r) {
        int mid = (l+r) / 2 ;
        if (get_max_a(cl,mid) == get_min_b(cl,mid)) {
            r = mid - 1 ; res = mid ;
        } else if (get_max_a(cl,mid) < get_min_b(cl,mid)) l = mid + 1 ; else r = mid - 1 ;
    }
    return res ;
}

int find__(int cl) {
    int l = cl , r = n , res = -1 ;
    while (l <= r) {
        int mid = (l+r) / 2 ;
        if (get_max_a(cl,mid) == get_min_b(cl,mid)) {
            l = mid + 1 ; res = mid ;
        } else if (get_max_a(cl,mid) < get_min_b(cl,mid)) l = mid + 1 ; else r = mid - 1 ;
    }
    return res ;
}

void process() {
    rmq() ;
    long long res = 0 ;
    forinc(i,1,n) {
        int t1 = find_(i) , t2 = find__(i) ;
        if (t1 == -1) continue ;
        res += t2 - t1 + 1 ;
    }
    cout << res << endl ;
}

int main() {
    //freopen("689D.inp" , "r" , stdin) ;
    enter() ;
    process() ;
    return 0 ;
}
