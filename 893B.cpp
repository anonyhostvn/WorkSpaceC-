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

int n ;

bool check(int x) {
    for (int i = 1 ; (long long) ((1 << i) - 1) * (1 << (i-1)) <= x ; i ++) if (((1 <<i) - 1) * (1 << (i-1)) == x) return true ;
    return false ;
}

void enter() {
    cin >> n ;
    fordec(i,n,1) if (n % i == 0 && check(i)) {
        cout << i << endl ;
        return ;
    }
}

int main () {
    //freopen("893B.inp" , "r" , stdin) ;
    enter () ;
    return 0 ;
}
