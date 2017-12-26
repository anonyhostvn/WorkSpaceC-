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

using namespace std ;


int n , a[1000001] ;
long long sum = 0 ;

int enter()
{
    scanf("%d" , &n) ;
    forinc(i,1,n) {
        scanf("%d" , &a[i]);
        sum += a[i] ;
    }
    return 0 ;
}

int process()
{
    if (sum % 2 != 0) {
        cout << "First" ;
        return 0 ;
    }
    int cnt = 0 ;
    forinc(i,1,n) if (a[i] % 2 != 0) cnt ++ ;
    if (cnt == 0) cout << "Second" ;
    else cout << "First" ;
    return 0 ;
}

int main()
{
    //freopen("841B.inp" , "r" , stdin) ;
    enter() ;
    process() ;
    return 0 ;
}
