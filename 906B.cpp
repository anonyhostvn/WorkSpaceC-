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

int n , m ;
bool ok = false ;

void enter () {
    cin >> n >> m ;
    if (n > m) swap(n,m) , ok = true ;
}

bool ans = false ;

void special_case (vector<vector<int> > &a) {
    if (m == 1) a[1][1] = 1 , ans = true ;
    else if (m == 4) {
        ans = true ;
        a[1][1] = 2 ; a[1][2] = 4 ; a[1][3] = 1 ; a[1][4] = 3 ;
    }
    else if (m >= 5) {
        ans = true ; int cnt = 0 ;
        forinc(i,1,m) if (i & 1) a[1][++cnt] = i ;
        forinc(i,1,m) if (i % 2 == 0) a[1][++cnt] = i ;
    }
}

void print_row(int row , vector<vector<int> > &a) {
    int Tplus = (row-1) * m ;
    vector<int> temp ;

    if (row % 2 > 0) {

        if (m % 2 == 0) {
            forinc(i,1,m) if (i % 2 == 0) temp.push_back(a[row][i]) ;
            forinc(i,1,m) if (i % 2 != 0) temp.push_back(a[row][i]) ;
        } else {
            forinc(i,1,m) if (i % 2 != 0) temp.push_back(a[row][i]) ;
            forinc(i,1,m) if (i % 2 == 0) temp.push_back(a[row][i]) ;
        }
    }
    else {
        if (m % 2 == 0) {
            fordec(i,m,1) if (i % 2 != 0) temp.push_back(a[row][i]) ;
            fordec(i,m,1) if (i % 2 == 0) temp.push_back(a[row][i]);
        } else {
            forinc(i,1,m) if (i % 2 == 0) temp.push_back(a[row][i]) ;
            forinc(i,1,m) if (i % 2 != 0) temp.push_back(a[row][i]) ;
        }
    }

    forv(i,temp) a[row][i+1] = temp[i] ;
}

void solve(vector<vector<int> > &a) {
    ans = true ;
    forinc(i,1,n) print_row(i , a) ;
}

void process () {
    vector<vector<int> > a (n + 5 , vector<int> (m + 5)) , b (m + 5 , vector<int> (n + 5)) ;
    int cnt = 0 ;
    if (!ok) forinc(i,1,n) forinc(j,1,m) a[i][j] = ++cnt ;
    else forinc(j,1,m) forinc(i,1,n) a[i][j] = ++cnt ;

    if (n == 1) special_case(a) ;
    else if (n == 3 && m == 3) {
        ans = true ;
        a[1][1] = 6 ; a[1][2] = 1 ; a[1][3] = 8 ;
        a[2][1] = 7 ; a[2][2] = 5 ; a[2][3] = 3 ;
        a[3][1] = 2 ; a[3][2] = 9 ; a[3][3] = 4 ;
    }
    else if (n >= 2 && m >= 4) solve(a) ;

    if (!ans) cout << "NO" << endl ;
    else {
        cout << "YES" << endl ;
        if (!ok) forinc(i,1,n) {
            forinc(j,1,m) cout << a[i][j] << " " ; cout << endl ;
        } else forinc(i,1,m){
            forinc(j,1,n) cout << a[j][i] << " " ;  cout << endl ;
        }
    }
}

int main () {
    //freopen("906B.inp" , "r" , stdin) ;
    enter () ;
    process () ;
    return 0 ;
}
