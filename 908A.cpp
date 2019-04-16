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
#define pli pair<long long , int>

template <class _T> bool maximize(_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize(_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

const int ooit = 2e9 ;
const long long ooll = 1e15 ;

using namespace std ;

bool vowel(char c) {
    return (c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u') ;
}

int main () {
    //freopen("908.inp" , "r" , stdin) ;
    string st ; cin >> st ;
    int cnt = 0 ;
    for (auto tmp : st) if (tmp >= 'a' && tmp <= 'z' && vowel(tmp)) cnt ++ ;
    else if (tmp >= '0' && tmp <= '9' && ((int) tmp - (int) '0') % 2 != 0) cnt ++ ;
    cout << cnt << endl ;
}
