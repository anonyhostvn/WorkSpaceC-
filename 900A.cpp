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

void enter () {
    cin >> n ;

    int cnt_posi = 0 , cnt_nega = 0 ;

    forinc(i,1,n) {
        int x , y ; cin >> x >> y ;
        if (x < 0) cnt_posi ++ ; else cnt_nega ++ ;
    }

    if (cnt_posi <= 1 || cnt_nega <= 1) cout << "Yes" ; else cout << "No" ;
}

int main () {
    //freopen("900A.inp" , "r" , stdin) ;

    enter () ;

    return 0 ;
}
