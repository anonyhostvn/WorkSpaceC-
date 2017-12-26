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
#define maxN 51
#define base 1000000007

using namespace std ;

int n , a[maxN] , f[maxN][maxN*maxN][maxN] , maxs = 0 , maxa = 0 , fgcd[maxN][maxN] ;
bool ok[5000] ;

void enter()
{
    cin >> n ;
    forinc(i,1,n) cin >> a[i] , maxs += a[i] , maxa = max(maxa,a[i]) ;
}

int gcd(int a , int b)
{
    if (a == 0) return b ; else if (b == 0) return a ;
    while (b != 0) {
        int tmp = a % b ;
        a = b ; b = tmp ;
    }
    return a ;
}

void prepare()
{
    forinc(i,0,12) ok[(1<<i)] = true  ;
    forinc(i,0,50)
    forinc(j,0,50) fgcd[i][j] = gcd(i,j) ;
}

bool check(int a , int b)
{
    double c = (double) a / b ;
    if ((int) c != c) return false ;
    return ok[(int) c] ;
}

void process()
{
    prepare() ;
    forinc(i,0,a[1]) f[1][i][i] = 1 ;
    forinc(i,1,n-1)
    forinc(sum,0,maxs)
    forinc(g,0,maxa) if (f[i][sum][g] > 0)
        forinc(nxt,0,a[i+1]) f[i+1][sum+nxt][fgcd[g][nxt]] += f[i][sum][g] , f[i+1][sum+nxt][fgcd[g][nxt]] %= base ;
    int res = 0 ;
    forinc(sum,1,maxs)
    forinc(g,1,maxa) if (check(sum,g)) res += f[n][sum][g] , res %= base ;
    cout << res << endl ;
}

int main()
{
    //freopen("LIKECS04.inp" , "r" , stdin) ;
    enter() ;
    process() ;
    return 0 ;
}
