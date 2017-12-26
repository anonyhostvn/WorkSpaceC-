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
#define maxN 101

using namespace std ;

string st ;
int n , a[maxN] ;
bool dd[301] ;

int enter()
{
    memset(dd,false,sizeof(dd)) ;
    cin >> st ;
    n = st.length() ;
    forinc(i,1,n) if (dd[(int) st[i-1]]) {
        cout << "yes" << endl ;
        return 0 ;
    } else dd[(int) st[i-1]] = true ;
    cout << "no" << endl ;
    return 0 ;
}

int main()
{
    //freopen("LIKECS01.inp" , "r" , stdin) ;
    int t = 0 ; cin >> t ;
    while (t--) enter() ;
    return 0 ;
}
