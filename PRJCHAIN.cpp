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
#define maxN 100005

using namespace std ;

int n , a[maxN],b[maxN] ;

void enter()
{
    cin >> n ;
    forinc(i,1,n) cin >> a[i]  ;
    forinc(i,1,n) cin >> b[i] ;
}

struct node{
    int ca ,cb , pos ;
    node (int a , int b , int c) {
        ca = a ; cb = b ; pos = c ;
    }
};

vector<node> c[2] ;

bool cmp_1(node a  , node b) {return (a.ca < b.ca) ; }
bool cmp_2(node a , node b) {return (a.cb > b.cb) ; }

vector<int> ans ;

void process()
{
    forinc(i,1,n) if (b[i] - a[i] >= 0) c[0].push_back(node(a[i],b[i],i)) ; else c[1].push_back(node(a[i],b[i],i)) ;

    if (c[0].size() > 0) sort(c[0].begin(),c[0].end(),cmp_1) ;
    if (c[1].size() > 0) sort(c[1].begin(),c[1].end(),cmp_2) ;

    long long res = 0 , recent = 0 ;
    forv(i,c[0]) if (recent < c[0][i].ca) res += c[0][i].ca - recent , recent = c[0][i].cb ; else recent += -c[0][i].ca + c[0][i].cb ;
    forv(i,c[1]) if (recent < c[1][i].ca) res += c[1][i].ca - recent , recent = c[1][i].cb ; else recent += -c[1][i].ca + c[1][i].cb ;

    cout << res << endl ;
    forv(i,c[0]) cout << c[0][i].pos << " " ; forv(i,c[1]) cout << c[1][i].pos << " " ; cout << endl ;
}

int main()
{
    freopen("PRJCHAIN.inp" , "r" , stdin) ;
    freopen("PRJCHAIN.out" , "w" , stdout) ;
    ios_base::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    enter() ;
    process() ;
    return 0 ;
}
