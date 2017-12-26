#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)
#define forv(j,u) for (int j = 0 ; j < u.size() ; j++)

using namespace std ;

int enter()
{
    char s[2] ;
    int a[2] ;
    forinc(i,0,1) {
        cin >> s[i] ;
        if (s[i] == '<') a[i] = 1 ;
        else if (s[i] == '>') a[i] = 3 ;
        else if (s[i] == '^') a[i] = 2 ;
        else a[i] = 4 ;
    }
    int n ; cin >> n ;
    if (a[0] - a[1] == -1 || a[0] - a[1] == 3) {
        if (n % 4 == 1) cout << "cw" ; else if (n % 4 == 3) cout << "ccw" ; else cout << "undefined" ;
        return 0 ;
    }
    else if(a[0] - a[1] == 1 || a[0] - a[1] == -3) {
        if (n % 4 == 1) cout << "ccw" ; else if (n % 4 == 3) cout << "cw" ; else cout << "undefined" ;
        return 0 ;
    }

    cout << "undefined" ;
}

int main()
{
    //freopen("834A.inp" , "r" , stdin) ;
    enter() ;
}
