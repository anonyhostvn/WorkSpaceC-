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
#define maxN 5

using namespace std ;

int n , m , a[maxN][maxN] , s , f[65600] ;

int enter()
{
    cin >> m >> n ;
    s = (1 << (m * n)) - 1 ;
    forinc(i,1,m) forinc(j,1,n) cin >> a[i][j] ;
    return 0 ;
}

int getbit(int x  , int i) { return (x >> (i-1)) & 1 ; }
int onbit(int x , int i) {return (1 << (i-1)) | x ; }

int process()
{
    forinc(i,0,s) f[i] = -1 ;
    f[0] = 0 ;
    forinc(stt,0,s) if (f[stt] > -1) {
        forinc(i,1,m) forinc(j,1,n) if (getbit(stt,n * (i-1) + j) == 0) {
            int tmp = 0 , ntt = stt ;
            forinc(k,j,n) {
                int id = (i-1) * n + k ;
                if (getbit(stt,id) == 1) break ;
                tmp *= 10 ; tmp += a[i][k] ; ntt = onbit(ntt,id) ;
                f[ntt] = max(f[ntt],f[stt] + tmp) ;
            } tmp = 0 ; ntt = stt ;
            forinc(k,i,m) {
                int id = (k-1) * n + j ;
                if (getbit(stt,id) == 1) break ;
                tmp *= 10 ; tmp += a[k][j] ; ntt = onbit(ntt,id) ;
                f[ntt] = max(f[ntt],f[stt] + tmp) ;
            }
        }
    }
    cout << f[s] << endl ;
    return 0 ;
}

int main()
{
    freopen("C11CUT.inp" , "r" , stdin) ;
    enter() ;
    process() ;
    return 0 ;
}
