#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)
#define forv(j,u) for (int j = 0 ; j < u.size() ; j++)

using namespace std ;

int n , k , a[1000001] , last[26] ;
bool tt[26] ;

int enter()
{
    cin >> n >> k ;
    forinc(i,1,n) {
        char c ; cin >> c ;
        a[i] = (int) c - (int) 'A' ;
    }
    return 0 ;
}

int process()
{
    int cnt = 0 ;
    fordec(i,n,1) if (last[a[i]] == 0) last[a[i]] = i ;
    forinc(i,1,n){
        if (!tt[a[i]]) {
            ++ cnt ;
            tt[a[i]] = true ;
            if (cnt > k){
                cout << "YES" ;
                return 0 ;
            }
        }
        if (last[a[i]] == i) cnt -- ;
    }
    cout << "NO" ;
    return 0 ;
}

int main()
{
    //freopen("834B.inp" , "r" , stdin) ;
    enter() ;
    process() ;
    return 0 ;
}
