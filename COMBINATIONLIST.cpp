#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i--)

using namespace std ;

int n , m , k , a[10001];
bool dd[10001] ;
long long c[10001][10001] ;

int prepare()
{

    c[1][1] = 1 ; c[0][0] = 1 ;
    forinc(i,1,n) {c[0][i] = 1 ; c[i][i] = 1 ;}

    forinc(i,2,n)
    forinc(j,1,i-1) if (c[j-1][i-i] + c[j][i-1] <= k) c[j][i] = c[j-1][i-1] + c[j][i-1] ;

}

int main()
{

    //freopen("COMBINATIONLIST.inp" , "r" , stdin) ;
    //freopen("COMBINATIONLIST.out" , "w" , stdout) ;

    cin >> n >> m >> k ;

    prepare() ;

    long long cnt = 0 ;

    a[0] = 0 ;

    forinc(i,1,m)
    {


        int temp = 0 , tmp = 0 , l[10002] , dem = 0;

        forinc(j,a[i-1]+1,n) if (!dd[j])
        {
            dem ++ ;
            l[dem] = j ;

        }

        forinc(j,1,dem)
        if ((cnt + c[m-i][dem-j] < k) && (c[m-i][dem-j] != 0)) cnt += c[m-i][dem-j] ;
        else
        {

            a[i] = l[j] ;

            dd[l[j]] = true ;

            if (cnt + c[m-i][dem-j] == k) cnt = k ;

            break ;

        }

    }

    forinc(i,1,m) if (a[i] == 0) {cout << -1 ; return 0 ;}
    forinc(i,1,m) cout << a[i] << " " ;

}
