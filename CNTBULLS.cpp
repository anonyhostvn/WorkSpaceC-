#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)
#define forv(j,u) for (int j = 0 ; j < u.size() ; j++)
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define base 2111992

using namespace std ;

int n , k ;
int f[100001] ;

int enter()
{
    cin >> n >> k ;
    f[0] = 1 ;
    forinc(i,0,n-1){
        f[min(n,i+k+1)] = (f[min(n,i+k+1)] + f[i]) % base ;
        f[i+1] = (f[i+1] + f[i]) % base ;
    }
    cout << f[n] ;
}

int main()
{
    enter() ;
}
