#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)
#define forv(j,u) for (int j = 0 ; j < u.size() ; j++)
#define pb push_back
#define pf push_front
#define fi first
#define se second

using namespace std ;

int n , a[100001] , b[100001] , sp = 0 , p[4001];
bool prime[40001] ;

int estharone()
{
    int maxn = (int) sqrt(1000000000) ;
    forinc(i,2,maxn)
    if (!prime[i]){
        int j = i * i ;
        while (j <= maxn){
            prime[j] = true  ;
            j += i ;
        }
    }
    forinc(i,2,maxn) if (!prime[i]) p[++sp] = i ;
}

int enter()
{
    estharone() ;
    cin >> n ;
    forinc(i,1,n) cin >> a[i] ;
    forinc(i,1,n) cin >> b[i] ;
}

int prepare()
{
    forinc(i,1,p){
    }
}

int main()
{

}
