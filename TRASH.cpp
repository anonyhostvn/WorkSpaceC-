#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)
#define forv(j,u) for (int j = 0 ; j < u.size() ; j++)
#define pb push_back
#define pf push_front
#define fi
#define se second
#define mk make_pair
#define pii pair<int,int>
#define ooll (long long) 1e15
#define ooit (int) 2e9
#define maxN 105

template <class _T> bool maximize(_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize(_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

using namespace std ;

typedef long long Coord ;

struct Point { Coord x , y ; };
typedef Point Tvector ;

Coord operator * (const Tvector& a , const Tvector& b) {return a.x * b.y - a.y * b.x ; }

Tvector operator - (const Point& a , const Point& b) {return {a.x - b.x , a.y - b.y} ; }

Coord CCW (const Point& a ,const Point&b , const Point& c) {return (b-a) * (c-b) > 0 ; }

Coord sqrLen(const Tvector& a) {return a.x * a.x + a.y * a.y ; }

int n ;
Point c[maxN] , A ;

vector<Point> convex ;

void convex_Hull(){
    convex.clear() ;
    A.x = A.y = ooit ;

    forinc(i,1,n) if (minimize(A.y,c[i].y)) A.x = c[i].x ; else if (A.y == c[i].y) minimize(A.x,c[i].x) ;
    sort(c+1,c+1+n,[] (Point a , Point b) {
         return (a - A) * (b - A) > 0 || ((a - A) * (b - A) == 0 && sqrLen(a-A) < sqrLen(b-A)) ;
         }) ;

    convex.push_back(c[1]) ;
    forinc(i,2,n) {
        while (convex.size() >= 2 && !CCW(convex[convex.size()-2],convex[convex.size()-1],c[i])) convex.pop_back();
        convex.push_back(c[i]) ;
    }
}

void process (int test) {
    convex_Hull() ;

    long double res = ooll ;
    forinc(i,0,convex.size()-1) {
        int p1 = i , p2 = (i+1) % convex.size() ;
        Tvector vt_1 = convex[p2] - convex[p1] ;
        long long tmp = 0 ;
        forinc(j,0,convex.size()-1) if (j != p1 && j != p2) {
            Tvector vt_2 = convex[j] - convex[p1] ;
            maximize(tmp, abs(vt_1 * vt_2)) ;
        }

        minimize(res,  (long double) (tmp) / sqrt(sqrLen(vt_1))) ;
    }

    cout << "Case " << test << ": " << fixed << setprecision(2) << res << endl ;
}


void enter ()  {
    int test = 0 ;
    while (cin >> n) {
        if (n == 0) return ;
        forinc(i,1,n) cin >> c[i].x >> c[i].y ;
        process (++test) ;
    }
}

int main () {
    freopen("TRASH.inp" , "r" , stdin) ;
    freopen("TRASH.out" , "w" , stdout) ;
    enter () ;
    return 0 ;
}
