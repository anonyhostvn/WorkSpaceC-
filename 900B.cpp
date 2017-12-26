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

template <class _T> bool maximize(_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize(_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

const int ooit = 2e9 ;
const long long ooll = 1e15 ;

using namespace std ;

const int base = 1e9 ;

#define maxN 100005

int a , b , c ;
bool prime[maxN] ;
vector<int> p ;

int Estharone(int n) {
    forinc(i,2,(int) sqrt(n)) if (!prime[i]) {
        for (int j = i * i ; j <= n ; j += i) prime[j] = true ;
    }

    forinc(i,2,n) if (!prime[i]) p.push_back(i) ;
}

int main () {
    cin >> a >> b >> c ;

    long double d = (double) a / b ;

    forinc(i,1,1000000) {
        if ((long long) (d * (long double) 10) % 10 == c) { cout << i ; return 0 ; }
        d *= (long double) 10 ; d -= (long long) d ;
    }
    return 0 ;
}
