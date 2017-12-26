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
#define maxN 101

using namespace std ;

int n , x ;
bool dd[maxN] ;

int enter()
{
    cin >> n >> x ;
    forinc(i,1,n){
        int num ; cin >> num ; dd[num] = true ;
    }
    int res = 0 ;
    forinc(i,0,x-1) if (!dd[i]) res ++;
    if (dd[x]) res ++ ;
    cout << res << endl ;
    return 0 ;
}

int main()
{
    //freopen("862A.inp" , "r" , stdin) ;
    enter() ;
    return 0 ;
}

