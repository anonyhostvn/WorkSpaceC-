#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)
#define forv(j,u) for (int j = 0 ; j < u.size() ; j++)
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define mk make_pair
#define pii pair<int,int>
#define oo 1000000000

using namespace std ;

int enter()
{
    int minx = oo , miny = oo ,  maxx = -oo , maxy = -oo ;
    forinc(i,1,2) {
        int x1 , y1 , x2 , y2 ; cin >> x1 >> y1 >> x2 >> y2 ;
        minx = min(minx,min(x1,x2)) ;
        miny = min(miny,min(y1,y2)) ;
        maxx = max(maxx,max(x1,x2)) ;
        maxy = max(maxy,max(y1,y2)) ;
    }
    int d = max(maxy-miny,maxx-minx) ;
    cout << (long long) d * d ;
    return 0 ;
}

int main()
{
    freopen("square.in" , "r" , stdin) ;
    freopen("square.out" , "w" , stdout) ;
    enter() ;
    return 0 ;
}
