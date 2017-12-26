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
#define maxN 100005
#define maxK 105

template <class _T> bool maximize(_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize(_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

using namespace std ;

int n , k , cnt[maxN] ;
long long sum [maxN] ;

void enter ()  {
    scanf("%d%d" , &n , &k) ;
    forinc(i,1,n) {
        long long x ;
        scanf("%lld" , &x) ; sum[i] = sum[i-1] + x ;
        cnt[i] = cnt[i-1] + (int) (x < 0) ;
    }
}

typedef pair <long long , int > pli ;

deque<pli> q ;

void add(int i) {
    while (!q.empty() && sum[i] >= q.back().fi) q.pop_back() ;
    q.push_back({sum[i] , i}) ;
}

void remove_(int i) { if (q.front().se == i) q.pop_front() ; }

void process () {
    int j = 0 ;
    long long res = -ooll ;
    forinc(i,1,n) {
        while (j + 1 <= n && cnt[j+1] - cnt[i-1] <= k) add(++j) ;
        maximize(res,q.front().fi - sum[i-1]) ;
        remove_(i) ;
    }
    printf("%lld" , res) ;
}

int main () {
    freopen("checkpoint.inp" , "r" , stdin) ;
    freopen("checkpoint.out" , "w" , stdout) ;
    enter ()  ;
    process ()  ;
    return 0 ;
}
