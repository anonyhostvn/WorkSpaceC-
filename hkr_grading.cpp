#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)
#define forv(j,u) for (int j = 0 ; j < u.size() ; j++)
#define fi first
#define se second
#define pii pair<int,int>

template <class _T> bool maximize(_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize(_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

const int ooit = 2e9 ;
const long long ooll = 1e15 ;
const int base = 1000000007 ;

using namespace std ;

int print_ans(int x) {
    forinc(i,0,2) if ((x + i) % 5 == 0) return x + i ;
    return x ;
}

int main () {
    int n = 0 ;
    cin >> n ;
    forinc(i,1,n) {
        int grade = 0 ; cin >> grade ;
        if (grade < 38) cout << grade << endl ;
        else cout << print_ans(grade) << endl ;
    }
    return 0 ;
}
