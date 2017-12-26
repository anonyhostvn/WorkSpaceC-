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
#define oo 1000000000
#define maxN 100001

using namespace std ;
int n , f[maxN] , trc[maxN];
string st = ""  ;

int trace (int n, int ch)
{
    if (n == 0) return 0 ;
    int j = trc[n] ;
    forinc(i,1,j) st += (char) ((int) 'a' + ch) ;
    trace(n - (j-1) * j / 2 , ch + 1) ;
    return 0 ;
}

int enter()
{
    cin >> n ;
    forinc(i,0,n) f[i] = oo ;
    f[0] = 0 ;
    forinc(i,0,n) if (f[i] > -1) {
        for (int j = 2 ; j * (j-1) / 2 <= n ; ++j) if (i + (j-1) * j / 2) {
            int id = (j - 1) * j / 2;
            if (i + id <= n && f[i+id] > f[i] + 1) f[i+id] = f[i] + 1 , trc[i+id] = j ;
        }
    }
    trace(n,0) ;
    cout << st ;
    return 0 ;
}

int main()
{
    freopen("849C.inp" , "r" , stdin) ;
    enter() ;
    return 0 ;
}
