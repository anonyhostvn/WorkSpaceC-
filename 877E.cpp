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
#define maxN 200005

using namespace std ;

struct interval{
    int val , rem ;
};
int n , a[maxN] ;
interval it[4*maxN] ;

void set_node(int s , int l ,int r)
{
    it[s].val = (r-l+1) - it[s].val ;
    it[s].rem  ++ ;
}

void trans(int s , int l , int r)
{
    if (it[s].rem == 0) return ;
    int mid = (l+r) / 2 ;
    if (it[s].rem % 2 != 0) set_node(2*s,l,mid) , set_node(2*s+1,mid+1,r) ;
    it[s].rem = 0 ;
}

void update(int s , int l , int r , int u , int v)
{
    if (r < u || v < l) return ;
    if (u <= l && r <= v) {
        set_node(s,l,r) ;
        return ;
    }
    trans(s,l,r) ;
    int mid = (l+r) / 2 ;
    update(2*s,l,mid,u,v) ;
    update(2*s+1,mid+1,r,u,v) ;
    it[s].val = it[2*s].val + it[2*s+1].val ;
}

int get(int s , int l , int r , int u , int v)
{
    if (r < u || v < l) return 0 ;
    if (u <= l && r <= v) return it[s].val ;
    trans(s,l,r) ;
    int mid = (l+r) / 2 ;
    return get(2*s,l,mid,u,v) + get(2*s+1,mid+1,r,u,v) ;
}

vector<int> ke[maxN] ;

void add(int u , int v)
{
    ke[u].push_back(v) ;
    ke[v].push_back(u) ;
}

void enter()
{
    cin >> n ;
    forinc(i,2,n) {
        int x ; cin >> x ;
        add(x,i) ;
    }
    forinc(i,1,n) cin >> a[i] ;
}

int f[maxN] , num[maxN] , cnt = 0 , id[maxN] ;

void dfs(int u , int p)
{
    num[u] = ++cnt ; id[cnt] = u ; f[u] = 1 ;
    forv(i,ke[u]) {
        int v = ke[u][i] ;
        if (v != p) dfs(v,u) , f[u] += f[v] ;
    }
}

void process()
{
    dfs(1,-1) ;
    forinc(i,1,n) if (a[i] == 1) update(1,1,n,num[i],num[i]) ;
    int q = 0 ; cin >> q ;
    forinc(i,1,q) {
        string st ; int x ;
        cin >> st ; cin >> x ;
        if (st == "pow") update(1,1,n,num[x],num[x] + f[x] - 1) ;
        else cout << get(1,1,n,num[x],num[x]+f[x]-1) << endl ;
    }
}

int main()
{
    //freopen("877E.inp" , "r" , stdin) ;
    enter() ;
    process() ;
    return 0 ;
}
