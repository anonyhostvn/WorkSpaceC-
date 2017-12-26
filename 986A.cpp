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
const long long ooll = 1e18 ;

using namespace std ;

string st0 , st1 , st2 , st3 ;
int L0 , L1 , L2 , L3 , k ;

void prepare() {
    st0 = "What are you doing at the end of the world? Are you busy? Will you save us?" ; L0 = st0.length() ;
    st1 = "What are you doing while sending \"" ; L1 = st1.length() ;
    st2 = "\"\? Are you busy\? Will you send \"" ; L2 = st2.length() ;
    st3 = "\"\?" ; L3 = st3.length() ; k = L1 + L2 + L3 ;
}

#define maxG (long long) 1e18 + 1

long long power(int x , int i) {
    if (i == 0) return 1 ;
    if (i == 1) return x ;
    long long tmp = power(x , i / 2) ;
    return (i % 2 == 0) ? tmp * tmp : tmp * tmp * x ;
}

#define maxN 100005

long long f[maxN] ;

void build() {
    f[0] = L0 ;
    forinc(i,1,100000) if (f[i-1] * 2 + k <= maxG) f[i] = f[i-1] * 2 + k ; else f[i] = maxG + 1 ;
}

char res ;

char cal(int i, long long k) {
    if (i == 0) return st0[k-1] ;

    if (L1 >= k) return st1[k-1] ; k -= L1 ;
    if (f[i-1] >= k) return cal(i-1,k) ; k -= f[i-1] ;
    if (L2 >= k) return st2[k-1] ; k -= L2 ;
    if (f[i-1] >= k) return cal(i-1,k) ; k -= f[i-1] ;
    return st3[k-1] ;
}

void process () {
    prepare () ;
    build() ;

    int q = 0 ; cin >> q ;
    forinc(i,1,q) {
        int n = 0 ; long long num = 0 ; cin >> n >> num ;
        if (num > f[n]) cout << '.' ; else cout << cal(n,num) ;
    }
}

int main () {
    //freopen("986A.inp" , "r" , stdin) ;
    process () ;
    return 0 ;
}
