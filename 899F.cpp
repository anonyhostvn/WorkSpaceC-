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

#define maxN 200005

int n , q , a[maxN] ;

void enter () {
    cin >> n >> q ;
    forinc(i,1,n) {
        char c ; cin >> c ; a[i] = (int) c ;
    }
}

#define maxACSII 256

set<int> pos[maxACSII] ;

struct BIT{
    int val[maxN] ;

    void update(int i , int x, int n) {
        for ( ; i <= n ; i += i & -i) val[i] += x ;
    }

    int get(int i) {
        int res = 0 ;
        for ( ; i > 0 ; i -= i & -i) res += val[i] ;
        return res ;
    }
} tree ;

void prepare () {
    forinc(i,1,n) pos[a[i]].insert(i) , tree.update(i,1,n) ;
}

int tfind(int x) {
    int l = 1 , r = n , res = -1 ;
    while (l <= r) {
        int mid = (l+r) / 2 ;
        if (tree.get(mid) >= x) r = mid - 1 , res = mid ; else l = mid + 1 ;
    }
    return res ;
}

bool is_remove[maxN] ;

void update(int l , int r , int x) {
    auto it_down = pos[x].lower_bound(l) ;
    if (it_down == pos[x].end()) return ;
    auto it_up = pos[x].upper_bound(r) ;

    vector<int> must_remove ;
    for ( ; it_down != it_up ; it_down ++) must_remove.push_back(*it_down) ;

    for (auto i : must_remove) {
        pos[x].erase(i) ;
        tree.update(i,-1,n) ;
        is_remove[i] = true ;
    }
}

void process () {
    prepare () ;
    forinc(i,1,q) {
        int l , r , cx;
        char c ; cin >> l >> r >> c ; cx = (int) c ;
        int tl = tfind(l) , tr = tfind(r) ;
        update(tl , tr , cx) ;
    }

    forinc(i,1,n) if (!is_remove[i]) cout << (char) a[i] ; cout << endl ;
}

int main () {
    //freopen("899F.inp", "r" , stdin) ;
    enter () ;
    process () ;
    return 0 ;
}
