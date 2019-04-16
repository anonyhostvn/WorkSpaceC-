#include <bits/stdc++.h>

using namespace std ;

int main () {
    int n , a[35] , sum = 0 ;
    cin >> n ;
    for (int i = 1 ; i <= n ; i ++) {
        cin >> a[i] ;
        sum += a[i] ;
    }
    for (int i = 1 ; i <= n ; i ++) if (a[i] >= (double) sum / n) cout << a[i] << " " ;
    return 0 ;
}

