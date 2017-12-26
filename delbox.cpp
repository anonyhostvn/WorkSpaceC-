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
#define maxN 1005

using namespace std ;

int n , m , a[maxN][maxN] , max_row[maxN] , max_col[maxN] , num_use[maxN][maxN] ;
bool dd_row[maxN] , dd_col[maxN] ;
long long sum = 0 ;

int main()
{
    //freopen("delbox.inp" , "r" , stdin) ;
    cin >> n >> m ;
    forinc(i,1,n) forinc(j,1,m) {
        cin >> a[i][j] ; sum += a[i][j] ;
        max_row[i] = max(max_row[i],a[i][j]) ;
        max_col[j] = max(max_col[j],a[i][j]) ;
    }
    forinc(i,1,n) forinc(j,1,m) {
        if (a[i][j] == max_row[i]) num_use[i][j] += 1 ;
        if (a[i][j] == max_col[j]) num_use[i][j] += 2 ;
    }
    long long res = 0 ;
    forinc(i,1,n) forinc(j,1,m) if (num_use[i][j] == 3) dd_row[i] = true , dd_col[j] = true , res += a[i][j];
    forinc(i,1,n) forinc(j,1,m) {
        if (num_use[i][j] == 1 && !dd_row[i]) dd_row[i] = true , res += a[i][j] ;
        if (num_use[i][j] == 2 && !dd_col[j]) dd_col[j] = true , res += a[i][j] ;
    }
    cout << sum - res << endl ;
    return 0 ;
}
