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

int main () {
    freopen("test_1.out" , "w" , stdout) ;
    int A[5] = {1 , 1 , 2 , 3 , 4} , cnt = 0 ;
    do {
        for (auto v : A) cout << v << " " ; cout << endl ;
    } while (next_permutation(A,A+5)) ;
    cout << cnt << endl ;
    return 0 ;
}
