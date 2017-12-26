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

#define maxN 2005

int n , m , a[maxN] , c ;

void enter () {
    cin >> n >> m >> c ;

    memset(a , -1 , sizeof(a)) ;
    int x = 0 ;
    while (cin >> x) {
        int pos = 0 ;
        if (x <= c / 2) forinc(i,1,n) if (a[i] == -1 || a[i] > x) {a[i] = x ; pos = i ; break ; }
        if (x > c / 2) fordec(i,n,1) if (a[i] == -1 || a[i] < x) {a[i] = x ; pos = i ; break ; }
        cout << pos << endl ;
        fflush(stdout) ;
    }
}

int main () {
    enter () ;
    return 0 ;
}
