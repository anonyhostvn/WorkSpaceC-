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
#define maxN 305

using namespace std ;

struct coordinate{
    int X , Y ;
};

struct vect{
    int X , Y ;
    long long operator * (const vect &other) {
        return (long long) X * other.Y - (long long) other.X * Y ;
    }
};

vect get_vect(coordinate A , coordinate B)
{
    vect res ;
    res.X = B.X - A.X ;
    res.Y = B.Y - A.Y ;
    return res ;
}

bool ccw(coordinate A , coordinate B , coordinate C)
{
    vect V_1 = get_vect(A,B) , V_2 = get_vect(B,C) ;
    return (V_1 * V_2) < 0 ;
}

coordinate a[maxN] ;

int n , below[maxN][maxN] ;

void enter()
{
    cin >> n ;
    forinc(i,1,n) cin >> a[i].X >> a[i].Y ;
}

bool dd[maxN][maxN][maxN] ;

void prepare()
{
    forinc(i,1,n)
    forinc(j,1,n) if (i != j && a[i].X <= a[j].X) {
        forinc(t,1,n) if (t != j && t != i && a[i].X <= a[t].X && a[t].X <= a[j].X && ccw(a[i],a[j],a[t]))
            below[i][j] ++ , dd[i][j][t] = true ;
        below[j][i] = -below[i][j] ;
    }
}

int ans[maxN] ;

void process()
{
    prepare() ;
    forinc(i,1,n)
    forinc(j,1,n) if (i != j && a[i].X <= a[j].X)
        forinc(t,1,n) if (t != j && t != i) {
            int cnt = abs(below[i][t] + below[t][j] + below[j][i]) ;
            if (dd[i][j][t] || dd[i][t][j] || dd[j][t][i] || dd[j][i][t] || dd[t][i][j] || dd[t][j][i]) cnt -- ;
            ans[cnt] ++ ;
        }
    forinc(i,0,n-3) cout << ans[i] / 3 << endl ;
}

int main()
{
    freopen("triangles.in" , "r" , stdin) ;
    freopen("triangles.out" , "w" , stdout) ;
    enter() ;
    process() ;
    return 0 ;
}
