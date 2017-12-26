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
#define maxN 5005

using namespace std ;

string st ;
int n , a[maxN] ;

void enter()
{
    cin >> st ; n = st.length() ;
    forinc(i,1,n) a[i] = (int) st[i-1] ;
}

int f[maxN][4] ;

void process()
{
    forinc(i,0,n) forinc(j,0,3) f[i][j] = -1 ;
    f[0][0] = 0;
    forinc(i,0,n-1) forinc(j,0,3) if (f[i][j] > -1) {
        f[i+1][j] = max(f[i+1][j],f[i][j]) ;
        if (j == 0) {
            if (a[i+1] == (int) 'a') f[i+1][1] = max(f[i+1][1],f[i][j] + 1) ;
            if (a[i+1] == (int) 'b') f[i+1][2] = max(f[i+1][2],f[i][j] + 1) ;
        }
        if (j == 1) {
            if (a[i+1] == (int) 'a') f[i+1][j] = max(f[i+1][j],f[i][j] + 1) ;
            else f[i+1][j+1] = max(f[i+1][j+1],f[i][j] + 1) ;
        }
        if (j == 2) {
            if (a[i+1] == (int) 'b') f[i+1][j] = max(f[i+1][j],f[i][j] + 1) ;
            else f[i+1][j+1] = max(f[i+1][j+1],f[i][j] + 1) ;
        }
        else if (j == 3) {
            if (a[i+1] == (int) 'a') f[i+1][j] = max(f[i+1][j],f[i][j] + 1) ;
        }
    }
    int res = 0 ;
    forinc(i,1,n) forinc(j,0,3) res = max(res,f[i][j]) ;
    cout << res << endl ;
}

int main()
{
    //freopen("877B.inp" , "r" , stdin) ;
    enter() ;
    process() ;
    return 0 ;
}
