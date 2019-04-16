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

int fastRead() {
    char c ; int res = 0 ;
    for (c = getchar() ; c < '0' || c > '9' ; c = getchar()) ;
    for ( ; c >= '0' && c <= '9' ; c = getchar()) res*= 10 , res += c - '0' ;
    return res ;
}

#define maxN 100005

int n , m , bounty , inc , dam ;

struct info {
    int max_health , start_health ,regen;
} enemy[maxN] ;

vector<pii> health[maxN] ;

void enter () {
    n = fastRead() ; m = fastRead() ; bounty = fastRead() ; inc = fastRead() ; dam = fastRead() ;

    forinc(i,1,n)
        enemy[i].max_health = fastRead() , enemy[i].start_health = fastRead() , enemy[i].regen = fastRead() , health[i].push_back({0,enemy[i].start_health});
    forinc(i,1,m) {
        int t = fastRead() , id = fastRead() , h = fastRead() ;
        health[id].push_back({t,h});
    }
}

void prepare () {
    forinc(i,1,n) if (health[i].size() > 0) sort(health[i].begin() , health[i].end()) ;
}
/*
long long up_health(int id , int _time) {
    if (health[id].size() == 0) return 0 ;
    int l = 0 , r = f[id].size() - 1 , res = -1 ;
    while (l <= r) {
        int mid = (l+r) / 2 ;
        if (f[id][mid].se <= mid) res = mid , l = mid + 1 ; else r = mid - 1 ;
    }

    if (res > -1) return f[id][res].fi ;
    return 0 ;
}


long long health_enemy (int id , int _time) {
    pii tmp = up_health(id , _time);
    long long res = enemy[id].start_health + up_health(id, _time) + (long long) enemy[id].regen * _time ;
    return res ;
}
*/
int kill_enemy (int id) {
    if (dam >= enemy[id].max_health) return ooit ;

    int res = -1 ;
    if (health[id].size() >= 2) forinc(i,0,health[id].size() - 2) if (dam >= health[id][i].se) {
        int tmp = min(health[id][i+1].fi - 1 , (int) (dam - health[id][i].se) / enemy[id].regen ) ;
        maximize(res , tmp + health[id][i].fi) ;
    }

    if (health[id].back().se <= dam) {
        int tmp = (dam - health[id].back().se) / enemy[id].regen ;
        maximize(res , tmp + health[id].back().fi) ;
    }

    return res ;
}

int later[maxN] ;

void process () {
    prepare () ;

    forinc(i,1,n) later[i] = kill_enemy(i) ;
    sort(later + 1 , later + 1 + n) ;
    forinc(i,1,n) cout << later[i] << endl ;

    if (later[n] == ooit  && inc > 0) cout << -1 << endl ;
    else {
        long long gold = 0 ;
        fordec(i,n,1) if (later[i] >= 0) maximize(gold , (long long) (n-i+1)  * ((long long) bounty + (long long) later[i] * inc) );
        cout << gold << endl ;
    }
}

int main () {
    freopen("912C.inp" , "r" , stdin) ;

    enter () ;
    process () ;
    return 0 ;
}
