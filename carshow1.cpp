#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)

using namespace std ;

struct node
{

    int x,v,y ;

};

node a[100001] ;

multiset <int> s ;

multiset <int> :: iterator it ;

int n , t ;

int enter()
{

    cin >> n >> t ;

    forinc(i,1,n) cin >> a[i].x >> a[i].v ;

}


int process()
{

    forinc(i,1,n) a[i].y = a[i].x + a[i].v * t ;

    int res = 0 ;

    fordec(i,n,1)
    {

        if (a[i].y < *s.begin())
        {

            while (!s.empty()) s.erase(s.begin()) ;

            res ++ ;

        }

        s.insert(a[i].y) ;

    }

    if (!s.empty()) res ++ ;

    cout << res ;

}

int main()
{

    freopen("CARSHOW1.inp" , "r" , stdin) ;

    freopen("CARSHOW1.out" , "w" , stdout) ;

    enter() ;

    process() ;

}
