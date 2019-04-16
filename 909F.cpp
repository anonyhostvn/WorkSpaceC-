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

void enter () {
    cin >> n ; m = n ;
}

#define maxN 100005

int power[maxN] ;

void prepare () {
    for (int i = 0 ; (1 << i) <= 200000 ; i ++ ) power[i] = (1 << i) ;
}

void subtask1 (int n) {
    if (n & 1) {cout << "NO" << endl ; return ; }
    int ans[maxN] ; memset(ans , 0 , sizeof(ans)) ;

    while (n) {
        int k = log2(n) , minid = ooit ;
        for (int i = 1 , p1 = power[k] + i - 1 , p2 = power[k] - i; p1 <= n && p2 >= 1 ; i ++ , p1 = power[k] + i - 1 , p2 = power[k] - i)
                ans[p1] = p2 , ans[p2] = p1 , minid = p2 ;
        n = minid - 1 ;
    }

    cout << "YES" << endl ;
    forinc(i,1,m) cout << ans[i] << " " ; cout << endl ;
}

int ans_6[6] = {3 , 6  , 2 , 5 , 1 , 4} , ans_7[7] = {7 , 3 , 6 , 5 , 1 , 2 , 4} , ans[maxN] ;

void Cyclic_permu (int s , int f) {
    int  i = s , j = f;
    while (i < j) {
        if (i < j) ans[i] = j , j -- ;
        if (i < j) ans[j] = i , i ++ ;
    }
    if (i == j) ans[f] = i ;

    forinc(i,s,f) cout << ans[i] << " " ;
}

void subtask2(int n) {
    if (n <= 5 || (long double) log2(n) == (int) log2(n) ) {cout << "NO" << endl ; return ; }
    cout << "YES" << endl ;
    if (n == 6) {
        forinc(i,0,5) cout << ans_6[i] << " " ;cout << endl ;
        return ;
    }

    forinc(i,0,6) cout << ans_7[i] << " " ;
    for (int i = 3 ; (1 << i) <= n ; i ++ ) {
        int Tlast = min((1 << (i + 1)) , n+1) - 1 ;
        Cyclic_permu((1 << i) , Tlast) ;
    }

    cout << endl ;
}

void process () {
    prepare () ;
    //forinc(i,1,10) cout << power[i] << " " ; cout << endl ;
    subtask1 (n) ;
    subtask2 (n) ;
}

int main () {
    //freopen("909F.inp" , "r" , stdin) ;
    //freopen("909F.out" , "w" , stdout) ;
    enter () ;
    process () ;
    return 0 ;
}
