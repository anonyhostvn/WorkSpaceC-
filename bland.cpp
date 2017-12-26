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
#define maxN 305

using namespace std ;

int n , m , a[maxN][maxN], f_min[maxN] , f_max[maxN] , k , f[maxN][maxN] , g[maxN];

void enter()
{
    cin >> m >> n >> k ;
    forinc(i,1,m) forinc(j,1,n) cin >> a[i][j] ;
}

deque<int> st[2] ;
int ans[maxN] ;

void add(int i)
{
    while (!st[0].empty() && f_min[i] <= f_min[st[0].back()]) st[0].pop_back() ;
    while (!st[1].empty() && f_max[i] >= f_max[st[1].back()]) st[1].pop_back() ;
    st[0].push_back(i) ; st[1].push_back(i) ;
}

void remove_(int i)
{
    if (!st[0].empty() && st[0].front() == i) st[0].pop_front() ;
    if (!st[1].empty() && st[1].front() == i) st[1].pop_front() ;
}

void build()
{
    st[0].clear() ; st[1].clear() ;
    int j = 1 ;
    forinc(i,1,n) {
        add(i) ;
        while (j <= i && f_max[st[1].front()] - f_min[st[0].front()] > k) remove_(j ++) ;
        ans[i] = j ;
    }
}

void prepare()
{
    forinc(row,1,m) {
        forinc(i,1,n) f_min[i] = a[row][i] , f_max[i] = a[row][i];
        int tres = 0 ;
        fordec(i,row,1) {
            forinc(j,1,n) f_min[j] = min(f_min[j],a[i][j]) , f_max[j] = max(f_max[j],a[i][j]) ;
            build() ; int res = 0 ;
            forinc(j,1,n) res = max(res,(row - i +1) * (j - ans[j] + 1)) ;
            f[row][i] = max(f[row][i+1],res) ;
            tres = max(tres,res) ;
        }
        g[row] = max(g[row-1],tres) ;
    }
}

int solve()
{
    int res = 0 ;
    forinc(i,1,m-1) {
        forinc(j,i+1,m) res = max(res,g[i] + f[j][i+1]) ;
    }
    return res ;
}

int b[maxN][maxN] ;

void reverse_()
{
    forinc(i,1,m) forinc(j,1,n) b[j][i] = a[i][j] ;
    forinc(i,1,n) forinc(j,1,m) a[i][j] = b[i][j] ;
    swap(n,m) ;
}

void process()
{
    prepare() ;
    int res = solve() ;
    reverse_() ;
    prepare() ;
    res = max(res,solve()) ;
    cout << res << endl ;
}

int main()
{
    //freopen("bland.inp" , "r" , stdin) ;
    enter() ;
    process() ;
    return 0;
}
