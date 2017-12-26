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

int n , k , m ;
vector<vector<int> >  a ;
vector<int> c ;

int enter()
{
    cin >> m >> n >> k ;
    m-- ; n-- ;
    forinc(i,0,m) {
        c.clear() ;
        forinc(i,0,n) {
            int x ; cin >> x ;
            c.push_back(x) ;
        }
        a.push_back(c) ;
    }
    return 0 ;
}

vector<vector<long long> > f ;
vector<long long> g ;
deque<int> st ;

int build(int id)
{
    g.clear() ; st.clear() ;
    forinc(i,0,n) {
        while (!st.empty() && f[id][i] > f[id][st.back()]) st.pop_back() ;
        if (!st.empty() && i - st.front() > 2 * k) st.pop_front() ;
        st.push_back(i) ;
        if (i >= k) g.push_back(a[id+1][i-k] + f[id][st.front()]) ;
    }
    forinc(i,n-k+1,n) {
        if (!st.empty() && i - st.front() > k) st.pop_front() ;
        g.push_back(a[id+1][i] + f[id][st.front()]) ;
    }
    f.push_back(g) ;
    return 0 ;
}

int process()
{
    forinc(i,0,n) g.push_back(a[0][i]) ;
    f.push_back(g) ;
    forinc(i,0,m-1) build(i) ;
    long long res = 0 ;
    forinc(i,0,n) res = max(res,f[m][i]) ;
    cout << res ;
    return 0 ;
}

int main()
{
    freopen("CAKHEO.inp" , "r" , stdin) ;
    freopen("CAKHEO.out" , "w" , stdout) ;
    enter() ;
    process() ;
    return 0 ;
}
