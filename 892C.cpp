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
#define maxN 2005

using namespace std ;

int n , a[maxN] ;

int gcd(int a , int b) {
    while (b > 0) {
        int tmp = a % b ;
        a = b ; b = tmp ;
    }
    return a ;
}

void enter() {
    cin >> n ;
    forinc(i,1,n) cin >> a[i] ;
}

void process() {
    int min_length = ooit , L = 0 , R = 0  , cnt = 0 ;
    forinc(i,1,n) if (a[i] == 1) cnt ++ ;
    if (cnt > 0) {
        cout << n - cnt << endl ;
        return ;
    }
    forinc(i,1,n) {
        int igcd = a[i] ;
        if (igcd == 1) { min_length = 1 ; break ; }
        forinc(j,i+1,n) {
            igcd  = gcd(igcd,a[j]) ;
            if (igcd == 1) {
                min_length = min(min_length,j - i + 1) ;
                break ;
            }
        }
    }
    if (min_length == ooit) { cout << -1 ; return ; }
    cout << min_length - 1 + (n-1) ;
}

int main() {
    //freopen("892C.inp" , "r" , stdin) ;
    enter() ;
    process() ;
    return 0 ;
}
