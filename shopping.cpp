#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)
#define forv(j,u) for (int j = 0 ; j < u.size() ; j++)
#define oo 10000000000000

using namespace std ;

int n , m , k , a[1001] , tt  ;
long long f[1001][1300] ;
vector<int> ke[1001] , ts[1001] ;

int onbit(int x, int i)
{
    return x | (1 << (i-1)) ;
}

int add(int u , int v , int t)
{
    ke[u].push_back(v) ;
    ts[u].push_back(t) ;
}

int enter()
{
    cin >> n >> m >> k ;
    forinc(i,1,n){
        int s ; cin >> s ;
        a[i] = 0 ;
        forinc(j,1,s) {
            int t ; cin >> t ;
            a[i] = onbit(a[i],t) ;
        }
    }
    forinc(i,1,m){
        int u , v , t ;
        cin >> u >> v >> t ;
        add(u,v,t) ;
        add(v,u,t) ;
    }
    tt = pow(2,k) - 1  ;
}

multiset <pair<int,pair<int,int> > > heap ;

int dkstra()
{
    heap.clear() ;
    forinc(i,1,n)
    forinc(j,0,tt) f[i][j] = oo ;
    f[1][a[1]] = 0 ;
    heap.insert(make_pair(0,make_pair(1,a[1]))) ;
    while (!heap.empty()){
        pair<int,pair<int,int> > tmp = *heap.begin() ;
        heap.erase(heap.begin()) ;
        int recent = tmp.first , u = tmp.second.first , stt = tmp.second.second ;
        forv(j,ke[u]) {
            int v = ke[u][j] , dist = ts[u][j] , ktt = stt | a[v] ;
            if (f[v][ktt] > f[u][stt] + dist){
                f[v][ktt] = f[u][stt] + dist ;
                heap.insert(make_pair(f[v][ktt],make_pair(v,ktt))) ;
            }
         }
    }
}

int process()
{
    long long res = oo ;
    dkstra () ;
    forinc(i,0,tt)
    forinc(j,0,tt)
    if ((i | j) == tt && f[n][i] < oo && f[n][j] < oo) res = min(res,max(f[n][i],f[n][j])) ;
    cout << res ;
}

int main()
{
    //freopen("shopping.inp" , "r" , stdin) ;
    enter() ;
    process() ;
}
