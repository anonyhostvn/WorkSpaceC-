#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)

using namespace std ;

int n , cnt , q ;
int nxt[2000001][27] , lab[2000001] ;

int addEdge(string st , int n)
{

    int recent = 1 ;

    forinc(i,0,n-1)
    {

        if (nxt[recent][(int) st[i]] > 0)
        {

            recent = nxt[recent][(int) st[i]] ;

        }

        else
        {

            cnt ++ ;

            nxt[recent][(int)st[i]] = cnt ;

            recent = cnt ;

        }

        lab[recent] ++ ;

    }


}

int string_find(string st , int n)
{


    int recent = 1 ;

    forinc(i,0,n-1)
    {

        recent = nxt[recent][(int) st[i]] ;

    }

    return lab[recent] ;

}

int enter()
{


    cin >> n ;

    cnt = 1 ;

    forinc(i,1,n)
    {

        string st ;
        cin >> st ;

        addEdge(st,st.length()) ;

    }

    cin >> q ;

    forinc(i,1,q)
    {

        string st ;

        cin >> st ;

        cout << string_find(st,st.length()) << endl ;

    }
}

int main()
{

    //freopen("dict.inp" , "r" , stdin) ;

    enter() ;


}

