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

using namespace std ;

int n ;

int enter()
{
    cin >> n ;
    forinc(i,1,n) cout << i << " " ; cout << endl ;
    return 0 ;
}

int main()
{
    //freopen("LIKECS02.inp" , "r" , stdin) ;
    int t ; cin >> t ;
    forinc(i,1,t) enter() ;
}
