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
#define maxN 105

template <class _T> bool maximize(_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize(_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

using namespace std ;

struct node {
    int R , Rmin , Rmax , STime  ;
    int isRated , Color ;
};

int n ;
node a[maxN] ;
bool dd[maxN] ;

bool check(int j , int i) {
    if (a[i].R > a[j].Rmax || a[i].R < a[j].Rmin) return false ;
    if (a[j].R > a[i].Rmax || a[j].R < a[i].Rmin) return false ;
    if (a[i].isRated != a[j].isRated) return false ;
    if (a[i].STime != a[j].STime) return false;
    if (a[i].Color == 2 && a[j].Color == 2) return true ;
    if (a[i].Color == 2 && a[j].Color != 2) return false ;
    if (a[j].Color == 2 && a[i].Color != 2) return false ;
    if (a[i].Color == a[j].Color) return false ;
    return true ;
}

void enter() {
    cin >> n  ;
    forinc(i,1,n) dd[i] = false ;
    string st1 , st2 ;
    forinc(i,1,n) {
        cin >> a[i].R >> a[i].Rmin >> a[i].Rmax >> a[i].STime >>  st2 >> st1 ; //cout << st1 << " " << st2 << endl ;
        if (st2 == "rated") a[i].isRated = 1 ; else a[i].isRated = 0 ;
        if (st1 == "white") a[i].Color = 1 ; else if (st1 == "random") a[i].Color = 2 ; else a[i].Color = 0 ;
        bool found = false ; int res = 0 ;
        forinc(j,1,i-1) if (!dd[j] && check(j,i)) {
            found = true ;  dd[j] = true ; dd[i] = true ; res = j ;
            break ;
        }
        if (found) cout << res << endl ; else cout << "wait" << endl ;
    }
}

int main () {
    //freopen("Test.inp" , "r" , stdin) ;
    int t= 0 ; cin >>t ;
    while (t--) enter() ;
    return 0 ;
}
