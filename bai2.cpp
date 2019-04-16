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

long long n ;
int k ;

void enter () {
    cin >> n >> k ;
}

vector<int> a ;
void factor(long long x) {
    if (x > 0) factor(x/10) ;
    if (x > 0) a.push_back(x % 10) ;
}

void prepare () {
    if (n > 0) factor(n) ; else a.push_back(0) ;
}

#define maxD 20
#define maxK 10005
#define base 1000000007

long long f[maxD][maxK][2][2] ;

long long cal(int i , int mul , int ok , int smaller) {
    if (f[i][mul][ok][smaller] > -1) return f[i][mul][ok][smaller] ;
    if (i == a.size()) {
        if (!ok) mul = 0 ; f[i][mul][ok][smaller] = (k == mul) ? 1 : 0 ;
        return f[i][mul][ok][smaller] ;
    }

    long long res = 0 ;
    int last = (smaller) ? 9 : a[i] ;
    forinc(j , 0 , last) if ((long long) j * mul <= k) {
        int okt = (ok || j > 0) ? 1 : 0 , Tsmaller = (smaller || j < a[i]) ? 1 : 0 , Tmul = (okt) ? mul * j : mul ;
        res += cal(i + 1 , Tmul , okt , Tsmaller) ; res %= base ;
    }

    f[i][mul][ok][smaller] = res ;
    return res ;
}

void process () {
    prepare () ;
    memset(f , -1 , sizeof(f)) ;
    cout << cal(0 , 1 , 0 , 0) << endl ;
}

int main () {
    freopen("bai2.inp" , "r" , stdin) ;
    freopen("bai2.out" , "w" , stdout) ;
    enter () ;
    process () ;
    return 0 ;
}
