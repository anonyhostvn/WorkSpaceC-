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

void enter()
{
    cin >> n ;
    int sum = 0 ; bool ok = false ;
    forinc(i,1,n) {
        int x = 0 ; cin >> x ;
        if (x != 1) ok =  true ;
        sum ^= x ;
    }
    if (!ok) { if (n % 2 == 0) cout << "John" ; else cout << "Brother" ; }
    else {if (sum == 0) cout << "Brother" ; else cout << "John" ;} cout << endl ;
}

int main()
{
    //freopen("nk05mnim.inp" , "r" , stdin) ;
    int t=  0 ; cin >> t ;
    while (t--) enter() ;
    return 0 ;
}
