#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i--)

using namespace std ;

int a[4] , dd[2001][2001] , sum , ta[10000001] , tb[10000001] , cnt ;
bool ok = false ;

int enter ()
{

    cin >> a[1] >> a[2] >> a[3] ;
    sum = a[1] + a[2] + a[3] ;

}

int dfs(int v1 , int v2 , int v3 , int l)
{

    if (l >= 10000000) return 0 ;

    if ((v1 == 0) || (v2 == 0) || (v3 == 0))
    {

        ok = true ;

        return 0 ;

    }

    if (dd[v1][v2] != 0) return 0 ;

    dd[v1][v2] = 1 ;

    int v[4] ;
    v[1] = v1 ; v[2] = v2 ; v[3] = v3 ;

    forinc(i,1,3)
    forinc(j,1,3)
    if ((i != j) && (v[i] >= v[j]))
    {

        int tj = v[j] , ti = v[i] ;

        v[i] -= v[j] ;
        v[j] +=  v[j] ;

        dfs(v[1],v[2],v[3],l+1) ;

        if (ok)
        {

            cnt ++ ;
            ta[cnt] = i ;
            tb[cnt] = j ;
            return 0 ;

        }

        v[j] = tj ;
        v[i] = ti ;

    }

}

int main ()
{

    freopen("POUR.inp" , "r" , stdin) ;
    freopen("POUR.out" , "w" , stdout) ;

    enter() ;
    dfs(a[1],a[2],a[3],0) ;

    cout << cnt << endl ;
    fordec(i,cnt,1) cout << ta[i] << " " << tb[i] << endl ;

}
