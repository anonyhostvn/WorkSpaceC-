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
#define maxN 100005

using namespace std ;

int n , k , a[maxN] ;
bool win[3][3] ;

void enter() {
    cin >> n >> k ;
    forinc(i,1,n) {
        char ch ; cin >> ch ;
        if (ch == 'H') a[i] = 0 ; else if (ch == 'P') a[i] = 1 ; else a[i] = 2 ;
    }
    win[0][2] = true ; win[2][1]= true ; win[1][0] = true ;
}

int f[maxN][25][3] ;

void maximize(int &a , int b) { a = max(a,b) ; }

void process() {
    forinc(i,0,n) forinc(j,0,k) forinc(t,0,2) f[i][j][t] = -1 ;
    forinc(i,0,2) f[1][0][i] = (int) (win[i][a[1]]) ;
    forinc(i,1,n) forinc(j,0,k) forinc(t,0,2) if (f[i][j][t] > -1) {
        forinc(s,0,2) maximize(f[i+1][j + (int) (s != t)][s],f[i][j][t] + (int) (win[s][a[i+1]])) ;
    }
    int res =0  ;
    forinc(i,0,k) forinc(j,0,2) res = max(res,f[n][i][j]) ;
    cout << res << endl ;
}

int main () {
    freopen("hps.in" , "r" , stdin) ;
    freopen("hps.out" , "w" , stdout);
    enter() ;
    process()  ;
    return 0 ;
}
