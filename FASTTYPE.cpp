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

#define maxQ 200005

int n , k , m ;
string s ;
struct node {
    int a , b , c ;
} q[maxQ] ;

void enter () {
    cin >> k >> m ;
    cin >> s ;
    cin >> n ;
    forinc(i,1,n) scanf("%d%d%d" , &q[i].a , &q[i].b , &q[i].c) ;
    //forinc(i,1,n) cout << q[i].a << " " << q[i].b << " " << q[i].c << endl ;
}

int solve(int id) {
    fordec(i,n,1)
        if (q[i].c < id && id <= q[i].c + q[i].b - q[i].a) id = q[i].a + id - q[i].c ;
        else if (id > q[i].c + q[i].b - q[i].a) id -= q[i].b - q[i].a ;
    return id ;
}

void process () {
    forinc(i,1,k) cout << s[solve(i)-1] ;
}

int main () {
    freopen("FASTTYPE.inp" , "r" , stdin) ;
    freopen("FASTTYPE.out" , "w" , stdout) ;
    enter ()  ;
    process () ;
    return 0 ;
}
