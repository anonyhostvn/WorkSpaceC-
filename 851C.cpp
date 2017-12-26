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
#define maxN 20

using namespace std ;

int a[maxN][5] ;
int n ;

bool check(int point1 , int point2 , int point3)
{
    int v1[5] , v2[5] ;
    forinc(i,0,4) v1[i] = a[point2][i] - a[point1][i] , v2[i] = a[point3][i] - a[point1][i] ;
    int sum = 0 ;
    forinc(i,0,4) sum += v1[i] * v2[i] ;
    return sum > 0 ;
}

void enter()
{
    cin >> n ;
    if (n > 11) {cout << 0 ; return ;}
    forinc(i,1,n) forinc(j,0,4) cin >> a[i][j] ;
    vector<int> ans ;
    forinc(i,1,n){
        bool ok = true ;
        forinc(j,1,n) if (!ok) break ;
        else forinc(k,1,n) if (i != j && j != k && k != i && check(i,j,k)) {ok = false ; break ;}
        if (ok) ans.push_back(i) ;
    }
    cout << ans.size() << endl ;
    forv(i,ans) cout << ans[i] << endl ;
}

int main()
{
    //freopen("851C.inp" , "r" , stdin) ;
    enter() ;
    return 0 ;
}
