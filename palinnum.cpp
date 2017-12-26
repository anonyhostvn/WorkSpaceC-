#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)
#define forv(i,u) for (int j = 0 ; j < ke[u].size() ; j++)

using namespace std ;

int n , k ;
string st ;

int enter()
{
    cin >> n >> k ;
    cin >> st ;
}

int check()
{
    int i = 0 , j = n-1  ,res = 0;

    while (i <= j)
    {
        if (st[i] != st[j]) res++ ;
        i++ ; j-- ;
    }

    return res ;
}

int process()
{
    int i = 0 , j = n - 1 ;

    int b = k - check() ;

    if (b < 0)
    {
        cout << -1 ;
        return 0 ;
    }

    while (i <= j)
    {
        if (i == j && b >= 1)
        {
            st[i] = '9' ;
            b-- ;
        }
        else
        {
            if (st[i] == st[j] && st[i] != '9' && b >= 2)
            {
                st[i] = '9' ;
                st[j] = '9' ;
                b -= 2 ;
            }
            else if (st[i] != st[j])
            {
                int cost = (int) (st[i] != '9') + (int) (st[j] != '9') ;

                if (cost == 2 && b >= 1)
                {
                    st[i] = '9' ;
                    st[j] = '9' ;
                    b-- ;
                }
                else
                {
                    char tmp = max(st[i],st[j]) ;
                    st[i] = tmp ;
                    st[j] = tmp ;
                }
            }
        }

        if (st[i] != st[j])
        {
            cout << -1 ;
            //cout << st[i] << "  " << st[j] << " " << k;
            return 0 ;
        }

        i++ ; j -- ;
    }

    cout << st ;
}

int main()
{
    freopen("palinnum.inp" , "r" , stdin) ;
    freopen("palinnum.out" , "w" , stdout) ;

    enter()  ;
    process()  ;
}
