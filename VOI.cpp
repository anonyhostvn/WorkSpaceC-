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

#define maxN 55

int n , a[maxN] , m ;
bool not_love[maxN][maxN] ;

void enter () {
    cin >> n ;

    forinc(i,1,n) {
        char c ; cin >> c;
        if (c == 'R') a[i] = 0 ; else if (c == 'G') a[i] = 1 ; else a[i] = 2 ;
    }

    cin >> m ;
    forinc(i,1,m) {
        int u , v ; cin >> u >> v;
        not_love[u][v] = true ; not_love[v][u] = true ;
    }
}

int get_bit(int x , int i) {
    return (x >> i) & 1 ;
}

int count_(int x) {
    int res = 0 ;
    forinc(i,1,n) res += get_bit(x,i-1) ;
    return res ;
}

bool solve(int x) {
    bool cc[3][3] ; memset(cc , false , sizeof(cc)) ;

    forinc(i,1,n) if (get_bit(x,i-1))
        forinc(j,1,n) if (i != j && get_bit(x,j-1) && not_love[i][j]) cc[a[i]][a[j]] = true , cc[a[j]][a[i]] = true  ;

    forinc(i,0,2){
        int cnt = 0 ; vector<int> tend ;
        forinc(j,0,2) if (i != j && cc[i][j])  cnt ++ , tend.push_back(j) ;
        if (cnt >= 2 && cc[tend[0]][tend[1]]) return false ;
    }

    return true ;
}

void sub1 () {
    int k = (1 << n) - 1 , res = ooit ;
    forinc(i,0,k) if (solve(i))
        minimize(res , n - count_(i)) ;
    cout << res << endl ;
}

int greedy(int room1 , int room2) {
    set<int> r1 , r2 ; vector<int> r3 ;
    forinc(i,1,n) if (a[i] == room1) r1.insert(i) ; else if (a[i] == room2) r2.insert(i) ; else r3.push_back(i) ;

    int cnt = 0 , res = ooit , knt = 0 ;
    for (auto tmp : r3) {
        vector<int> era ;
        for (auto id : r1) if (not_love[tmp][id]) era.push_back(id) ;
        cnt += era.size() ;
        for (auto id : era) r1.erase(id) ;
    }

    for (auto tmp : r3) {
        vector<int> era ;
        for (auto id : r2) if (not_love[tmp][id]) era.push_back(id) ;
        knt += era.size() ;
        for (auto id : era) r2.erase(id) ;
    }

    return min(cnt,knt) ;
}

void sub2() {
    int res = ooit ;

    forinc(i,0,1) forinc(j,i+1,2) minimize(res , greedy(i,j)) ;

    cout << res << endl ;
}

void process () {
    if (n <= 15) sub1() ; else sub2() ;
}

int main () {
    freopen("VOI.inp" , "r" , stdin) ;
    freopen("VOI.out" , "w" , stdout) ;
    enter () ;
    process () ;
    return 0 ;
}
