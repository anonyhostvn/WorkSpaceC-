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

int n , m , k ;

int enter()
{
    cin >> m >> n >> k ;
    forinc(i,1,m) {
        string st = "" ;
        forinc(i,1,n) {
            char ch ; cin >> ch ;
            forinc(i,1,k) st += ch ;
        }
        forinc(i,1,k) cout << st << endl ;
    }
    return 0 ;
}

int main()
{
    freopen("cowsignal.in" , "r" , stdin) ;
    freopen("cowsignal.out" , "w",  stdout) ;
    enter() ;
    return 0 ;
}
