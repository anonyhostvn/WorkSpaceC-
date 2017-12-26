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
#define oo (long long) 1e15
#define maxN 100005

using namespace std ;

typedef long long TCoord ;

struct Point {
    TCoord x , y ;
};

typedef Point Tvector ;

int n ;
Point a[maxN] ;

TCoord sqrLen(const Tvector &u) {return u.x * u.x + u.y * u.y ; }

TCoord operator * (const Tvector &u , const Tvector &v) {return u.x * v.y - u.y * v.x ; }

Tvector operator - (const Tvector &u , const Tvector &v) {return {u.x - v.x , u.y - v.y} ; }

Tvector operator + (const Tvector &u , const Tvector &v) {return {u.x + v.x , u.y + v.y} ; }

void enter()
{
    scanf("%d" , &n) ;
    forinc(i,1,n) scanf("%lld%lld" , &a[i].x , &a[i].y) ;
}

Point Find_A()
{
    Point res  = {oo,oo} ;
    forinc(i,1,n) if (res.y > a[i].y) res = a[i] ; else if (res.y == a[i].y && res.x > a[i].x) res = a[i] ;
    return res ;
}

Point A ;

bool CCW(const Point &a , const Point &b , const Point &c) { return (b-a) * (c-b) > 0 ;}

bool cmp (Point u , Point v) {return ((u-A) * (v-A) > 0) || ((u-A) * (v-A) == 0 && sqrLen(u-A) < sqrLen(v-A)) ; }

long double S (vector<Point> ans)
{
    long double res = 0;
    forv(i,ans) res += ans[i] * ans[(i+1) % ans.size()] ;
    return (long double) res / 2 ;
}

void convexHull()
{
    A = Find_A() ;
    sort(a+1,a+1+n,cmp) ;
    vector<Point> ans ; ans.push_back(A) ;
    forinc(i,2,n) {
        while (ans.size() >= 2 && !CCW(ans[ans.size()-2],ans[ans.size()-1],a[i])) ans.pop_back() ;
        ans.push_back(a[i]) ;
    }
    cout << ans.size() << endl ;
    cout << fixed << setprecision(1) << S(ans) << endl ;
    forv(i,ans) cout << ans[i].x << " " << ans[i].y << endl ;
}

int main()
{
    freopen("CONVEXHULL.inp" , "r" , stdin) ;
    freopen("CONVEXHULL.out" , "w" , stdout) ;
    enter() ;
    convexHull() ;
    return 0 ;
}
