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
#define maxN 5005

template <class _T> bool maximize(_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize(_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

using namespace std ;

int n , m , w ;
vector<int> ke[maxN] ;

struct store{
    int place , num , price ;
};

vector<store> vinmart ;

void enter() {
    cin >> n >> m ;
    forinc(i,1,m) {
        int u , v ; cin >> u >> v ;
        ke[u].push_back(v) ;
        ke[v].push_back(u) ;
    }

    cin >> w ;
    forinc(i,1,w) {
        int c , k , p ; cin >> c >> k >> p ;
        vinmart.push_back({c,k,p}) ;
    }
}

int d[maxN] ;


void bfs(int rot) {
    queue<int> q ;
    forinc(i,1,n) d[i] = -1 ; d[rot] = 0 ; q.push(rot) ;
    while (!q.empty()) {
        int u = q.front() ; q.pop() ;
        for (int v : ke[u]) if (d[v] == -1) d[v] = d[u] + 1 , q.push(v) ;
    }
}

int max_length = 0 , dist[maxN][maxN] ;

void prepare () {
    forinc(i,1,n) {
        bfs(i) ;
        forinc(j,1,n) dist[i][j] = d[j] , maximize(max_length,d[j]) ;
    }

    sort(vinmart.begin() , vinmart.end() , [] (store a , store b) { return a.price < b.price ;  } ) ;
}

bool check(int root , int snum , int money , int tlen) {
    int cnt_sholve = 0 , sum = 0 ;

    for (auto u : vinmart) if (dist[root][u.place] <= tlen && dist[root][u.place] > -1) {
        int cnt = max(0,min(u.num,(money - sum) / u.price)) ;
        cnt_sholve += cnt ; sum += cnt * u.price ;
    }

    return cnt_sholve >= snum ;
}

long long solve(int snum , int root , int money)  {
    int l = 0 , r = max_length , res = -1  ;
    while (l <= r) {
        int mid = (l+r) / 2 ;
        if (check(root,snum,money,mid)) res = mid , r = mid - 1 ; else l = mid + 1 ;
    }
    return res ;
}

void process () {
    prepare () ;

    int q = 0 ; cin >> q ;

    forinc(i,1,q){
        int r , g , a ; cin >> g >> r >> a ;
        cout << solve(r,g,a)  << endl ;
    }
}

int main () {
    //freopen("730C.inp" , "r" , stdin) ;

    enter () ;
    process () ;
    return 0 ;
}
