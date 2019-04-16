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
#define pli pair<long long , int>

template <class _T> bool maximize(_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize(_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

const int ooit = 2e9 ;
const long long ooll = 1e15 ;

using namespace std ;

#define maxN 55

int n , m , a[maxN][maxN] , comand[2 * maxN] , k = 0 , xs , ys , xe , ye ;

void enter () {
    cin >> n >> m ;
    forinc(i,1,n) forinc(j,1,m) {
        char c ; cin >> c;
        a[i][j] = (c == '#') ? 1 : 0 ;
        if (c == 'S') xs = i , ys = j ; else if (c == 'E') xe = i , ye = j ;
    }
    string st ; cin >> st ;
    for (auto tmp : st) comand[++k] = (int) tmp - (int) '0' ;
}

vector<int> X ;

int goX[4] = { -1 , 0 , +1 , 0} ;
int goY[4] = { 0 , +1 , 0 , -1} ;

bool check() {
    int x = xs , y = ys ;
    forinc(i,1,k) {
        int cx = x + goX[X[comand[i]]] , cy = y + goY[X[comand[i]]] ;
        if (cx <= 0 || cy <= 0 || cx > n || cy > m) return false ;
        if (a[cx][cy] == 1) return false ;
        if (cx == xe && cy == ye) return true ;
        x = cx ; y = cy ;
    }
    return false ;
}

void process() {
    forinc(i,0,3) X.push_back(i) ;
    int cnt = 0 ;
    do {
        if (check()) cnt ++ ;
    } while (next_permutation(X.begin() , X.end())) ;
    cout << cnt << endl ;
}

int main () {
    //freopen("908.inp" , "r" , stdin) ;
    enter () ;
    process() ;
    return 0 ;
}
