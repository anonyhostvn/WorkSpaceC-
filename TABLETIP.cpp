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

int n , m , a[5001][5001] , t[5001][5001] ;

int enter()
{
    cin >> n ;
    forinc(i,1,n)
    forinc(j,1,n) cin >> a[i][j] ;
    return 0 ;
}

int update(int idx , int idy)
{
    for (int i = idx ; i <= n ; i += i & -i)
    for (int j = idy ; j <= n ; j += j & -j) {
        t[i][j] ++ ; t[i][j] %= 2 ;
    }
    return 0 ;
}

int get(int idx , int idy)
{
    int res = 0 ;
    for (int i = idx ; i > 0 ; i -= i & -i)
    for (int j = idy ; j > 0 ; j -= j & -j) {
        res += t[i][j] ;
    }
    return  res % 2 ;
}

int process()
{
    return 0 ;
}

int main()
{

}
