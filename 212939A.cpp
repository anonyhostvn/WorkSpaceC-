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
#define maxN 100005

using namespace std ;
const int base =14062008 ;

int n , k ;
long long f[maxN] ;
bool broke[maxN] ;

void enter() {
    cin >> n >> k ;
    forinc(i,1,k) {
        int x ; cin >> x ; broke[x] = true ;
    }
}

void process () {
    f[1] = 1 ;
    forinc(i,1,n) if (f[i] > 0) {
        if (!broke[i+1]) f[i+1] += f[i] , f[i+1] %= base ;
        if (!broke[i+2]) f[i+2] += f[i] , f[i+2] %= base ;
    }
    cout << f[n] << endl ;
}
int main() {
    //freopen("Test.inp" , "r" , stdin) ;
    enter() ;
    process() ;
    return 0 ;
}
