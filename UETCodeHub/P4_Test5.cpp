#include <bits/stdc++.h>

using namespace std ;

int main () {
    int cnt = 0 ;
    string st1 , st2 ;
    cin >> st1 >> st2 ;
    for (int i = 0 ; i < st1.length() ; i ++) if (st1[i] == st2[i]) cnt ++ ;
    cout << cnt << endl ;
    return 0 ;
}

