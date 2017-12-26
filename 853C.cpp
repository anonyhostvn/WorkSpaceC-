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
#define maxN 200005

using namespace std ;
struct node {
    int val , info , pos , lpos , rpos , range ;
    node (int v , int i , int p , int lp , int rp  , int r) {
        val = v ; info = i ; pos = p ; lpos = lp ; rpos = rp ; range = r ;
    }
} ;

vector<node> A ;
int n , q ;

void push_query(int i ,int l , int d , int r , int u)
{
    A.push_back(node(0,-1,i,1,n,1)) ; A.push_back(node(l-1,1,i,1,n,1)) ;
    A.push_back(node(0,-1,i,1,d-1,2)) ; A.push_back(node(n,1,i,1,d-1,2)) ;
    A.push_back(node(r,-1,i,1,n,3)) ; A.push_back(node(n,1,i,1,n,3)) ;
    A.push_back(node(0,-1,i,u+1,n,4)) ; A.push_back(node(n,1,i,u+1,n,4)) ;
    A.push_back(node(0,-1,i,u+1,n,5)) ; A.push_back(node(l-1,1,i,u+1,n,5)) ;
    A.push_back(node(0,-1,i,1,d-1,6)) ; A.push_back(node(l-1,1,i,1,d-1,6)) ;
    A.push_back(node(r,-1,i,1,d-1,7)) ; A.push_back(node(n,1,i,1,d-1,7)) ;
    A.push_back(node(r,-1,i,u+1,n,8)) ; A.push_back(node(n,1,i,u+1,n,8)) ;
}

void enter()
{
    cin >> n >> q ;
    forinc(i,1,n) {
        int x ; cin >> x;  A.push_back(node(x,-2,i,0,0,0)) ;
    }
    forinc(i,1,q) {
        int l , d , r , u ;
        cin >> l >> d >> r >> u ;
        //push_query(i,l,d,r,u) ;
        push_query(i,d,l,u,r) ;
    }
}

bool cmp(node a , node b) {return (a.val < b.val) || ((a.val == b.val) && (a.info < b.info)) ; }

int BIT[maxN] ;
long long ans[maxN][8] ;

void update(int x)
{
    for (int i = x ; i <= n ; i += i & -i)
        BIT[i] ++ ;
}

int get(int x)
{
    int res = 0 ;
    for (int i = x ; i > 0 ; i -= i & -i) res += BIT[i] ;
    return res ;
}

void process()
{
    sort(A.begin() , A.end() , cmp) ;
    forv(i,A) if (A[i].info == -2) update(A[i].pos) ;
    else ans[A[i].pos][A[i].range-1] += (long long) A[i].info * (get(A[i].rpos) - get(A[i].lpos-1)) ;
    //forinc(i,0,7) cout << ans[3][i] << " " ; cout << endl ;
    long long sum = (long long) n * (n-1) / 2 ;
    forinc(i,1,q) {
        long long res = 0 ;
        forinc(j,0,7) if (ans[i][j] > 0) res += (long long) ((j <= 3) ? 1 : -1) * ((long long) ans[i][j] * (ans[i][j]-1) / 2) ;
        cout << sum - res << endl ;
    }
}

int main()
{
    //freopen("853C.inp" , "r" , stdin) ;
    ios_base::sync_with_stdio(false) ;
    cin.tie(0) ; cout.tie(0) ;
    enter() ;
    process() ;
    return 0 ;
}
