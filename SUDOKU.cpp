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
#define maxN 20

template <class _T> bool maximize(_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize(_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

using namespace std ;

int n , a[maxN * maxN][maxN * maxN] ;

void enter () {
    cin >> n ;
    forinc(i,1,n * n) forinc(j,1,n*n) cin >> a[i][j];
}

set<int> r[maxN] , c[maxN] ;

void prepare () {
    forinc(i,1,n * n) forinc(j , 1 , n * n) r[i].insert(j) , c[i].insert(j) ;
    forinc(i,1,n * n) {
        bool dd[maxN * maxN] ; forinc(i,1,n*n) dd[i] = false ;
        forinc(j,1,n * n) dd[a[i][j]] = true ;
    }
}

void process () {

}

int main () {
    return 0  ;
}
