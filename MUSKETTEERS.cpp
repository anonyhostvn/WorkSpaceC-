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

int n ;
string st[maxN] ;

void enter () {
    cin >> n ;
    forinc(i,1,n) cin >> st[i] ;
}

int cnt['z'] ;
bool dd['z'] ;

void prepare () {
    memset(cnt , 0 , sizeof(cnt)) ;

    forinc(i,1,n) {
        memset(dd , false , sizeof(dd)) ;
        for (auto ch : st[i]) if (!dd[ch]) dd[ch] = true , cnt[ch] ++ ;
    }
}

long long solve(char ch) {
    return (long long) cnt[ch] * (cnt[ch] - 1) * (cnt[ch] - 2) / 6 ;
}

void process () {
    prepare () ;
    long long res = solve('a') + solve('e') + solve('i') + solve('o') + solve('u') ;
    cout << res << endl ;
}

int main () {
    freopen("MUSKETEERS.inp" , "r" , stdin) ;
    //freopen("MUSKETEERS.out" , "w" , stdout) ;
    int t = 0 ; cin >> t ;
    while (t--) enter () , process () ;
    return 0 ;
}
