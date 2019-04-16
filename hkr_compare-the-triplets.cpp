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

using namespace std;

int main () {
    int a[3] , b[3] , Alice_score = 0 , Bob_score = 0 ;
    cin >> a[0] >> a[1] >> a[2] ;
    cin >> b[0] >> b[1] >> b[2] ;
    forinc(i,0,2) if (a[i] > b[i]) Alice_score ++ ; else if (a[i] < b[i]) Bob_score ++ ;
    cout << Alice_score << " " << Bob_score << endl ;
    return 0 ;
}
