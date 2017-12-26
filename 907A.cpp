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

int v1 , v2 , v3 , vm ;

void enter () {
    cin >> v1 >> v2 >> v3 >> vm ;
}

bool check() {
    if (max(v1,vm) > 2 * v1) return false;
    if (max(v2,vm) > 2 * v2) return false ;
    if (max(vm,v3) > min(2 * vm , 2 * v3)) return false ;
    return true ;
}

void process () {
    if (!check()) cout << -1 ; else {
        int car1 = 2 * v1 , car2 = -1 , car3 = -1 ;
        fordec(i , car1-1 , max(vm,v2)) if (i >= max(vm,v2) && i <= 2 * v2) {car2 = i ; break ; }
        if (car2 == -1) {cout << -1 ; return ; }
        fordec(i , car2 - 1 , max(vm,v3)) if (i >= max(vm,v3) && i <= min(2 * vm , 2 * v3)) {car3 = i ; break ; }
        if (car3 == -1) {cout << -1 ; return ; }
        if (2 * vm >= car1) {cout << -1 ; return ; }
        if (2 * vm >= car2) {cout << -1 ; return ; }
        cout << car1 << endl << car2 << endl << car3  ;
    }
}

int main () {
    //freopen("907A.inp" , "r" , stdin) ;
    enter () ;
    process () ;
    return 0 ;
}
