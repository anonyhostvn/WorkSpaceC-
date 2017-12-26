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

template <class _T> bool maximize(_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize(_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

const int ooit = 2e9 ;
const long long ooll = 1e15 ;
const double esp = 0.000000000000001 ;

using namespace std ;

typedef long long TCoord ;

struct TPoint { int x , y , z ; };
typedef TPoint Tvector ;

struct Ball {
    TPoint pos ; int R ;
};

struct tea_store {
    TPoint pos ; int W ;
};

Tvector operator * (const Tvector &a , const Tvector &b) { return {a.y * b.z - a.z * b.y , a.z * b.x - b.z * a.x , a.x * b.y - a.y * b.x} ; } ;

Tvector operator - (const TPoint &u , const TPoint &v) {return {u.x - v.x , u.y - v.y , u.z - v.z} ; } ;

bool operator == (const TPoint &u , const TPoint &v) {return (u.x == v.x) && (u.y == v.y) && (u.z == v.z) ; }

TCoord sqrLen(const Tvector &u) {return u.x * u.x + u.y * u.y + u.z * u.z ; }

TCoord sqr(TCoord a) {return (TCoord) a * a ; }

long double sqrDistance (TPoint O , TPoint P , TPoint S) {
    Tvector u = S - P , v = O - P ;
    return (long double) sqrLen(u * v) / sqrLen(u) ;
}

bool Tangent (TPoint O , TPoint P , TPoint S , TCoord sqrR) {
    Tvector u = S - P , v = O - P ;
    return sqrLen(u * v) > sqrR * sqrLen(u) ;
}


#define maxM 2005
#define maxN 20

int n , m , k ;
TPoint PVH ;
Ball a[maxM] ;
tea_store b[maxN] ;

int fastRead() {
    int res = 0 ; char c ; bool neg = false ;
    for (c = getchar() ; (c < '0' || c > '9') ; c = getchar()) if (c == '-') neg = true ;
    for ( ; c >= '0' && c <= '9' ; c = getchar()) res *= 10 , res += c - '0' ;
    if (neg) res *= -1 ;
    return res ;
}

void enter () {
    m = fastRead() ; n = fastRead() ; k = fastRead() ;
    forinc(i,1,m) a[i].pos.x = fastRead() , a[i].pos.y = fastRead() , a[i].pos.z = fastRead() , a[i].R = fastRead() ;
    forinc(i,1,n) b[i].pos.x = fastRead() , b[i].pos.y = fastRead() , b[i].pos.z = fastRead() , b[i].W = fastRead() ;
    PVH.x = fastRead() ; PVH.y = fastRead() ; PVH.z = fastRead() ;
}

void enter_ () {
    cin >> m >> n >> k ;
    forinc(i,1,m) cin >> a[i].pos.x >> a[i].pos.y >> a[i].pos.z >> a[i].R ;
    forinc(i,1,n) cin >> b[i].pos.x >> b[i].pos.y >> b[i].pos.z >> b[i].W ;
    cin >> PVH.x >> PVH.y >> PVH.z ;
}

bool checking(TPoint sphe_center , int radius , TPoint A , TPoint B) {
    if (A == B) return false ;
    long long sqr_radius = sqr(radius) ;
    if (sqrLen(sphe_center-A) <= sqr_radius && sqrLen(sphe_center-B) <= sqr_radius) return false ;
    if (sqrLen(sphe_center-A) <= sqr_radius) return true ;
    if (sqrLen(sphe_center-B) <= sqr_radius) return true ;
    //if (sqrDistance(sphe_center , A , B) > sqr_radius) return false ;
    if (Tangent(sphe_center , A , B , sqr_radius)) return false ;

    Tvector vtcp = B - A ;
    TCoord M = vtcp.x * sphe_center.x + vtcp.y * sphe_center.y + vtcp.z * sphe_center.z - (vtcp.x * A.x + vtcp.y * A.y + vtcp.z * A.z) ;
    if (M < 0) return false ;
    if (M > sqrLen(vtcp)) return false ;

    return true ;
}

bool must_remove[maxM][maxN] ;

void prepare () {
    forinc(i,1,m)
    forinc(j,1,n)
        must_remove[i][j] = checking(a[i].pos , a[i].R , b[j].pos , PVH) ;
}

int get_bit(int stt , int i) {return (stt >> i) & 1 ; }

bool _remove[maxM] ;

int solve(int stt , long long &ans) {
    int cnt = 0 ;
    forinc(i,1,m) _remove[i] = false ;

    forinc(i,1,n) if (get_bit(stt,i-1)) {
        ans += b[i].W ;
        forinc(j,1,m) if (!_remove[j] && must_remove[j][i]) _remove[j] = true , cnt ++ ;
        if (cnt > k) return cnt ;
    }

    return cnt ;
}

void process () {
    prepare () ;

    int s = (1 << n) - 1 ;
    long long res = 0 ;

    forinc(i,0,s) {
        long long milk_tea = 0 ;
        int sball = solve(i , milk_tea) ;
        if (sball <= k) maximize(res,milk_tea) ;
    }

    cout << res << endl ;
    cerr << res << endl ;
}

int main () {
    freopen("TEAWORLD.inp" , "r" , stdin) ;
    freopen("TEAWORLD.out" , "w" , stdout);

    enter () ;
    process () ;

    return  0 ;
}
