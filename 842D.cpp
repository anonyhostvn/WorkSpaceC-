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
#define maxN 300001
#define maxnode 6000000

using namespace std ;

int n , m , a[maxN] , b[maxN] , cnt = 0 , nxt[maxnode][2] , sz[maxnode] ;
bool dd[maxN] ;

int enter()
{
    cin >> n >> m ;
    forinc(i,1,n) cin >> a[i] ;
    forinc(i,1,m) cin >> b[i] ;
    forinc(i,1,m) b[i] = b[i-1] ^ b[i] ;
    return 0 ;
}

int getbit(int x , int i)
{
    return (x >> i) & 1 ;
}

int onbit(int x , int i)
{
    return (1 << i) | x ;
}

int build(int x)
{
    int recent = 1 ;
    sz[recent] ++ ;
    fordec(i,19,0) {
        int t = getbit(x,i) ;
        if (nxt[recent][t] == 0) {
            nxt[recent][t] = ++cnt ;
            recent = cnt ;
        } else recent = nxt[recent][t] ;
        sz[recent] ++ ;
    }
    return 0 ;
}

int solve(int x)
{
    int res = 0 , u = 1 , l = 0 , r = pow(2,20) - 1 ;
    fordec(i,19,0) {
        int t = getbit(x,i) , mid = (l+r) / 2 ;
        if (t == 0) {
            int v = nxt[u][0] ;
            if (v == 0) return res ;
            if (mid - l + 1 > sz[v]) {
                u = nxt[u][0] ;
                r = mid ;
            }
            else {
                res = onbit(res,i) ;
                int v = nxt[u][1] ;
                if (v == 0) return res ;
                l = mid + 1 ;
                u = nxt[u][1] ;
            }
        }
        else {
            int v = nxt[u][1] ;
            if (v == 0) return res ;
            if (r-mid > sz[v]) {
                u = nxt[u][1] ;
                l = mid + 1 ;
            }
            else {
                res = onbit(res,i) ;
                int v = nxt[u][0] ;
                if (v == 0) return res ;
                u = nxt[u][0] ;
                r = mid ;
            }
        }
    }
    return res ;
}

int prepare()
{
    cnt = 1 ;
    forinc(i,1,n) if (!dd[a[i]]) {
        build(a[i]) ;
        dd[a[i]] = true ;
    }
    forinc(i,1,m) cout << solve(b[i]) << endl ;
    return 0 ;
}

int main()
{
    //freopen("842D.inp" , "r" , stdin) ;
    enter() ;
    prepare() ;
    return 0 ;
}
