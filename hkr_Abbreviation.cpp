#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)
#define forv(i,u) for (int j = 0 ; j < ke[u].size() ; j++)

using namespace std ;

string sta , stb ;
int na , nb , a[1001] , b[1001];
bool f[1001][1001] ;

bool islower(char ch)
{
    return ch >= 'a' && ch <= 'z' ;
}

char upcase(char ch)
{
    if (ch >= 'A' && ch <= 'Z') return ch ;
    return ch - 'a' + 'A' ;
}

int process()
{
    cin >> sta ;
    cin >> stb ;
    na = sta.length() ;
    nb = stb.length() ;

    memset(f,false,sizeof(f)) ;
    f[0][0] = true ;

    forinc(i,0,na-1)
    forinc(j,0,nb)
    if (f[i][j])
    {
        if (islower(sta[i])) f[i+1][j] = true ;
        if (i < na && j < nb && upcase(sta[i]) == stb[j]) f[i+1][j+1] = true ;
    }

    if (f[na][nb])
    {
        cout << "YES" << endl ;
        return 0 ;
    }

    cout << "NO" << endl ;
    return 0 ;
}

int main()
{
    //freopen("hkr.inp" , "r" , stdin) ;
    int q ;
    cin >> q ;
    forinc(i,1,q) process() ;

    return 0 ;
}
