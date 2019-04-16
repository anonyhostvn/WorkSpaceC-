#include <bits/stdc++.h>

using namespace std ;

double pi = 3.14159 ;

double* getPointerToPi () {
    double* res = &pi ;
    return res ;
}

int main () {
    cout << getPointerToPi() << endl ;
    return 0 ;
}


