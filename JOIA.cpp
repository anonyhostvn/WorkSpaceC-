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
#define maxN 1005

using namespace std ;

int n , m , a[maxN][maxN] , b[2][2];

void enter() {
    cin >> n >> m ;
    forinc(i,1,n) forinc(j,1,m) {
        char ch ; cin >> ch ;
        if (ch == 'J') a[i][j] = 2 ; else if (ch == 'I') a[i][j] = 1 ;
    }
    forinc(i,0,1) forinc(j,0,1) {
        char ch ; cin >> ch ;
        if (ch == 'J') b[i][j] = 2 ; else if (ch == 'I') b[i][j] = 1 ;
    }
}

int check(int u , int v) {
    if (u <= 0 || v <= 0 || u > n || v > m) return 0 ;
    forinc(i,0,1) forinc(j,0,1) if (u + i > n || v + j > m || a[u + i][v + j] != b[i][j]) return 0 ;
    return 1 ;
}

void process() {
    int res = 0 , ans = 0  ;
    forinc(i,1,n-1) forinc(j,1,m-1) res += check(i,j) ; ans = res ;
    forinc(i,1,n) forinc(j,1,m) {
        int tmp = a[i][j] , temp = res - (check(i-1,j-1) + check(i-1,j) + check(i,j-1) + check(i,j)) ;
        forinc(k,0,2) if (k != tmp) {
            a[i][j] = k ;
            ans = max(ans,temp + check(i-1,j-1) + check(i-1,j) + check(i,j-1) + check(i,j)) ;
        }
        a[i][j] = tmp ;
    }
    cout << ans << endl ;
}

int main() {
        //freopen("JOIA.inp" , "r" , stdin) ;
    enter() ;
    process()  ;
    return 0 ;
}
