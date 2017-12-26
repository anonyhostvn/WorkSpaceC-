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
#define maxN 100000
#define base 1000000007

using namespace std ;

int n , b[maxN+1] , t[maxN+1] ;
pii a[maxN+1] ;

int enter()
{
    cin >> n ;
    forinc(i,1,n){
        cin >> a[i].fi ;
        a[i].se = i ;
    }
    return 0 ;
}

int prepare()
{
    sort(a+1,a+1+n) ;
    int recent = 1 ; b[a[1].se] = 1 ;
    forinc(i,2,n) b[a[i].se] = (a[i] != a[i-1]) ? ++recent : recent ;
    return 0 ;
}

int update(int i , int x)
{
    while (i <= n){
        t[i] += x ; t[i] %= base ;
        i += (i) & (-i) ;
    }
}

int get(int i)
{
    int res = 0 ;
    while (i > 0){
        res += t[i] ; res %= base ;
        i -= (i) & (-i) ;
    }
    return res ;
}

int process()
{
    long long res = 1 ;
    prepare() ;
    cout << res ;
    return 0 ;
}

int main()
{
    freopen("ntseq.inp" , "r" , stdin) ;
    enter() ;
    process() ;
}
