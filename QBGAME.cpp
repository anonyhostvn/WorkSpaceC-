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
#define maxN 10000
#define oo 1000000000000000

using namespace std ;

int n , s , cnt = 0 , status[60] , a[9][maxN+1];
bool ok[60][60] ;
long long sum[maxN+1][60] , f[maxN+1][60][2] ;

int enter()
{
    cin >> n ;
    forinc(i,1,8)
    forinc(j,1,n) cin >> a[i][j] ;
    s = 255 ;
    return 0 ;
}

int getbit(int st , int i)
{
    return (st >> i) & 1 ;
}

bool checkum(int st)
{
    forinc(i,1,7) if (getbit(st,i) == 1 &&  getbit(st,i-1) == 1) return false ;
    return true ;
}

long long nsum(int i , int stt)
{
    long long res = 0 ;
    forinc(j,1,8) if (getbit(stt,j-1) == 1) res += (long long) a[j][i] ;
    return res ;
}

int prepare()
{
    forinc(i,0,s) if (checkum(i)) status[++cnt] = i ;
    forinc(i,1,cnt)
    forinc(j,1,cnt) if ((status[i] & status[j]) == 0) ok[i][j] = true ;
    forinc(i,1,n)
    forinc(j,1,cnt) sum[i][j] = nsum(i,status[j]) ;
    return 0 ;
}

int process()
{
    prepare() ;
    forinc(i,0,n)
    forinc(j,1,cnt)
    forinc(t,0,1) f[i][j][t] = -oo ;
    f[0][1][0] = 0 ;
    forinc(i,0,n-1)
    forinc(j,1,cnt)
    forinc(t,0,1) if (f[i][j][t] > -oo)
        forinc(k,1,cnt) if (ok[j][k]) {
            int tmp = 0 ;
            if (t == 1 || k > 1) tmp = 1 ;
            f[i+1][k][tmp] = max(f[i+1][k][tmp],f[i][j][t] + sum[i+1][k]) ;
        }
    long long res = -oo ;
    forinc(i,1,cnt) res = max(res,f[n][i][1]) ;
    cout << res ;
    return 0 ;
}

int main()
{
    //freopen("QBGAME.inp" , "r" , stdin) ;
    enter() ;
    process() ;
    return 0 ;
}
