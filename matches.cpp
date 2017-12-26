#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)

using namespace std ;

int dd[101][101] , a[101] , m , n;

string info[40001] ;

map<string , int> promap ;

int process()
{

    forinc(k,1,m)
    {

        forinc(i,1,n) cin >> a[i] ;

        forinc(i,1,n/2) info[a[i]] += '0' ;

        forinc(i,n/2+1,n) info[a[i]] += '1' ;

    }

    forinc(i,1,n) promap[info[i]] = 0 ;

    forinc(i,1,n)
    {

        if (promap[info[i]] > 0)
        {

            cout << "NO" ;

            return 0 ;

        }

    promap[info[i]] = promap[info[i]]  + 1 ;

    }

    cout << "YES" ;

}

int enter()
{

    cin >> n >> m ;

    process() ;

}

int main()
{

    //freopen("matches.inp" , "r" , stdin) ;

    enter() ;

}
