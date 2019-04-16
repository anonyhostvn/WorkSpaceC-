#include <bits/stdc++.h>

using namespace std ;

int main () {
    int a[505][505] , Q , n , m ;
    cin >> m >> n >> Q ;
    for (int i = 1 ; i <= m ; i ++)
        for (int j = 1 ; j <= n ; j ++) cin >> a[i][j] ;
    for (int i = 1 ; i <= Q ; i ++) {
        int x , y ;
        cin >> x >> y ;
        cout << a[x][y] << endl ;
    }
    return 0 ;
}

