#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i--)

using namespace std ;

#define maxN 1000005
int n , a[maxN] , s[maxN] , f[1005][1005] ;

int g[5] = {2 , 3 , 5 , 7 , 11} ;

int main()
{
    srand(time(nullptr));
    freopen("Test.inp" , "w" , stdout) ;
    int n = 20 , t = 100 ; long long base = 1000000000000000000 ;
    cout << n << endl ;
    forinc(i,1,n) {
        //cout << (base + (long long) rand()) % (long long) base  << " " << (base + (long long) rand()) % (long long) base << endl ;
        //cout << rand()  << " " << rand () << endl ;
        cout << rand() % 200 + 1 << " " ;
    }

    cout << endl ;

    forinc(i,1,n) cout << rand() % 200 + 1 << " " ; cout << endl ;

    return 0 ;
}
