#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i--)

using namespace std ;

int m,n,tt[301],f[301][301],s ;
bool ok[301][301] ;

int enter()
{

    cin >> m >> n ;

}

int pow(int x,int n)
{

    if (n == 1) return x ;

    if (n == 0) return 1 ;

    int tmp = pow(x,n/2);

    if (n % 2 == 0) return tmp * tmp ; else return tmp * tmp * x ;

}

bool check(int x)
{
    int a = x >> m;
	int b = x & ((1<<m) - 1);
	return !((a & (b>>2)) || (b & (a>>2)));
}

bool checkum(int x, int y)
{
    if ((x >> m) != (y&((1<<m) - 1))) return 0;
	int a = x & ((1<<m) - 1);
	int b = y >> m;
    return !((a & (b>>1)) || (b & (a>>1)));
}

int prepare()
{

    int k = pow(2,m*2) , cnt = 0  ;

    forinc(i,0,k)
    if (check(i))
    {

        cnt ++ ;
        tt[cnt] = i ;

    }

    forinc(i,1,cnt)
    forinc(j,1,cnt)
    if ((i != j) && (checkum(tt[i],tt[j]))) ok [i][j] = true ;

    s = cnt ;

}

int process()
{

    prepare() ;

    f[0][0] = 1 ;

    forinc(i,0,n-1)
    forinc(tt,1,s)
    if (f[i][tt] > 0)
    {

        forinc(stt,1,s)
        if (ok[tt][stt]) f[i+1][stt] = f[i][tt] + f[i+1][stt] ;

    }

    int res = 0 ;

    forinc(i,1,s) res += f[n][i] ;

    cout << res ;

}

int main()
{

    freopen("KNIGHT.inp" , "r" , stdin) ;
    //freopen("KNIGHT.out" , "w" , stdout) ;

    enter( ) ;
    process() ;

}
