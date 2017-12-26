#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)

using namespace std ;

int n,k,q,l[200001],r[200001],a[200001],b[200001],f[200001],g[200001] ;

int enter()
{

    cin >> n >> k >> q ;

    forinc(i,1,n) cin >> l[i] >> r[i] ;

    forinc(i,1,q) cin >> a[i] >> b[i] ;

}

int infirst_delast()
{

    forinc(i,1,n)
    {

        f[l[i]]++ ;
        f[r[i]+1]-- ;

    }

    forinc(i,1,200000) f[i] = f[i-1] + f[i] ;

}

int process()
{

    infirst_delast() ;

    forinc(i,1,200000)
    if (f[i] >= k) g[i] = g[i-1] + 1 ; else g[i] = g[i-1] ;

    forinc(i,1,q) cout << g[b[i]] - g[a[i]-1] << endl ;

}

int main ()
{

    //freopen("816B.inp" , "r" , stdin) ;

    enter () ;
    process() ;

}
