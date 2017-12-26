#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++ )
#define fordec(i,a,b) for (int i  = a ; i >= b ; i-- )
#define oo 1000000000

using namespace std ;

int n,b[251][251],subset_1[251],subset_2[251],psub_1,psub_2,res ;
bool dd[251] ;

int enter()
{

    cin >> n ;

    forinc(i,1,n)
    forinc(j,1,n) cin >> b[i][j] ;

}

int solve()
{

    forinc(i,1,psub_1)
    forinc(j,1,psub_1)
    if ((i != j) && (b[subset_1[i]][subset_1[j]] == 0)) return 0;

    forinc(i,1,psub_2)
    forinc(j,1,psub_2)
    if ((i != j) && (b[subset_2[i]][subset_2[j]] == 0)) return 0 ;

    res = min (res,abs(psub_2-psub_1)) ;

}

int bt(int i)
{

    if (i == n+1)
    {

        solve() ;
        return 0 ;

    }

    psub_1++;
    subset_1[psub_1] = i ;
    bt(i+1) ;

    psub_1-- ;
    psub_2++ ;  subset_2[psub_2] = i ;
    bt(i+1) ;

    psub_2-- ;

}

int sub1()
{

    res = oo ;
    bt(1) ;

    if (res != oo) cout << res ; else cout << "Impossible" ;

}

int sub2()
{

    psub_1 = 1 ; subset_1[1] = 1 ; dd[1] = true ;

    forinc(i,2,n) if (b[1][i] == 1)
    {

        psub_1 ++ ;
        subset_1[psub_1] = i ;
        dd[i] = true ;

    }
}

int process()
{

    if (n <= 16) sub1() ; else cout << "Impossible" ;

}

int main ()
{

    freopen("PARTITION.inp" , "r" , stdin) ;
    freopen("PARTITION.out" , "w" , stdout) ;

    enter() ;
    sub1() ;

}
