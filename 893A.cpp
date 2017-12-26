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
#define ooll (long long) 1e15
#define ooit (int) 2e9

template <class _T> bool maximize(_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize(_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

using namespace std ;

int n , player_1 = 0 , player_2 = 0 , specta = 0 ;

void enter () {
    cin >> n ;
    player_1 = 1 ; player_2 = 2 ; specta = 3 ;

    forinc(i,1,n) {
        int x = 0 ; cin >> x ;
        if (player_1 == x) swap(player_2,specta) ;
        else if (player_2 == x) swap(player_1,specta) ;
        else {cout << "NO" << endl ; return ; }
    }
    cout << "YES" << endl ;
}

int main () {
    //freopen("893A.inp" , "r" , stdin) ;

    enter() ;
    return 0 ;
}
