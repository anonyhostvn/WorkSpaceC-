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
#define maxN 1000000

using namespace std ;

string st ;
char x , y ;
long long f[maxN] ;

int enter()
{
    ios_base::sync_with_stdio(false) ;
    cin >> st ;
    cin >> x >> y ;
    int cnt = 0  , n = st.length();
    long long res = 0 ;
    forinc(i,0,n-1){
        if (st[i] == y) res += cnt ;
        if (st[i] == x) ++cnt ;
    }
    cout << res ;
    return 0 ;
}

int main()
{
    //freopen("VMRR.inp" , "r" , stdin) ;
    enter() ;
    return 0 ;
}
