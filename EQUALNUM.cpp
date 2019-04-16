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

template <class _T> bool maximize(_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize(_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

const int ooit = 2e9 ;
const long long ooll = 1e15 ;

using namespace std;

#define maxN 105
#define maxA 1000

int n , a[maxN] ,sum = 0 ;

void enter () {
    cin >> n ;
    forinc(i,1,n) cin >> a[i] ;
    forinc(i,1,n) sum += a[i] ;
}

int f[maxN][maxN * maxA] , nxt[maxN][maxN * maxA] ;

void prepare () {
    forinc(i,1,n) {
        int tsum = 0 ;
        forinc(j,i,n) tsum += a[j] , nxt[i][tsum] = j ;
    }

    forinc(i,0,sum) f[0][i] = 1 ;
}

void process () {
    prepare () ;

    forinc(i,0,n) forinc(j,0,sum) if (f[i][j] > 0) {
        if (nxt[i+1][j]) maximize(f[nxt[i+1][j]][j] , f[i][j] + 1) ;
        maximize(f[i+1][j] , f[i][j]) ;
    }

    int res = 0 ;
    forinc(i,0,sum) maximize(res , f[n][i]) ;

    vector<int> ans ; forinc(i,0,sum) if (res == f[n][i]) ans.push_back(i) ;
    sort(ans.begin() , ans.begin()) ;

    cout << res - 1 << endl ;
    for (auto tmp : ans) cout << tmp << " " ;
}

int main () {
    freopen("EQUALNUM.inp" , "r" , stdin) ;
    freopen("EQUALNUM.out" , "w" , stdout) ;
    enter () ;
    process () ;
    return 0 ;
}
