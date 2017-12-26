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

int m , a[200001] , b[200001] , c[200001] ;

int enter()
{
    cin >> m ;
    forinc(i,1,m) cin >> a[i] ;
    forinc(i,1,m) cin >> b[i] ;
    return 0 ;
}

priority_queue<pii> qb ;
priority_queue<int> qa ;

int process()
{
    forinc(i,1,m) {
        qa.push(a[i]) ; qb.push(mk(-b[i],i)) ;
    }
    forinc(i,1,m) {
        int sa = qa.top() ; qa.pop() ;
        pii sb = qb.top() ; qb.pop() ;
        c[sb.se] = sa ;
    }
    forinc(i,1,m) cout << c[i] << " " ;
    return 0 ;
}

int main()
{
    //freopen("841C.inp" , "r" , stdin) ;
    enter() ;
    process() ;
    return 0 ;
}
