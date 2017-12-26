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
#define maxN 100005

using namespace std ;

int n ;
pii a[maxN] ;
bool dead[maxN] ;

bool cmp (pii a , pii b)
{
    return (a.fi < b.fi) || ((a.fi == b.fi) && (a.se < b.se)) ;
}

void enter()
{
    cin >> n ;
    forinc(i,1,n) {
        cin >> a[i].fi ; a[i].se = i ;
    }
    sort(a+1,a+1+n,cmp) ;
    int res = 0 ;
    forinc(i,1,n) if (!dead[a[i].se]){
        dead[a[i].se] = true ;
        dead[a[i].se-1] = true ;
        dead[a[i].se+1] = true ;
        res ++ ;
    }
    cout << res << endl ;
}

int main()
{
    //freopen("FIRS.inp" , "r" , stdin) ;
    enter() ;
    return 0 ;
}
