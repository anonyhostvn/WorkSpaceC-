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
#define base 1000000007

using namespace std ;

int n ;
long long a[305] , f[305][305] , sum[305] , c[305][305] , g[305] ;
int select[305] ;
vector<int> group ;

int buildC()
{
    c[0][0] = 1 ;
    forinc(i,1,300) {c[0][i] = 1 ; c[i][i] = 1 ;}
    forinc(i,2,300)
    forinc(j,1,i-1) c[j][i] = (c[j-1][i-1] + c[j][i-1] ) % base ;
    g[0] = 1 ;
    forinc(i,1,300) {g[i] = g[i-1] * i ; g[i] %= base ; }
    return 0 ;
}

int enter()
{
    cin >> n ;
    forinc(i,1,n) cin >> a[i] ;
    return 0 ;
}

int prepare()
{
    forinc(i,1,n) if (!select[i]) {
        select[i] = true ;
        group.pb(1) ; int id = group.size() - 1 ;
        forinc(j,i+1,n) if ((int) sqrt(a[i] * a[j]) == (double) sqrt(a[i] * a[j])) {
            select[j] = true ;
            group[id] ++ ;
        }
    }
    sum[0] = group[0] ;
    for (int i = 1 ; i < group.size() ; i++) sum[i] = sum[i-1] + group[i] ;
    return 0 ;
}

int process()
{
    buildC() ;
    prepare() ;
    f[0][group[0]-1] = g[group[0]] ;
    int m = group.size() ;
    forinc(i,0,m-2)
    forinc(j,0,n) if (f[i][j]) {
        int total = sum[i] , tsize = group[i+1] ;
        forinc(s,1,min(tsize,total+1))
            forinc(d,0,min(j,s)) {
                long long T = c[s-1][tsize-1] * c[d][j] ; T %= base ;
                T *= g[tsize] ; T %= base ;
                if (d < s) T *= c[s-d][total-j+1] ; T %= base ;
                int newj = j - d + tsize - s ;
                f[i+1][newj] += f[i][j] * T ; f[i+1][newj] %= base ;
            }
    }
    cout << f[m-1][0] ;
}

int main()
{
    //freopen("841E.inp" , "r" , stdin) ;
    enter() ;
    process() ;
    return 0 ;
}
