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
#define maxN 100005

using namespace std ;

int a[maxN] , p[maxN] , n ;

void enter() {
    cin  >> n ;
    forinc(i,1,n) cin >> a[i] ;
    forinc(i,1,n) cin >> p[i] ;
}

bool active[maxN] ;
int lab[maxN] ;
long long sum[maxN] , ans[maxN] , res = 0  ;

int get_root(int u) {
    if (u == lab[u]) return u ;
    lab[u] = get_root(lab[u]) ;
    return lab[u] ;
}

void uni(int u , int v) {
    int root_u = get_root(u) , root_v = get_root(v);
    sum[root_v] += sum[root_u] ; if (res < sum[root_v]) res = sum[root_v] ;
    lab[root_u] = root_v ;
}

void process() {
    forinc(i,1,n) lab[i] = i ;
    fordec(i,n,2) {
        int u = p[i] ;
        active[u] = true ; sum[get_root(u)] = a[u] ; res = max(res,(long long) a[u]) ;
        if (active[u-1]) uni(u,u-1) ; if (active[u+1]) uni(u,u+1) ;
        ans[i-1] = res ;
    }
    forinc(i,1,n) cout << ans[i] << endl ;
}

int main() {
    //freopen("722C.inp" , "r" , stdin) ;
    enter() ;
    process() ;
    return 0 ;
}
