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
#define oo (int) 1e9 + 7
#define maxN 105

using namespace std ;

int n , m , k , a[maxN][maxN] , f_one[maxN] , f[maxN][maxN] ;
pii f_max[maxN] ;

void enter()
{
    cin >> n >> m >> k ;
    forinc(i,1,n) forinc(j,1,m) {
        cin >> a[i][j] ;
        if (a[i][j] == 1 && f_one[j] == 0) f_one[j] = i ;
        f[i][j] = f[i-1][j] + a[i][j] ;
    }
}

int get(int col , int i , int j) {return f[j][col] - f[i-1][col] ; }

void build()
{
    forinc(col,1,m) {
        int id = 0 , res = 0 ;
        forinc(i,1,n) if (a[i][col] == 1 && res < f[min(n,i+k-1)][col] - f[i-1][col]) id = i , res = f[min(n,i+k-1)][col] - f[i-1][col] ;
        f_max[col].fi = id ; f_max[col].se = res ;
    }
}

void process()
{
    build() ;
    int res = 0 , tres = 0 ;
    forinc(i,1,m) if (f_one[i] > 0) {
        int id_1 = f_one[i] , id_2 = f_max[i].fi ;
        res += f_max[i].se ; tres += f[id_2-1][i] - f[id_1-1][i] ;
    }
    cout << res << " " << tres << endl ;
}

int main()
{
    //freopen("873C.inp" , "r" , stdin) ;
    enter() ;
    process() ;
    return 0 ;
}
