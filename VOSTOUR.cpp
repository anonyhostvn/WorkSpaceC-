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
#define maxN 100000
#define maxT 256
#define oo 1000000000

using namespace std ;

int n , k , m , d[maxN+1][maxT+1] , ktt ;
vector<int> ke[maxN+1] ;

int enter()
{
    cin >> n >> k >> m ;
    ktt = pow(2,k) - 1 ;
    forinc(i,1,m) {
        int u , v ; cin >> u >> v ;
        ke[u].pb(v) ;
    }
    return 0 ;
}

int onbit(int x , int i)
{
    if (i > k-1) return x ;
    return (1 << i) | x ;
}

int getbit(int x , int i)
{
    return (x >> i) & 1 ;
}

queue <pii> q ;

int process()
{
    forinc(i,0,n-1)
    forinc(t,0,ktt) d[i][t] = oo ;
    d[0][onbit(0,0)] = 0 ;
    q.push(mk(0,onbit(0,0))) ;
    while (!q.empty()){
        pii tmp = q.front() ; q.pop() ;
        int u = tmp.fi , tt = tmp.se ;
        forv(j,ke[u]){
            int v = ke[u][j] , stt = onbit(tt,v) ;
            if (d[v][stt] > d[u][tt] + 1){
                d[v][stt] = d[u][tt] + 1 ;
                q.push(mk(v,stt)) ;
            }
        }
    }
    cout << d[0][ktt] ;
    return 0 ;
}

int main()
{
    //freopen("VOSTOUR.inp" , "r" , stdin) ;
    enter() ;
    process() ;
}
