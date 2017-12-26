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
#define maxN 24
#define maxB 540000

using namespace std ;

int n , a[maxN+1] , cnt[2] ;
pair<long long,long long> c[2][540000] ;

int enter()
{
    cin >> n ;
    forinc(i,1,n) cin >> a[i] ;
    return 0 ;
}

bool cmp(pair<long long,long long> a , pair<long long,long long> b){
    return (a.fi < b.fi) || ((a.fi == b.fi) && (a.se < b.se)) ;
}

int bt(int id , int last , int i , long long s2 , long long s1)
{
    if (i == last + 1){
        c[id][++cnt[id]].fi = s2 - s1 ;
        c[id][cnt[id]].se = s1 ;
        return 0 ;
    }
    bt(id,last,i+1,s2,s1) ;
    bt(id,last,i+1,(long long)s2+a[i],s1) ;
    bt(id,last,i+1,s2,(long long)s1+a[i]) ;
    return 0 ;
}

int tfind(long long x)
{
    int res = 0 , l = 1 , r = cnt[1] ;
    while (l <= r){
        int mid = (l+r) / 2 ;
        if (c[1][mid].fi == x){
            res = mid ;
            l = mid + 1 ;
        }
        else if (c[1][mid].fi < x) l = mid + 1 ;
        else if (c[1][mid].fi > x) r = mid - 1 ;
    }
    return res ;
}

int process()
{
    long long res = 0 ;
    bt(0,n/2,1,0,0) ;
    bt(1,n,n/2+1,0,0) ;
    sort(c[1]+1,c[1]+1+cnt[1],cmp) ;
    forinc(i,1,cnt[0]) {
        int tmp = tfind(-c[0][i].fi) ;
        if (tmp == 0) continue ;
        res = max(res,c[0][i].se+c[1][tmp].se) ;
    }
    cout << res ;
    return 0 ;
}

int main()
{
    //freopen("DGOLD.inp" , "r" , stdin) ;
    enter() ;
    process() ;
    return 0 ;
}
