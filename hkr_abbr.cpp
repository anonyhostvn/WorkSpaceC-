#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i--)

using namespace std ;

int q = 0 , na , nb ;
char sta[1001] , stb[1001] ;
bool f[1001][1001] ;

int process()
{

    f[0][0] = true ;

    forinc(i,0,nb)
    forinc(j,0,na)
    if (f[i][j])
    {

        if (sta[i+1] == stb[]

    }

}

int enter ()
{

    cin >> q ;

    forinc(i,1,q)
    {

        cin >> sta ;
        cin >> stb ;

        na = strlen(sta);
        nb = strlen(stb);

        strupr(sta);
        strlwr(stb) ;

        process() ;

    }

}

int main ()
{
}
