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

using namespace std;

int n , a[maxN] , lab[maxN] ;
bool dd[maxN] , cdd[maxN] ;

int get_root(int u) {
    if (u == lab[u]) return u ;
    lab[u] = get_root(lab[u]) ;
    return lab[u] ;
}

void uni(int u , int v) { lab[lab[u]] = lab[v] ; }

void enter() {
    cin >> n ;
    forinc(i,1,n) cin >> a[i] ;
    forinc(i,1,n) lab[i] = i ;
    forinc(i,1,n) if (!dd[a[i]]) dd[a[i]] = true , uni(i,a[i]) ;
    int res =0  ;
    forinc(i,0,n) if (!cdd[get_root(i)]) cdd[get_root(i)] = true , res ++ ;
    cout << res << endl ;
}

int main() {
    //freopen("890C.inp" , "r" , stdin) ;
    enter() ;
    return 0 ;
}
