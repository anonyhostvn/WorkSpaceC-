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

#define maxN 10005
#define maxS 20

int n , pos[26] ;
vector<int> a[maxN] , acsi ;

void init() {
    forinc(i,0,25) pos[i] = -1 ;
    acsi.push_back(0) ; acsi.push_back('e' - 'a') ;
    acsi.push_back('i' - 'a') ; acsi.push_back('o' - 'a') ; acsi.push_back('u' - 'a') ;
    pos[0] = 0 ; pos['e'-'a'] = 1 ; pos['i' - 'a'] = 2 ; pos['o'-'a'] = 3 ; pos['u'-'a'] = 4 ;
}

void enter () {
    cin >> n ;
    forinc(i,1,n) {
        a[i].clear() ;
        string st ; cin >> st ;
        forinc(j,0,st.length()-1) a[i].push_back((int) st[j] - (int) 'a') ;
    }
}

int cnt[26] ;
bool dd[26] , exist[maxN][26] ;

void prepare () {
    memset(cnt , 0 , sizeof(cnt)) ;
    memset(exist , false , sizeof(exist)) ;

    forinc(i,1,n) {
        memset(dd , false , sizeof(dd)) ;
        for (auto ch : a[i]) if (!dd[ch]) dd[ch] = true , cnt[ch] ++ , exist[i][ch] = true ;
    }

}

void trau() {
    prepare () ;
    int cnt = 0 ;

    forinc(i,1,n-2) forinc(j,i+1,n-1) forinc(k,j+1,n)
    for (auto ch : acsi) if (exist[i][ch] && exist[j][ch] && exist[k][ch]) {cnt ++ ; break ; } ;

    cout << cnt << endl ;
}

long long f1[32] , f2[32];

int get_bit(int x , int i) {
    return (x >> i) & 1 ;
}

int on_bit(int x , int i) {
    return  (1 << i) | x ;
}

int get_status(int id) {
    int res = 0 ;
    for (auto ch : a[id]) if (pos[ch] >-1) res = on_bit(res,pos[ch]) ;
    return res ;
}

void process () {
    memset(f1 , 0 , sizeof(f1)) ;
    memset(f2 , 0 , sizeof(f2)) ;
    long long res = 0 ;

    forinc(i,1,n) {
        int A = get_status(i) ;
        forinc(i,1,31) if ((A & i) > 0) res += f2[i] ;
        forinc(i,1,31) if ((A & i) > 0) f2[A & i] += f1[i] ;
        if (A > 0) f1[A] ++ ;
    }

    cout << res << endl ;
}

int main () {
    freopen("MUSKETEERS.inp" , "r" , stdin) ;
    //freopen("MUSKETEERS.out" , "w" , stdout) ;
    init() ;
    int t = 0 ; cin >> t ;
    while (t--) enter () , process () ;
    return 0 ;
}
