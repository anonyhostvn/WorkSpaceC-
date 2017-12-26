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

int n , q , a[100001] , r[100001] , nxt[100001] , block[100001] , f[100001] , step[100001] ;
long long t[100002] ;

int update(int id  ,int x)
{
    for (int i = id ; i <= n+1 ; i += i & -i) t[i] += x ;
    return 0 ;
}

long long get(int id)
{
    long long res = 0 ;
    for (int i = id ; i > 0 ; i -= i & -i) res += t[i] ;
    return res ;
}

int jump(int start , int k)
{

}

stack<int> st ;

int fix_seg(int sl , int sr , int sfl , int sfr)
{
    fordec(i,sr,sl){
        while (!st.empty() && get(i) >= get(st.top())) st.pop() ;
        if (!st.empty()) r[i] = st.top() ; else r[i] = n+1 ;
    }
    forinc(i,sfl,sfr) if (r[i] <= n && r[i] - i <= 100) nxt[i] = r[i] ; else nxt[i] = i ;
    while (st.empty()) st.pop() ;
    return 0 ;
}

int build_seg(int sl , int sr)
{
    fordec(i,n,1)
        if (block[nxt[i]] != block[i]) {
            f[i] = i ; step[i] = 0 ;
        }
        else {
            f[i] = f[nxt[i]] ; step[i] = step[nxt[i]] + 1 ;
        }
    return 0 ;
}

int process(int l , int r , int x)
{
    update(l,x) ;
    update(r+1,-x) ;
    fix_seg(max(1,l-100),min(n,l+100),max(1,l-100),l) ;
    fix_seg(max(1,r-100),min(n,r+100),max(1,r-100),r) ;
    return 0 ;
}

int prepare()
{
    stack <int> st ;
    fordec(i,n,1) {
        while (!st.empty() && a[i] >= a[st.top()]) st.pop() ;
        if (!st.empty()) r[i] = st.top() ; else r[i] = n+1 ;
    }

    int p = (int) sqrt(n) ;
    forinc(i,1,n) {
        update(i,a[i]) ;
        update(i+1,-a[i]) ;
    }
    fix_seg(1,n,1,n) ;
    build_seg(1,n) ;
    return 0 ;
}

int enter()
{
    cin >> n >> q ;
    forinc(i,1,n) cin >> a[i] ;
    prepare() ;
    forinc(i,1,q) {
        int query = 0 ; cin >> query ;
        if (query == 1) {
            int start , k ; cin >> start >> k ;
            jump(start,k) ;
        }
        else {
            int l , r , x ; cin >> l >> r >> x ;
            process(l,r,x) ;
        }
    }
    return 0 ;
}

int main()
{
    return 0 ;
}
