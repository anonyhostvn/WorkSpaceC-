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

int k[4] ;

void enter () {
    cin >> k[1] >> k[2] >> k[3] ;
    sort(k + 1 , k + 1 + 3) ;
    if (k[1] == 1 || (k[1] == 2 && k[2] == 2) || (k[1] == 3 &&  k[2] == 3 &&  k[3] == 3) || (k[1] == 2 && k[2] == 4 && k[3] == 4)) cout << "YES" << endl ; else cout << "NO" ;
}

int main () {
    //freopen("911C.inp" , "r" , stdin) ;
    enter () ;
    return 0 ;
}
