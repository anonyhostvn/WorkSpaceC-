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
int a[maxN] ;

int main() {
    //freopen("892A.inp" , "r" , stdin) ;
    cin >> n ;
    long long sum = 0 ;
    forinc(i,1,n) {
        int x ; cin >> x ;
        sum += x ;
    }
    forinc(i,1,n) cin >> a[i] ;
    sort(a+1,a+1+n) ;
    if (sum <= a[n] + a[n-1]) cout << "YES" ; else cout << "NO" ;
}
