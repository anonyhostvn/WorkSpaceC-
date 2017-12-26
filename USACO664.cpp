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

int n , cnt[101][2][26] ;
string st ;

int enter()
{
    cin >> n ;
    forinc(i,1,n) {
        cin >> st ; int l = st.length() ;
        forinc(j,0,l-1) cnt[i][0][(int)st[j]-(int)'a'] ++ ;
        cin >> st ; l = st.length() ;
        forinc(j,0,l-1) cnt[i][1][(int)st[j]-(int)'a'] ++ ;
    }
    forinc(i,0,25){
        int res = 0;
        forinc(j,1,n) res += max(cnt[j][0][i],cnt[j][1][i]) ;
        cout << res << endl ;
    }
    return 0 ;
}

int main()
{
    freopen("blocks.in" , "r" , stdin) ;
    freopen("blocks.out" , "w" , stdout) ;
    enter() ;
    return 0 ;
}
