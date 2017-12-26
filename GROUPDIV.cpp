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

template <class _T> bool maximize(_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize(_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

using namespace std ;

#define maxN 300005

int n ;
vector<int> a[maxN] ;

void enter () {
    cin >> n ;
    forinc(i,1,n) {
        int cnt = 0 ; cin >> cnt ;
        forinc(j,1,cnt) {int x = 0 ; cin >> x ; a[i].push_back(x) ; }
    }
}

bool group [maxN] ;

void process () {
    forinc(i,1,n) {
        int cnt = 0 ;
        for (auto tmp : a[i]) cnt += (int) (group[i] == group[tmp]) ;
        if (cnt > 1) group[i] = !group[i] ;
    }

    while (true) {
        int LatDot = 0 ;
        forinc(i,1,n) {
            int cnt = 0 ;
            for (auto tmp : a[i]) cnt += (int) (group[i] == group[tmp]) ;
            if (cnt > 1) LatDot ++ , group[i] = !group[i] ;
        }
        if (LatDot == 0) break ;
    }

    cout << "YES" << endl ;
    forinc(i,1,n) if (group[i]) cout << i << " " ; cout << endl ;
    forinc(i,1,n) if (!group[i]) cout << i << " " ; cout << endl ;
}

int main () {
    freopen("GROUPDIV.inp" , "r" , stdin) ;
    freopen("GROUPDIV.out" , "w" , stdout) ;
    enter () ;
    process() ;
}
