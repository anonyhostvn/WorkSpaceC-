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

int n , a[maxN] , last_vis[maxN] ;

void enter() {
    cin >> n ;
    forinc(i,1,n) cin >> a[i] ;
    fordec(i,n,1) if (last_vis[a[i]] == 0) last_vis[a[i]] = i ;
    int res = ooit , tres = 0 ;
    forinc(i,0,200000) if (last_vis[i] != 0 && res > last_vis[i]) res = last_vis[i] , tres = i ;
    cout << tres << endl ;
}

int main() {
    //freopen("890B.inp" , "r" , stdin) ;
    enter() ;
    return 0 ;
}
