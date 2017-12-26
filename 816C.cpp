#include <bits/stdc++.h>
#define forinc(i,a,b) for(int i = a ; i <= b ; i++)
#define fordec(i,a,b) for(int i = a ; i >= b ; i--)
#define oo 10000000

using namespace std ;

int n , m , a[101][101] , cor[1000001] , scor[1000001] , kcor[1000001] , b[101][101] , cnt = 0 , smove = 0  ;

bool ok = true ,  isRevRow = false  ;

int enter()
{

    cin >> n >> m ;

    forinc(i,1,n)
    forinc(j,1,m) cin >> a[i][j] ;

}

int rev_row()
{

    if (n <= m) return 0 ;

    isRevRow = true ;

    forinc(i,1,n)
    forinc(j,1,m)
    {

        b[j][i] = a[i][j] ;

        a[i][j] = 0 ;

    }

    swap(n,m) ;

    forinc(i,1,n)
    forinc(j,1,m) a[i][j] = b[i][j] ;

}

int print()
{

    cout << smove << endl ;

    forinc(i,1,cnt)
    {

        string display ;

        if ((!isRevRow && cor[i] == 0) || (isRevRow && cor[i] == 1)) display = "row" ;
        else display = "col" ;

        forinc(j,1,scor[i]) cout << display << " " << kcor[i] << endl ;

    }

}

int process()
{

    rev_row() ;

    forinc(i,1,n)
    {

        int smin = oo ;

        forinc(j,1,m) smin = min(smin,a[i][j]) ;

        if (smin == 0) continue ;

        forinc(j,1,m) a[i][j] -= smin ;

        cnt ++ ;

        cor[cnt] = 0 ;

        kcor[cnt] = i ;

        scor[cnt] = smin ;

        smove += smin ;

    }

    forinc(j,1,m)
    {

        int smin = oo ;
        bool all_zero = true , all_equal = true ;

        forinc(i,1,n)
        {

            smin = min(smin,a[i][j]) ;

            if (a[i][j] != 0) all_zero = false ;

            if (a[i][j] != a[1][j]) all_equal = false ;

        }

        if ((!all_zero && smin == 0) || (!all_equal))
        {

            cout << -1 ;

            return 0 ;

        }

        if (smin == 0) continue ;

        forinc(i,1,n) a[i][j] -= smin ;

        cnt ++ ;

        cor[cnt] = 1 ;

        kcor[cnt] = j ;

        scor[cnt] = smin ;

        smove += smin ;

    }

    print() ;

}

int main ()
{

    //freopen("816C.inp" , "r" , stdin) ;

    enter () ;
    process() ;

}
