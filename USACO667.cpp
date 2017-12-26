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
string b[200001] , c[200001] ;
map<string,int> f ;

int enter()
{
    cin >> n ;
    forinc(i,1,n) {
        string sta , stb ; cin >> sta >> stb ;
        b[i] = b[i] + sta[0] + sta[1] + stb ;
        c[i] = c[i] + stb + sta[0] + sta[1] ;
    }
    return 0 ;
}

int process()
{
    forinc(i,1,n) f[c[i]] = 0 ;
    long long res = 0 ;
    forinc(i,1,n) {
        if (b[i][0] == b[i][2] && b[i][1] == b[i][3]) continue ;
        res += f[b[i]] ;
        f[c[i]] ++ ;
    }
    cout << res ;
    return 0 ;
}

int main()
{
    freopen("citystate.in" , "r" , stdin) ;
    freopen("citystate.out" , "w" , stdout) ;
    enter() ;
    process() ;
    return 0 ;
}
