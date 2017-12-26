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
const int maxN = 55 ;

using namespace std ;

int r , c , a[maxN][maxN] ;

void enter () {
    cin >> r >> c ;
    forinc(i,1,r) forinc(j,1,c) cin >> a[i][j] ;
}

vector<pii> oil ;

void prepare () {
    forinc(i,1,r) forinc(j,1,c) if (a[i][j]) oil.push_back({i,j}) ;
}

bool dd[maxN * maxN] ;

int ACM(pii a , pii b) {return max(abs(b.fi - a.fi) , abs(b.se - a.se)) ; }

void reset() {forv(i,oil) dd[i] = false ; }

void process () {
    prepare() ;

    int ans = ooit ;

    forv(i,oil) {
        int res = 0 ; reset() ; dd[i] = true ;

        forinc(soil , 1 , oil.size() - 1) {
            int minw = ooit , coil = 0 ;
            forv(j,oil) if (!dd[j]) {
                int w =  0 ; forv(k,oil) if (dd[k]) maximize(w,ACM(oil[j],oil[k])) ;
                if (minimize(minw,w)) coil = j ;
            }
            dd[coil] = true ; res += minw ;
        }

        minimize(ans,res) ;
    }

    cout << ans << endl ;
}

int main () {
    freopen("OIL.inp" , "r" , stdin) ;
    freopen("OIL.out" , "w" , stdout) ;
    enter () ;
    process () ;
    return 0 ;
}
