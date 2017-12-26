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
#define maxN 700

using namespace std ;

const int gox[8] = {-1 , -1 , -1 , 0 , 0 , +1 , +1, +1} ;
const int goy[8] = {-1 ,  0 , +1 ,-1 ,+1 , -1 ,  0 ,+1} ;
int n , m , a[maxN+1][maxN+1] ;
bool dd[maxN+1][maxN+1] ;

int enter()
{
    ios_base::sync_with_stdio(false) ;
    cin >> n >> m ;
    forinc(i,1,n)
    forinc(j,1,m) cin >> a[i][j] ;
    return 0 ;
}

int bfs(int u , int v)
{
    int res = 1 ;
    queue<pii> q ;
    q.push(mk(u,v)) ; dd[u][v] = true ;
    while (!q.empty()){
        pii tmp = q.front() ; q.pop() ;
        int tu = tmp.fi , tv = tmp.se ;
        forinc(i,0,7) {
            int cx = tu + gox[i] , cy = tv + goy[i] ;
            if (cx >= 1 && cy >= 1 && cx <= n && cy <= m){
                if (a[cx][cy] > a[u][v]) res = 0 ;
                if (a[cx][cy] == a[u][v] && !dd[cx][cy]) {
                    dd[cx][cy] = true ;
                    q.push(mk(cx,cy)) ;
                }
            }
        }
    }
    return res ;
}

int process()
{
    int res = 0 ;
    forinc(i,1,n)
    forinc(j,1,m)
    if (!dd[i][j]) res += bfs(i,j) ;
    cout << res ;
    return 0 ;
}

int main()
{
    //freopen("NKGUARD.inp" , "r" , stdin) ;
    enter() ;
    process() ;
    return 0 ;
}
