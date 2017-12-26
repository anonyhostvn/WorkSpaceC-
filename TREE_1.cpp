#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b  ; i++)
#define fordec(i,a,b) for (int i = a ; i >= b  ; i--)

using namespace std ;

int n , m , a[1001] , info[1001] , dd[1001] , par[1001] , root ,res  , leaf[1001] ,id[1001];

bool isleaf[1001] ;

vector <int>  ke[1001] ;

int add(int u , int v)
{

    ke[u].push_back(v) ;

    par[v] ++ ;

}

int enter()
{

    cin >> n >> m ;

    forinc(i,1,m) cin >> a[i] ;

    int cnt = 0 ;

    forinc(i,1,n)
    {

        int k ,l , r ;

        cin >> k >> l >> r ;

        if (k == 0)
        {

            isleaf[i] = true ;

            cnt ++ ;

            id[i] = cnt ;

        }
        else
        {

            info[i] = k ;

            add(i,l) ;
            add(i,r) ;

        }

    }

    forinc(i,1,n) if (par[i] == 0) root = i ;

}

int dfs(int u)
{

    if (isleaf[u]) return leaf[id[u]];

    int res = 0 , gt[2] , scon = 0  ;

    for (int j = 0 ; j < ke[u].size() ; j++)
    {

        gt[j] = dfs(ke[u][j]) ;

        scon++ ;

    }

    if (scon == 1) return gt[0] ;

    if (info[u] == 1) return max(gt[0],gt[1]) ;

    else return min(gt[0],gt[1]) ;

}

int solve()
{

    res = max(res,dfs(root)) ;

}

int bt(int i)
{

    if (i == m+1)
    {

        solve() ;

        return 0 ;

    }

    forinc(j,1,m)
    if (dd[j] == 0)
    {

        leaf[i] = a[j] ;

        dd[j] = 1 ;

        bt(i+1) ;

        dd[j] = 0 ;

    }

}

int sub1 ()
{

    bt(1) ;

    cout << res ;

}


int main()
{

    freopen("TREE.inp" , "r" , stdin) ;
    freopen("TREE.out" , "w" , stdout) ;

    enter() ;
    sub1() ;

}
