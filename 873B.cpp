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
#define maxN 100005

using namespace std ;

int n  ;
pii a[maxN] ;
string S ;

void enter()
{
    cin >> n ;
    cin >> S ;
    forinc(i,1,n) a[i].fi = a[i-1].fi + (((int) S[i-1] - (int) '0' == 0) ? -1 : 1) , a[i].se = i ;
}

bool cmp (pii a , pii b)
{
    return (a.fi < b.fi) || ((a.fi == b.fi) && (a.se < b.se)) ;
}

void process()
{
    sort(a,a+1+n,cmp) ;
    int j = 0 , res = 0 ;
    forinc(i,1,n) if (a[i].fi != a[i-1].fi) res = max(res,a[i-1].se - a[j].se)  , j = i ;
    res = max(res,a[n].se - a[j].se) ;
    cout << res << endl ;
}


int main()
{
    //freopen("873B.inp" , "r" , stdin) ;
    enter() ;
    process() ;
    return 0 ;
}
