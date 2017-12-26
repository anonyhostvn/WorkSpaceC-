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
#define maxN 300005

using namespace std ;

int n , k , a[maxN] ;

void enter()
{
    cin >> n >> k ;
    forinc(i,1,n) cin >> a[i] ;
}

priority_queue<pii> q ;
int depart[maxN] ;

void process()
{
    long long res = 0 ;
    forinc(i,1,n+k) {
        if (i <= n) q.push(mk(a[i],i)) ;
        if (i > k) {
            while (depart[q.top().se]) q.pop() ;
            pii tmp = q.top() ; q.pop() ;
            depart[tmp.se] = i ;
            res += (long long) a[tmp.se] * (i - tmp.se) ;
        }
    }
    cout << res << endl ;
    forinc(i,1,n) cout << depart[i] << " " ; cout << endl ;
}

int main()
{
    //freopen("853A.inp" , "r" , stdin) ;
    enter() ;
    process() ;
    return 0 ;
}
