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

using namespace std ;

int k , m ;
string st ;

void enter () {
    cin >> k >> m ;
    cin >> st ;
}

void active(int a , int b , int c) {
    int L = st.length() ;
    string sta = "" , stb = "" ;
    forinc(i,a,b-1) sta.push_back(st[i]) ;
    forinc(i,c,L-1) stb.push_back(st[i]) ;
    forinc(i,c,L-1) st.pop_back() ;

    for (auto c : sta) st.push_back(c) ;
    for (auto c : stb) st.push_back(c) ;
    while (st.length() > m) st.pop_back() ;
}

void process () {
    int n = 0 ; cin >> n ;
    forinc(i,1,n) {
        int a , b , c ;
        cin >> a >> b >> c ;
        active(a,b,c) ;
    }

    forinc(i,0,k-1) cout << st[i] ;
}

int main () {
    freopen("FASTTYPE.inp" , "r" , stdin) ;
    freopen("FASTTYPE.out" , "w" , stdout) ;
    ios_base::sync_with_stdio(false) ; cin.tie(nullptr) ;
    enter () ;
    process () ;
    return 0 ;
}
