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

int n , m , t[maxN] , c[maxN] ;
long long f[maxN] ;

typedef long long TCoord ;

struct Point{
    TCoord x , y ;
};

typedef Point Tvector ;

TCoord operator * (const Point &a , const Point &b) {return a.x * b.y - b.x * a.y ; }
Tvector operator - (const Point &a , const Point &b) {return {a.x-b.x,a.y-b.y} ; }

bool CCW(const Point &a , const Point &b , const Point &c) {return (b-a) * (c-b) < 0 ; }

void enter()
{
    scanf("%d%d" , &n , &m) ;
    forinc(i,1,n) scanf("%d" , &t[i]) , f[i] = f[i-1] + t[i] ;
    forinc(i,1,m) scanf("%d" , &c[i]) ;
}

vector<Point> ans ;

void convexHull()
{
    vector<Point> p ; p.clear() ;
    forinc(i,1,n) p.push_back({f[i-1],f[i]}) ;
    forv(i,p) {
        while (ans.size() >= 2 && !CCW(ans[ans.size()-2],ans[ans.size()-1],p[i])) ans.pop_back() ;
        ans.push_back(p[i]) ;
    }
}

long long Find_(int x , int y) {
    Point tmp = {x,y} ;
    long long tmax = 0 ;
    forv(i,ans) if (tmax < tmp * ans[i]) tmax = tmp * ans[i] ;
    return tmax ;
}

void sub_1()
{
    convexHull() ;
    long long td = 0 ;
    forinc(i,2,m) td += Find_(c[i-1],c[i]) ;
    td += (long long) c[m] * f[n] ;
    cout << td << endl ;
}

void process()
{
    long long td = 0 ;
    forinc(i,2,m) {
        long long tmp = 0 ;
        forinc(j,1,n) tmp = max(tmp,(long long) c[i-1] * f[j] - (long long) c[i] * f[j-1]) ; td += tmp ;
    }
    td += (long long) c[m] * f[n] ;
    printf("%lld" , td) ;
}

int main()
{
    freopen("READERS.inp", "r" , stdin) ;
    freopen("READERS.out" , "w" , stdout) ;
    enter() ;
    sub_1();
    return 0 ;
}
