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
#define maxN 25
#define maxS 1500000

using namespace std ;

int n , m ;
bool connect[maxN][maxN] ;

void enter() {
    cin >> n  >> m ;
    forinc(i,1,m) {
        int u , v ; cin >> u >> v ;
        connect[u][v] = true ; connect[v][u] = true ;
    }
}

int status = 0 ;

int get_bit(int x , int i) {return (x >> i) & 1 ;}
int on_bit(int x , int i) {return x | (1 << i) ; }
int off_bit(int x , int i) {return x & (~(1 << i)) ;}

int f_bit[maxS] , dp2[maxS] ;

void prepare()  {
    status = (1 << n) - 1 ;
    forinc(i,0,status) fordec(j,n-1,0) if (get_bit(i,j) == 1) {f_bit[i] = j ; break ;  } ;
    forinc(s,1,status) {
        int stt = off_bit(s,f_bit[s]) ; dp2[s] = dp2[stt] ;
        forinc(i,1,n) if (connect[i][f_bit[s]+1]) {
            if (get_bit(s,i-1) == 1) dp2[s] -- ; else dp2[s] ++ ;
        }
    }
}

int dp[maxS] ;

int minimize(int &a , int b) {a = min(a,b) ; }

void process() {
    prepare() ;
    forinc(i,1,status) dp[i] = ooit ;
    forinc(i,0,status)
        forinc(j,1,n) if (get_bit(i,j-1) == 0) minimize(dp[on_bit(i,j-1)],dp[i] + dp2[i]) ;
    cout << dp[status] << endl ;
}

int main() {
    freopen("SERVER.inp" , "r" , stdin) ;
    freopen("SERVER.out" , "w" , stdout) ;
    enter() ;
    process()  ;
    return 0 ;
}
