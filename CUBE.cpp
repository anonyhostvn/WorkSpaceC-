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
#define ooll (long long) 1e15
#define ooit (int) 2e9

template <class _T> bool maximize(_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize(_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

using namespace std ;

struct node {
    int x[2] , y[2] , z[2] ;
};

#define maxN 55

node a[maxN] ;
int n , k ;

void enter () {
    cin >> n >> k ;
    forinc(i,1,n) cin >> a[i].x[0] >> a[i].y[0] >> a[i].z[0] >> a[i].x[1] >> a[i].y[1] >> a[i].z[1] ;
}

map<int,int> f[3] ;
int compress[3][2 * maxN] ;

void minimax(int id) {
    int last = -1 , cnt = 0 ;
    for (auto &tmp : f[id]) tmp.se = ++cnt , compress[id][cnt] = (last == -1) ? 1 : tmp.fi - last , last = tmp.fi ;
}

void prepare () {
    forinc(i,1,n) f[0][a[i].x[0]] = 0 , f[0][a[i].x[1]] = 0  , f[1][a[i].y[0]] = 0 , f[1][a[i].y[1]] = 0 , f[2][a[i].z[0]] = 0 , f[2][a[i].z[1]] ;
    forinc(i,0,2) minimax(i) ;
    forinc(i,1,n) a[i].x[0] = f[0][a[i].x[0]] , a[i].x[1] = f[0][a[i].x[1]] , a[i].y[0] = f[1][a[i].y[0]] , a[i].y[1] = f[1][a[i].y[1]] ,
                  a[i].z[0] = f[2][a[i].z[0]] , a[i].z[1] = f[2][a[i].z[1]] ;
}

int dd[2 * maxN][2 * maxN][2 * maxN] ;

void process () {
    prepare () ;
    //forinc(i,1,n) { forinc(j,0,1) cout << a[i].x[j] << " " <<  a[i].y[j] << " " << a[i].z[j] << " " ; cout << endl ; }
    long long res = 0  ;
    forinc(i,1,n) forinc(x,a[i].x[0]+1,a[i].x[1]) forinc(y,a[i].y[0]+1,a[i].y[1]) forinc(z,a[i].z[0]+1,a[i].z[1]) dd[x][y][z] ++ ;
    forinc(x,1,101) forinc(y,1,101) forinc(z,1,101)
        if (dd[x][y][z] >= k)
            res += (long long) compress[0][x] * compress[1][y] * compress[2][z] ;
    cout << res << endl ;
}

int main () {
    freopen("CUBE.inp" , "r" , stdin) ;
    freopen("CUBE.out" , "w" , stdout) ;
    enter () ;
    process () ;
    return 0 ;
}
