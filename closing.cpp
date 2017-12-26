#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)
#define forv(i,u) for (int j = 0 ; j < ke[u].size() ; j++)

using namespace std ;

int n , m , b[200001], lab[200001] , res[200001] ;
vector <int> ke[200001] ;
bool inuse[200001] ;

int enter()
{
    cin >> n >> m ;

    forinc(i,1,m){
        int u , v ;
        cin >> u >> v ;
        ke[u].push_back(v) ;
        ke[v].push_back(u) ;
    }
    forinc(i,1,n) cin >> b[i] ;
}

int getroot(int u)
{
    if (lab[u] == u) return u ;
    lab[u] = getroot(lab[u]) ;
    return lab[u] ;
}

int process()
{
    int slt = 0 ;

    fordec(i,n,1)
    {
        inuse[b[i]] = true ;
        slt ++ ;
        lab[b[i]] = b[i] ;

        forv(j,b[i])
        {
            int v = ke[b[i]][j] ;
            if (inuse[v] && getroot(b[i]) != getroot(v))
            {
                lab[lab[b[i]]] = lab[v] ;
                --slt ;
            }
        }

        if (slt == 1) res[i] = 0  ; else res[i] = 1 ;
    }

    forinc(i,1,n) if (res[i] == 0) cout << "YES" << endl ;
    else cout << "NO" << endl ;
}

int main()
{

    freopen("closing.inp" , "r" , stdin) ;
    freopen("closing.out" , "w" , stdout) ;

    ios_base::sync

    enter()  ;
    process() ;

}

