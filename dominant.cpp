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
#define oo 1000000000

using namespace std;

int n , a[300001] , b[300001] , t[600005];
long long g[600005];
string st ;

int enter()
{
    cin >> st ; n = st.length() ;
    forinc(i,1,n) a[i] = a[i-1] + (int) st[i-1] - (int) '0' ;
    return 0 ;
}

int prepare()
{
    //forinc(i,1,n) cout << a[i] << endl ;
    forinc(i,0,n) b[i] = i - 2 * a[i] + n + 1 ;
    return 0 ;
}

int update(int id , int x)
{
    for (int i = id ; i > 0 ; i -= i & -i) t[i] = min(t[i],x) ;
    return 0 ;
}

int get(int id)
{
    int res = oo ;
    for (int i = id ; i <= 2 * n + 1 ; i += i & -i) res = min(res,t[i]) ;
    return res ;
}

int process()
{
    int res1 = 0 ;
    long long res2 = 0 ;
    prepare() ;
    forinc(i,1,2*n) t[i] = oo ;
    //forinc(i,1,n) cout << b[i] << endl  ;
    forinc(i,0,n) {
        int tmp = get(b[i]+1) ;
        update(b[i],i) ;
        if (res1 < i-tmp) {
            res1 = i-tmp ;
            res2 = 1 ;
        }
        else if (res1 == i-tmp) res2 ++ ;
    }
    cout << res1 << " " << res2 ;
    return 0 ;
}

int main()
{
    freopen("dominant.inp" , "r" , stdin) ;
    freopen("dominant.out" , "w" , stdout) ;
    enter() ;
    process() ;
    return 0 ;
}
