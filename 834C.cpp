#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)
#define forv(j,u) for (int j = 0 ; j < u.size() ; j++)

using namespace std ;

int n , a , b , p[40001] , cnt = 0 ;
bool prime[40001] ;

int estharone ()
{
    int maxn = (int) sqrt(1000000000) ;
    forinc(i,2,(int)sqrt(maxn))
    if (!prime[i]) {
        int j = i * i  ;
        while (j <= maxn) {
            prime[j] = true ;
            j += i ;
        }
    }
    forinc(i,2,maxn) if (!prime[i]) p[++cnt] = i ;
}

int enter()
{
    estharone () ;
    cin >> n ;
    forinc(i,1,n){
        int a ,  b ;
        bool ok = true ;
        cin >> a >> b ;
        forinc(j,1,cnt) if (a % p[j] == 0 && b % p[j] == 0) {
            int ca = 0 , cb = 0 ;
            while (a % p[j] == 0) { ca ++ ; a = a / p[j] ; }
            while (b % p[j] == 0) { cb ++ ; b = b / p[j] ; }

            int ka = max(ca,cb) , kb = min(ca,cb) ;
            if (ka == 1 && kb == 1) {
                ok = false ;
                break ;
            }
            if (ka == kb && ka % 2 ==0) {
                ok = false ;
                break ;
            }
            if (ka > 2 * kb) {
                ok =  false ;
                break ;
            }
            if (2 * kb - ka == 1) {
                ok = false ;
                break ;
            }
        }
        else if ((a % p[j] == 0 && b % p[j] != 0) || (a % p[j] != 0 && b % p[j] == 0)) {ok = false ; break ; }
        if (ok)cout << "Yes" << endl ; else cout << "No" << endl ;
    }
}

int main()
{
    //freopen("834C.inp" , "r" , stdin) ;
    enter() ;
}
