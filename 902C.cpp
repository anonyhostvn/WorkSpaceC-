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

#define maxH 100005

int h , a[maxH] ;

void enter () {
    cin >> h ;
    forinc(i,0,h) cin >> a[i] ;
}

bool pre_check() {
    forinc(i,0,h-1) if (a[i] > 1 && a[i+1] > 1) return true ;
    return false ;
}

#define maxN 200005

int n = 0 ;
int par[maxN] ;

void build_tree_1() {
    queue<pii> q ; q.push({1,0}) ;
    int cnt = 1 ;

    while (!q.empty()) {
        auto tmp = q.front() ; q.pop() ;
        int u = tmp.fi , d = tmp.se ;
        forinc(i,1,a[d+1]) {
            par[++cnt] = u ;
            if (i == 1) q.push({cnt , d+1}) ;
        }
    }
}

int par_1[maxN] , cnt_push[maxH] , cnt_pop[maxH] ;

void build_tree() {
    queue<pii> q ; q.push({1,0}) ;
    forinc(i,0,h) cnt_push[i] = a[i] , cnt_pop[i] = a[i] ;
    int cnt = 1 ; cnt_push[0] -- ;
    while (!q.empty()) {
        auto tmp = q.front() ; q.pop() ;
        int u = tmp.fi , d = tmp.se ; cnt_pop[d] -- ;

        if (cnt_pop[d] > 0 && cnt_push[d+1] > 0) par_1[++cnt] = u , q.push({cnt,d+1}) , cnt_push[d+1] -- ;
        else {
            forinc(i,1,cnt_push[d+1]) par_1[++cnt] = u , q.push({cnt,d+1}) ;
            cnt_push[d+1] = 0 ;
        }
    }
}

void process () {
    if (!pre_check()) {
        cout << "perfect" << endl ;
        return ;
    }

    build_tree_1() ;
    build_tree() ;
    forinc(i,0,h) n += a[i] ;

    cout << "ambiguous" << endl ;
    forinc(i,1,n) cout << par[i] << " " ; cout << endl ;
    forinc(i,1,n) cout << par_1[i] << " " ; cout << endl ;
}

int main () {
    //freopen("902C.inp" , "r" , stdin) ;
    enter () ;
    process () ;
    return 0 ;
}
