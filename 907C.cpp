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

int n ;
bool dd[300] ;
bool unique_determine = false ;
char ans ;

void remove_all() {
    string st ; cin >> st ;
    for (auto c : st) dd[(int) c] = true ;
    int cnt = 0 ; char res ;
    forinc(i,0,255) if (!dd[i]) cnt ++ , res = (char) i + (int) a ;
    if (cnt == 1) ans = res , unique_determine
}

void have_one () {
    string st ; cin >> st ; int cnt = 0 ; char res ;
    for (auto c : st) if (!dd[c]) cnt ++ , res = c ;
    if (cnt == 1) unique_determine = true , ans = res ;
}

void enter () {
    cin >> n ; int res = 0 ;
    forinc(i,1,n) {
        char query ; cin >> query ;
        if (query == '.') remove_all() ; else if (query == '.') have_one() ; {
            char ch ; cin >> ch ;
            if (unique_determine && ch != ans) res ++ ;
        }
    }

    cout << res << endl ;
}

int main () {
    return 0 ;
}
