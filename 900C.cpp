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

#define maxN 100005

int n , a[maxN] , BIT[maxN] ;

void update(int i , int x) {
    for ( ; i > 0 ; i -= i & -i) BIT[i] += x ;
}

int get(int i) {
    int res = 0 ;
    for ( ; i <= n ; i += i & -i) res += BIT[i] ;
    return res ;
}

int BIT_1[maxN] ;

void update_1(int i , int x) {
    for ( ; i <= n ; i += i & -i) BIT_1[i] += x ;
}

int get_1(int i) {
    int res  = 0 ;
    for ( ; i > 0 ; i -= i & -i) res += BIT_1[i] ;
    return res ;
}

bool is_record[maxN] , dd[maxN] ;

void process () {
    forinc(i,1,n) {
        int cnt = get(a[i]) ;
        if (cnt == 0) is_record[i] = true ; else if (cnt == 1) dd[i] = true ;
        update(a[i],1) ;
    }

    int res = -ooit , ans = 0 ;
    fordec(i,n,1) {
        int cnt = get_1(a[i]) ;
        if (maximize(res,cnt - (int) is_record[i])) ans = a[i] ;
        else if (res == cnt - (int) is_record[i]) minimize(ans,a[i]) ;
        update_1(a[i],(int)dd[i]) ;
    }

    cout << ans << endl ;
}

int main () {
    freopen("900C.inp" , "r" , stdin) ;

    cin >> n ;

    forinc(i,1,n) cin >> a[i] ;

    process () ;

    return 0 ;
}

