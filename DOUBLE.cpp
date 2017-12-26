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
#define maxN 50005
#define maxM 100005

using namespace std ;

int n , a[maxN], b[maxN] ;

void enter()
{
    cin >> n ;
    forinc(i,1,n) cin >> a[i] ;
    forinc(i,1,n) cin >> b[i] ;
}

int last[maxM] ;
vector<int> ke[maxN] ;

void add(int u , int v)
{
    ke[u].push_back(v) ;
    ke[v].push_back(u) ;
}

void prepare()
{
    forinc(i,1,n) {
        if (last[a[i]] != 0) add(i,last[a[i]]) ;
        if (last[b[i]] != 0) add(i,last[b[i]]) ;
        last[a[i]] = i ; last[b[i]] = i ;
    }
}

int id[maxM]  ;

void dfs(int u)
{

}

void process()
{
    prepare() ;
    forinc(i,1,n) if (!vis[i]) {
        id[x[i]] = 1 ; id[y[i]] = 2 ;
    }
}

int main()
{
    return 0 ;
}
