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
#define maxN 100001

using namespace std ;

struct dancer{
    int g , p , t ;
};

int n , w , h ;
dancer a[maxN] ;

int enter()
{
    cin >> n >> w >> h ;
    forinc(i,1,n) cin >> a[i].g >> a[i].p >> a[i].t ;
    return 0 ;
}

vector<pair<int,pii> > dance[2] ;
int treal[maxN] ;
pii ans[maxN]  ;

bool cmp(pair<int,pii> a , pair<int,pii> b)
{
    return (a.fi < b.fi) || (a.fi == b.fi && a.se.fi < b.se.fi) ;
}

int prepare()
{
    forinc(i,1,n) dance[a[i].g-1].push_back(mk(a[i].t-a[i].p,mk(a[i].p,i))) ;
    sort(dance[0].begin(),dance[0].end(),cmp) ;
    sort(dance[1].begin(),dance[1].end(),cmp) ;
    forinc(i,1,n) treal[i] = i ;
    return 0 ;
}

int process()
{
    prepare() ;
    forv(i,dance[0]) cout << dance[0][i].fi << " " << dance[0][i].se.fi << " " << dance[0][i].se.se << endl;
    forv(i,dance[1]) cout << dance[1][i].fi << " " << dance[1][i].se.fi << " " << dance[1][i].se.se << endl;
    int j = 0 ;
    forv(i,dance[0]) {
        while (j < dance[1].size() && dance[1][j].fi <= dance[0][i].fi) j ++ ;
        if (j > 0  && dance[0][i].fi == dance[1][j-1].fi) treal[dance[0][i].se.se] = dance[1][j-1].se.se ;
    } j = 0 ;
    forv(i,dance[1]) {
        while (j < dance[0].size() && (dance[0][j].fi <= dance[1][i].fi)) j ++ ;
        if (j > 0 && dance[1][i].fi == dance[0][j-1].fi) treal[dance[1][i].se.se] = dance[0][j-1].se.se ;
    }
    forinc(i,1,n) if (a[i].t == 1) {
        int id = treal[i] ;
        ans[id].fi = w ; ans[id].se = a[i].p ;
    } else {
        int id = treal[i] ;
        ans[id].fi = a[i].p ; ans[id].se = h ;
    }
    forinc(i,1,n) cout << ans[i].fi << " " << ans[i].se << endl ;
    return 0 ;
}

int main()
{
    freopen("849D.inp" , "r" , stdin) ;
    enter() ;
    process() ;
    return 0 ;
}
