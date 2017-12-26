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
#define maxN 1000005

template <class _T> bool maximize(_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize(_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

using namespace std ;

int m , n , k , a[maxN] , suma = 0 ;

int fastRead() {
    int res = 0 ; char c ;
    for (c = getchar() ; c < '0' || c > '9' ; c = getchar()) ;
    for ( ; c >= '0' && c <= '9' ; c = getchar()) res *= 10  , res += (int) c - (int) '0'  ;
    return res ;
}

int get_val_a(int i , int j) {return a[(i-1) * n + j] ; }

void enter () {
    m = fastRead() ; n = fastRead() ; k = fastRead() ;
    forinc(i,1,m) forinc(j,1,n) a[(i-1) * n + j] =  fastRead() ;
}

int b[maxN] ; long long max_ = 0 ;
int get_id (int i , int j) {return (i-1) * m + j ; }

void prepare () {
    forinc(i,1,n) forinc(j,1,m) b[(i-1) * m + j] = get_val_a(j,i) ;
    forinc(i,1,n) sort(b + (i-1) * m + 1 , b + (i-1) * m + 1 + m , [] (int a , int b) {
        return a > b ;
    } ) ;
    forinc(i,1,n) max_ += b[get_id(i,1)] ;
    forinc(i,1,n) forinc(j,2,m) b[get_id(i,j)] -= b[get_id(i,1)] ;
    forinc(i,1,n) b[get_id(i,1)] = 0 ;
}

bool Count(int x ) {
    typedef multiset<int> :: iterator iter ;
    multiset<int> Tset ;  vector<int> Tadd ; Tset.insert(x) ;

    forinc(i,1,n) {
        Tadd.clear() ;
        forinc(j,2,m) {
            iter Lim = Tset.upper_bound(b[get_id(i,j)]) ;
            for (iter it = Tset.begin() ; it != Lim ; it ++) {
                Tadd.push_back(*it - b[get_id(i,j)]) ;
                if (Tadd.size() + Tset.size() >= k) return true ;
            }
        }
        for (auto tmp : Tadd) Tset.insert(tmp) ;
        if (Tset.size() >= k) return true ;
    }
    if (Tset.size() >= k) return true ;
    return false ;
}

int find_Thresh_Old(){
    int l = 0 , r = 0 , res = 1 , q = 0 ; long long tmp = 0 ;
    forinc(i,1,n) l += b[get_id(i,m)] ;

    while (l <= r) {
        int mid = (l+r) / 2 ;
        if (Count(mid)) l = mid + 1 , res = mid ; else r = mid - 1 ;
    }

    return res ;
}

long long find_sum(int x , int& q) {
    if (x > 0) return 0 ;
    q = 0 ; typedef multiset<int> :: iterator iter ;
    multiset<int> Tset ; vector<int> Tadd ; Tset.insert(x) ;
    forinc(i,1,n) {
        Tadd.clear() ;
        forinc(j,2,m) {
            iter Lim = Tset.upper_bound(b[get_id(i,j)]) ;
            for (iter it = Tset.begin() ; it != Lim ; it ++) Tadd.push_back(*it - b[get_id(i,j)]) ;
        }
        for (auto tmp : Tadd) Tset.insert(tmp) ;
    }
    long long res = 0 ;
    for (auto tmp : Tset) res += x - tmp ; q = Tset.size() ;
    return res ;
}

void process (){
    prepare () ;
    int threshOld = find_Thresh_Old() , q = 0 ;
    long long res = find_sum(threshOld+ 1 , q) ;
    res += (long long) (k-q) * threshOld ;
    res += (long long) k * max_ ;

    cout << res << endl ;
}

int main () {
    freopen("LANDSEL.inp" , "r" , stdin) ;
    freopen("LANDSEL.out" , "w" , stdout) ;
    enter () ;
    process () ;
    return 0 ;
}
