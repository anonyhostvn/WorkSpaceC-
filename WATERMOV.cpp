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
#define maxN 1000005

using namespace std ;
typedef long double llu ;
typedef long long TCoord ;

struct Point{
    TCoord x, y ;
};
typedef Point Tvector ;

TCoord sqrLen(const Tvector &u) {return u.x * u.x + u.y * u.y ; }

Tvector operator + (const Tvector &u , const Tvector &v) {return {u.x + v.x , u.y + v.x} ; }

Tvector operator - (const Tvector &u , const Tvector &v) {return {u.x-v.x , u.y - v.y} ; }

TCoord operator % (const Tvector &u , const Tvector &v) {return u.x * v.x + u.y * v.y ; }

TCoord operator * (const Tvector &u , const Tvector &v) {return u.x * v.y - u.y * v.x ; }

bool CCW(const Point &A , const Point &B , const Point &C) {return (B-A) * (C-B) > 0 ; }

int n , a[maxN] ;
long long  b[maxN] ;

void enter()
{
    scanf("%d" , &n) ;
    forinc(i,1,n) scanf("%d" , &a[i]) ;
}

Point A ;
Point pa[maxN] ;

vector<Point> ans , Tans ;

void convexHull()
{
    //forinc(i,0,n) cout << pa[i].x << " " << pa[i].y << endl ;
    ans.push_back(pa[0]) ;
    forinc(i,1,n) {
        while (ans.size() >= 2 && !CCW(ans[ans.size()-2],ans[ans.size()-1],pa[i])) ans.pop_back() ;
        ans.push_back(pa[i]) ;
    }
}

void prepare()
{
    forinc(i,1,n) b[i] = b[i-1] + a[i] ;
    forinc(i,0,n) pa[i].x = i , pa[i].y = b[i] ;
    convexHull() ;
    forinc(i,0,n) Tans.push_back(pa[i]) ;
    ans.push_back({n,0}) ;
    Tans.push_back({n,0}) ;
}

long double S(vector<Point> ans)
{
    long double res = 0 ;
    int n = ans.size() ;
    forv(i,ans) res += ans[i] * ans[(i+1) % n] ;
    return abs(res) ;
}

void process()
{
    prepare() ;
    cout << fixed << setprecision(1) << (long double) abs(S(Tans) - S(ans)) / 2 ;
}

int main()
{
    freopen("WATERMOV.inp" , "r" , stdin) ;
    freopen("WATERMOV.out" , "w" , stdout) ;
    enter() ;
    process() ;
    return 0 ;
}
