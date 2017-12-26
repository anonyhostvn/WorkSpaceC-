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
#define oo (long long) 1e15
#define maxN 40

using namespace std ;

int n , m  , a[maxN][maxN] ;
int gox[4] = { 0 , 0 , -1 , +1} ;
int goy[4] = {-1 , +1 , 0 ,  0} ;

void enter()
{
    cin >> m >> n ;
    forinc(i,0,m-1) forinc(j,0,n-1) cin >> a[i][j]  ;
}

vector<int> plus_(vector<int> a , vector<int> b)
{
    vector<int> res ;
    int temp = 0 ;
    forv(i,a) {
        int debug = a[i] + b[i] + temp , c = (a[i] + b[i] + temp) % 10;temp = (a[i] + b[i] + temp) / 10 ;
        res.push_back(c) ;
    }
    if (temp != 0) res.push_back(temp) ;
    return res ;
}

vector<int> power(int x)
{
    vector<int> res ;
    if (x == 0) {res.push_back(1) ; return res ; }
    res.push_back(2) ;
    forinc(i,1,x-1) res = plus_(res,res) ;
    return res ;
}

void print(vector<int> x)
{
    fordec(i,x.size()-1,0) cout << x[i] ;
}

vector<int> x[maxN * maxN] ;

void plus_ans(int u , int v){ forv(i,x[u]) x[v][i] += x[u][i] , x[v][i] %= 2 ; }

void khu_gauss(int u , int v) { forinc(i,u+1,m*n-1) if (x[i].size() > 0 && x[i][v] == 1) plus_ans(u,i) ; }

int check_ans(int u) {
    forinc(i,0,x[u].size()-2) if (x[u][i] == 1) return 0 ;
    if (x[u].back() == 0) return 1 ; return -1 ;
}

void solve()
{
    int k = m * n ;
    //cout << x[0].size() ;
    forinc(i,0,m*n-1)
        if (x[i].size() == 0) k -- ; else forinc(j,0,x[i].size()-2) if (x[i][j] == 1) khu_gauss(i,j) ;
    forinc(i,0,m*n-1) if (x[i].size() > 0) {
        int temp = check_ans(i) ;
        if (temp == 1) k -- ; else if (temp == -1) { cout << 0 ; return ; }
    }
    //cout << k << endl ;
    print(power(m*n-k)) ;
}

void process()
{
    forinc(i,0,m-1) forinc(j,0,n-1) if (a[i][j] != -1) {
        forinc(u,0,m-1) forinc(v,0,n-1) if (abs(u-i) + abs(v-j) == 1) x[i*n+j].push_back(1) ; else x[i * n + j].push_back(0) ;
        x[i*n+j].push_back(a[i][j]) ;
    }
    /*forinc(i,0,m*n-1) {
        forv(j,x[i]) cout << x[i][j] << " " ; cout << endl ;
    }*/
    solve() ;
}

int main()
{
    freopen("BOMB.inp" , "r" , stdin) ;
    freopen("BOMB.out" , "w" , stdout) ;
    enter() ;
    process() ;
    return  0 ;
}
