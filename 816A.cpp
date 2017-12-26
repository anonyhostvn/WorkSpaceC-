#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i--)

using namespace std ;

int rev(int hh)
{

    int x1 = hh / 10 , x2 = hh % 10 ;
    return x2 * 10 + x1 ;

}


bool check(int hh)
{

    return rev(hh) <= 59 ;

}

int main ()
{


    //freopen("816A.inp" , "r" , stdin) ;

    string st ;

    cin >> st ;

    int n = st.length() , cnt = 0  ;

    int zero = (int) '0' , x1 = (int) st[0] - zero , x2 = (int) st[1] - zero
        , y1 = (int) st[3] - zero , y2 = (int) st[4] - zero ;

    int hh = x1 * 10 + x2 , mm = y1 * 10 + y2 ;

    if ((check(hh)) && (rev(hh) >= mm))
    {

        cout << rev(hh) - mm ;
        return 0 ;

    }

    hh = (hh + 1) % 24 ;
    cnt = 1 ;

    while (!check(hh))
    {

        hh ++ ;
        hh %= 24 ;
        cnt ++ ;

    }

    cnt -- ;
    hh -- ;
    hh %= 24 ;

    cout << cnt * 60 + 60 - mm + rev((hh+1)%24) ;

}
