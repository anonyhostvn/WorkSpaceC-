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
#define maxN 10000

using namespace std ;

int n , c[maxN + 1] , t[maxN + 1] ;

int enter()
{
    cin >> n ;
    forinc(i,1,n) cin >> c[i] >> t[i] ;
    return 0 ;
}

pii info[maxN+1] ;
priority_queue<pii> heap ;

bool check(int mid)
{
    while (!heap.empty()) heap.pop() ;
    forinc(i,1,n){
        info[i].fi = max(1,c[i] - mid / t[i]) ;
        info[i].se = min(n,c[i] + mid / t[i]) ;
    }
    sort(info + 1 , info + 1 + n) ;
    int j = 1 ;
    forinc(i,1,n){
        while (j <= n && info[j].fi <= i) {
            heap.push(mk(-info[j].se,j)) ;
            ++j ;
        }
        if (heap.empty()) return false ;
        pii tmp = heap.top() ; heap.pop() ;
        int id = tmp.se ;
        if (info[id].fi > i || info[id].se < i) return false ;
    }
    return true ;
}

int process()
{
    int l = 0 , r = 10000000 , res = 0  ;
    while  (l <= r){
        int mid = (l+r) / 2 ;
        if (check(mid)){
            r = mid - 1 ;
            res = mid;
        }
        else l = mid + 1;
    }
    cout << res ;
    return 0 ;
}

int main()
{
    //  freopen("move12.inp" , "r" , stdin) ;
    enter() ;
    process() ;
    return 0 ;
}
