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

int fastRead() {
    int res = 0 ; char c ;
    for (c = getchar() ; c < '0' || c > '9' ; c = getchar()) ;
    for ( ; c >= '0' && c <= '9' ; c = getchar()) res *= 10 , res += c - (int) '0' ;
    return res ;
}

#define maxN 1000005

int n , a[maxN] ;

void enter () {
    n = fastRead() ;
    forinc(i,1,n) a[i] = fastRead() ;
}

int L[maxN] , R[maxN] ;

void prepare () {
    stack<int> st ;

    forinc(i,1,n) {
        while (!st.empty() && a[i] <= a[st.top()]) st.pop() ;
        if (!st.empty()) L[i] = st.top() ; st.push(i) ;
    }

    while (!st.empty()) st.pop() ;

    fordec(i,n,1) {
        while (!st.empty() && a[i] <= a[st.top()]) st.pop() ;
        if (!st.empty()) R[i] = st.top() ; st.push(i) ;
    }
}

void process () {
    prepare() ;
    int res = 0 ;

    forinc(i,1,n) {
        if (L[i] > 0) maximize(res , a[i] ^ a[L[i]]) ;
        if (R[i] > 0) maximize(res , a[i] ^ a[R[i]]) ;
    }

    cout << res << endl ;
}

int main () {
    freopen("SUBSEQ.inp" ,"r" , stdin) ;
    freopen("SUBSEQ.out" , "w" , stdout) ;
    enter () ;
    process () ;
    return 0 ;
}
