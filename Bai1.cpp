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

using namespace std ;

int main()
{
    int j = 0 ;
    double n = 1000, m = 10 ;
    while (n > 0) {
        n -= m ; m += (double) 0.1 * m ; j ++ ;
    }
    cout << j << endl ;
    return 0 ;
}
