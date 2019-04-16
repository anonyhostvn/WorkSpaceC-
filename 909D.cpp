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

#define pci pair<char,int>

int n ;
vector<pci> a ;

void enter () {
    string st ; cin >> st ;
    int n = st.length () ;

    forinc(i,1,n) if (a.empty() || a.back().fi != st[i-1]) a.push_back({st[i-1] , 1}) ;
    else if (a.back().fi == st[i-1]) a.back().se ++ ;
}

void process () {
    //for (auto tmp : a) cout << tmp.fi << "  " << tmp.se << endl ;
    int res = 0 ;

    while (a.size() > 1) {
        forv(i,a) {
            if (i == 0 || i == a.size()-1) a[i].se -- ; else a[i].se -- , a[i].se -- ;
            maximize(a[i].se , 0) ;
        }

        vector<pci> b ; b.clear () ;

        for (auto tmp : a) if ((b.empty() || b.back().fi != tmp.fi) && tmp.se > 0) b.push_back({tmp.fi , tmp.se}) ;
            else if (!b.empty() && b.back().fi == tmp.fi) b.back().se += tmp.se ;
        swap(a,b) ; res ++ ;
    }

    cout << res << endl ;
}

int main () {
    //freopen("909D.inp" , "r" , stdin) ;
    enter () ;
    process () ;
    return 0 ;
}
