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
#define maxK 100

using namespace std ;

int a[maxK+1] , n , k ;
bool dd[maxN+1][3] ;

int enter()
{
    cin >> n  >> k ;
    forinc(i,1,n) cin >> a[i] ;
    return 0 ;
}

priority_queue <pii> q ;

int process()
{
    forinc(i,1,k) q.push(mk(a[i],i)) ;
    int j = 1 ;
    while (q.top().fi >= 4 && j <= n){
        int id = q.top().se ; q.pop() ;
        a[id] -= 4 ;
        dd[j][1] = true; ++j ;
        if (a[id] > 0) q.push(mk(a[id],id)) ;
    }
    j = 1 ;
    while (q.top().fi >= 2 && j <= n){
        int id = q.top().se ; q.pop() ;
        a[id] -= 2 ;
        dd[j][0] = true ; j ++ ;
        if (a[id] > 0) q.push(mk(a[id],id)) ;
    }
    j = 1 ;
    while (q.top().fi >= 2 && j <= n){
        int id = q.top().se ; q.pop() ;
        a[id] -= 2;
        dd[j][0]  = true ; j++ ;
        if (a[id] > 0) q.push((mk(a[id],id))) ;
    }
    return 0 ;
}

int main()
{

}
