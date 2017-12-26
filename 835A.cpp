#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)
#define forv(j,u) for (int j = 0 ; j < u.size() ; j++)
#define pb push_back
#define pf push_front
#define fi first
#define se second

using namespace std ;

long long s , v1 , v2 , t1 , t2 ;

int enter()
{
    cin >> s >> v1 >> v2 >> t1 >> t2 ;
    if (s * v1 + 2 * t1 < s * v2 + 2 * t2) cout << "First" ;
    else if (s * v1 + 2 * t1 > s * v2 + 2 * t2) cout << "Second" ;
    else cout << "Friendship" ;
}

int main()
{
    //freopen("835A.inp" , "r" , stdin) ;
    enter() ;
}
