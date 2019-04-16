#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)
#define forv(j,u) for (int j = 0 ; j < u.size() ; j++)
#define fi first
#define se second
#define pii pair<int,int>
#define pli pair<long long , int>

template <class _T> bool maximize(_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize(_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

const int ooit = 2e9 ;
const long long ooll = 1e15 ;

using namespace std ;

int n ;

void enter () {
    cin >> n ;
}

map<char,int> select , not_select ;

void shock_guess () {
    string st ; cin >> st ;
    if (select.empty()) {for (auto tmp : st) select[tmp] = 0 ; return ; }
    for (auto tmp : st) if (select.find(tmp) != select.end()) select[tmp] = 1 ;
    vector<char> Tchar , Cchar ;
    for (auto tmp : st) if (select.find(tmp) != select.end()) {
        if (select[tmp] == 1) Tchar.push_back(tmp) ; else Cchar.push_back(tmp) ;
    }
    select.clear() ; for (auto tmp : Tchar) select[tmp] = 0  ;
    for (auto tmp : Cchar) not_select[tmp] = 0 ;
}

void wrong_guess () {
    char c ; cin >> c ;
    not_select[c] = 0 ;
    if (select.find(c) != select.end()) select.erase(c) ;
}

void not_shock_guess () {
    string st ; cin >> st ;
    for (auto tmp : st) {
        not_select[tmp] = 0 ;
        if (select.find(tmp) != select.end()) select.erase(tmp) ;
    }
}

bool check_unique(){
    if (select.size() == 1 || not_select.size() == 25) return true ;
    int cnt = 0 ;
    for (char c = 'a' ; c <= 'z' ; c ++ ) if (not_select.find(c) == not_select.end() && select.find(c) != select.end()) cnt ++ ;
    return cnt == 1 ;
}

void process () {
    bool ok = false ; int res = 0 ;

    forinc(i,1,n-1) {
        char c ; cin >> c ;
        if (ok && (c == '!' ||c == '?')) res ++ ;
        if (c == '!') shock_guess() ; else if (c == '?') wrong_guess () ; else not_shock_guess ()  ;
        //for (auto tmp : select) cout << tmp.fi << " " ; cout << " --- " ;  for (auto tmp : not_select) cout << tmp.fi << " " ; cout << endl ;
        if (check_unique()) ok = true ;
    }

    cout << res << endl ;
}

int main () {
    //freopen("906A.inp"  , "r" , stdin) ;
    enter () ;
    process () ;
    return 0 ;
}
