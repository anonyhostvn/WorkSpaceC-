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
#define base (int) 1e9 + 7
#define maxN 300005

using namespace std ;

int n , k , a[maxN] , f[maxN] , g[maxN] ;

void enter()
{
    cin >> n >> k ;
    forinc(i,1,n) cin >> a[i] ;
}

deque<int> q[2] ;

void add_que(int x)
{
    while (!q[0].empty() && a[x] <= a[q[0].back()]) q[0].pop_back() ;
    while (!q[1].empty() && a[x] >= a[q[1].back()]) q[1].pop_back() ;
    q[0].push_back(x) ;
    q[1].push_back(x) ;
}

void remove_que(int x)
{
    if (!q[0].empty() && q[0].front() == x) q[0].pop_front() ;
    if (!q[1].empty() && q[1].front() == x) q[1].pop_front() ;
}

void prepare()
{
    int j = 1 ;
    forinc(i,1,n) {
        add_que(i) ;
        while (j <= i && abs(a[q[1].front()] - a[q[0].front()]) > k) remove_que(j++) ;
        f[i] = j ;
    }
}

void process()
{
    prepare() ;
    forinc(i,1,n) g[i] = max(g[i-1],i-f[i] + 1) ;
    int res = g[n] ;
    forinc(i,1,n) if (f[i] > 1 && f[i] <= i) res = max(res,i-f[i] + 1 + g[f[i]-1]) ;
    cout << res << endl ;
}

int main()
{
    //freopen("kdiff.inp" , "r" , stdin)  ;
    enter()  ;
    process() ;
    return 0 ;
}
