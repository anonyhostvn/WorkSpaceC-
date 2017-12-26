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
#define oo (int) 1e9 + 7
#define maxN 100005

using namespace std ;

int n , d , a[maxN] , amin = oo ;

int main()
{
    cin >> n >> d ;
    forinc(i,1,n) cin >> a[i] , amin = min(amin,a[i]) ;
    bool ok = true ; long long res = 0 ;
    forinc(i,1,n) ok &= ((a[i] - amin) % d == 0) , res += (a[i] - amin) / d ;
    cout << (ok ? res : -1) << endl ;
    return 0 ;
}
