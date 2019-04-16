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
#define pli pair<long long , int>

template <class _T> bool maximize(_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize(_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

const int ooit = 2e9 ;
const long long ooll = 1e15 ;

using namespace std ;

#define maxN 200005

int n , k ;
vector<int> p ;
set<int> Tset ;

void enter () {
    cin >> n >> k ;
    forinc(i,1,n) Tset.insert(i) ;
    forinc(i,1,k) {
        int x ; cin >> x ; p.push_back(x) ;
        Tset.erase(x) ;
    }
}

stack<int> st ;
vector<int> b ;

bool prepare () {
    b.push_back(0) ; st.push(ooit) ;
    for (auto tmp : p) {
        if (!st.empty() && st.top() < tmp) return false ;
        st.push(tmp) ;
        while (!st.empty() && b.back() + 1 == st.top()) b.push_back(st.top()) , st.pop() ;
    }

    return true ;
}

void process () {
    if (!prepare () ) {
        cout << -1 << endl ;
        return ;
    }

    while (!Tset.empty()) {
        int x = st.top() ; auto it = Tset.lower_bound(x) ; vector<int> L ;
        for (auto i = Tset.begin() ; i != it; i ++) L.push_back(*i) ;
        while (!L.empty()) p.push_back(L.back()) , st.push(L.back()) , L.pop_back() ;
        //for (auto tmp : p) cout << tmp << " " ;
        while (!Tset.empty() && (*Tset.begin()) < x) Tset.erase(Tset.begin()) ;
        while (!st.empty() && st.top() == b.back() + 1) b.push_back(st.top()) , st.pop() ;
    }

    for (auto tmp : p) cout << tmp << " " ; cout << endl ;
}

int main () {
    //freopen("911E.inp" , "r" , stdin) ;
    enter () ;
    process () ;
    return 0 ;
}
