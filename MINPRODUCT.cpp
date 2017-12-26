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

int n ;
long long a[maxN]  ;

void enter() {
    scanf("%d" , &n) ;
    forinc(i,1,n) scanf("%lld" , &a[i]) ;
    sort(a+1,a+1+n) ;
    printf("%lld" , min(a[1] * a[2],min(a[1] * a[n], a[n-1] * a[n]))) ;
}

int main() {
    freopen("MINPRODUCT.inp" , "r" , stdin) ;
    freopen("MINPRODUCT.out" , "w", stdout) ;
    enter() ;
    return 0 ;
}
