#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)
#define forv(j,u) for (int j = 0 ; j < u.size() ; j++)
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define mk make_pair
#define pii pair<int,int>x`
#define ooll (long long) 1e15
#define ooit (int) 2e9
#define maxM 100005
#define maxN 505

template <class _T> bool maximize (_T &a , _T b) { return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize (_T &a , _T b) { return a > b ? a = b , 1 : 0 ; }

using namespace std ;

struct node {
    int _size , _prize ;
};

int  m , n , manju[maxM] ;
node box[maxN] ;

void enter() {
    cin >> m >> n ;
    forinc(i,1,m) cin >> manju[i] ;
    forinc(i,1,n) cin >> box[i]._size >> box[i]._prize ;
    sort(manju+1,manju+1+m , greater<int>() ) ;
}

long long f[maxN][maxM] ;

bool cmp(node a , node b) {return a._prize > b._prize ; }

void process() {
    sort(box+1,box+1+n,cmp) ;
    forinc(i,0,n) forinc(j,0,m) f[i][j] = ooll ;
    f[0][0] = 0 ;
    forinc(i,0,n) forinc(j,0,m) if (f[i][j] < ooll) {
        minimize(f[i+1][j],f[i][j]) ;
        minimize(f[i+1][min(j + box[i+1]._size , m)],f[i][j] + box[i+1]._prize) ;
    }
    long long sum = 0 , res = 0 ;
    forinc(i,1,m) {
        sum += manju[i] ;
        res = max(res,sum - f[n][i]) ;
    }
    cout << res << endl ;
}

int main() {
    freopen("JOIB.inp" , "r" , stdin) ;
    freopen("JOIB.out" , "w" , stdout) ;
    enter() ;
    process() ;
    return 0 ;
}
