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

void enter()
{
    int n =  0 ;
    vector<int> ans[2] ;
    cin >> n ;
    forinc(i,1,n) if (i % 2 == 1) ans[0].push_back(i) ;
    forinc(i,1,n) if (i % 2 == 0) ans[0].push_back(i) ;
    forinc(i,1,n) if (i % 2 == 1) ans[0].push_back(i) ;
    forinc(i,1,n) if (i % 2 == 0) ans[1].push_back(i) ;
    forinc(i,1,n) if (i % 2 == 1) ans[1].push_back(i) ;
    forinc(i,1,n) if (i % 2 == 0) ans[1].push_back(i) ;
    if (ans[0].size() < ans[1].size()) {
        cout << ans[0].size() << endl ;
        forv(i,ans[0]) cout << ans[0][i] << " " ;
    } else {
        cout << ans[1].size() << endl ;
        forv(i,ans[1]) cout << ans[1][i] << " " ;
    }
}

int main()
{
    enter() ;
    return 0 ;
}
