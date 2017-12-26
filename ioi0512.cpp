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

using namespace std ;

int n ;

int main() {
    freopen("ioi0512.inp" , "r" , stdin) ;
    scanf("%d" , &n) ;
    int last = 0 , x = 0 , res = 0 ;
    scanf("%d" , &last) ; scanf("%d" , &x) ; res = x - last + 1 ; last = x ;
    forinc(i,3,n) {
        scanf("%d" , &x) ;
        if (last + res - 1 > x) res = x - last + 1 ; last = x ;
    }
    cout << res + 1 ;
}
