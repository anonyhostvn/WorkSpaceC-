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
#define oo (long long) 1e15
#define maxN 30

using namespace std ;

int n , m ,s , a[1000005] , rem_col[50005] , rem_row[50005] ;

void enter()
{
    scanf("%d%d%d" , &m , &n , &s)  ;
    forinc(i,1,m) forinc(j,1,n) scanf("%d" , &a[(i-1) *n + j]) ;
}

void process()
{
    forinc(i,1,s) {
        int x = 0 ; scanf("%d" , &x) ;
        if (x <= m) rem_row[x] ++ ; else { x-=m ; rem_col[x] ++ ; }
    }
    int res =0 ;
    forinc(i,1,m) forinc(j,1,n) if ((a[(i-1) * n + j] + rem_row[i] + rem_col[j]) % 3 == 0) res ++ ;
    printf("%d" , res);
}

int main()
{
    freopen("LISYS.inp" , "r" , stdin) ;
    freopen("LISYS.out" , "w" , stdout) ;
    enter() ;
    process() ;
    return 0 ;
}
