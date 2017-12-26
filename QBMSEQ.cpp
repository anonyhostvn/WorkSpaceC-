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

int n , a[10001] ;
bool dd[100000001] ;

int enter()
{
    cin >> n ;
    forinc(i,1,n) cin >> a[i] ;
}

int process()
{
    int tmp = 0 ;
    long long res = 0  , recent = 0 ;
    forinc(i,1,14141) {tmp += i ; dd[tmp] = true ; }
    if (dd[a[1]]) recent = 1 ;
    forinc(i,2,n){
        if (a[i] >= a[i-1] && dd[a[i]]) recent ++ ;
        else {
            res = max(res,recent) ;
            if (dd[a[i]]) recent = 1 ; else recent = 0 ;
        }
    }
    cout << res ;
}

int main()
{
    //freopen("QBMSEQ.inp" , "r" , stdin) ;
    enter() ;
    process() ;
}
