#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)
#define forv(j,u) for (int j = 0 ; j < u.size() ; j++)
#define pb push_back
#define pf push_front
#define fi first
#define se second

using namespace std ;

int n , a[5001] , f[5001][5001] , cnt[5001] ;
string s ;

int enter()
{
    cin >> s ;
    n = s.length() ;
    forinc(i,0,n-1) a[i+1] = (int)s[i] - (int)'a' ;
    return 0 ;
}

int cal(int l , int r)
{
    if (l == r || l > r){
        f[l][r] = 1 ;
        return 1 ;
    } ;
    if (f[l][r] != -1) return f[l][r] ;
    int tmp = cal(l+1,r-1) ;
    if (a[l] != a[r] || tmp == 0) {
        f[l][r] = 0 ;
        return 0 ;
    }
    int mid = 0 ;
    if ((r-l+1) % 2 == 0) mid = (l+r) / 2  ; else mid = (l+r) / 2 - 1 ;
    f[l][r] = cal(l,mid) + 1 ;
    return f[l][r] ;
}

int process()
{
    memset(f,-1,sizeof(f)) ;
    forinc(i,1,n)
    forinc(j,i,n)
    cnt[cal(i,j)] ++ ;
    fordec(i,n-1,1)cnt[i] += cnt[i+1]  ;
    forinc(i,1,n) cout << cnt [i] << " " ;
    return 0 ;
}

int main()
{
    //freopen("835D.inp" , "r" , stdin) ;
    enter() ;
    process() ;
    return 0 ;
}
