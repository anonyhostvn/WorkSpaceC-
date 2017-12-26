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
#define ooll (long long) 1e15
#define ooit (int) 2e9

using namespace std ;

int a[10] ;

int main() {
    int X[6]= {1 , 2 , 3 , 4 , 5 , 6} ,  sum = 0 ;
    forinc(i,1,6) cin >> a[i] ;
    forinc(i,1,6) sum += a[i] ;
    do {
        int recent = 0 ;
        forinc(i,0,2) recent += a[X[i]] ;
        if (recent * 2 == sum) {
            cout << "YES" << endl ;
            return 0 ;
        }
    } while (next_permutation(X,X+6)) ;
    cout << "NO" << endl ;
    return 0 ;
}
