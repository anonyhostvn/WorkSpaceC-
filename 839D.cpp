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
#define maxN 200000
#define maxA 1000000

using namespace std ;

int n , a[maxN+1] , p[80000] ;
int prime[maxA] ;

int estharone ()
{
    int m = 1000000 ;
    forinc(i,2,(int)sqrt(m))if (!prime[i]) {
        int j = i * i ;
        while (j <= m){
            prime[j] = i;
            j += i ;
        }
    }
    return 0 ;
}

int enter()
{
    estharone() ;
    cin >>  n ;
    forinc(i,1,n) cin >> a[i] ;
    return 0 ;
}

int process()
{

    return 0 ;
}

int main()
{
    estharone() ;
}
