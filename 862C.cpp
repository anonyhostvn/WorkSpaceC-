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
#define maxN 1000001

using namespace std ;

int n , x ;
vector<int> ans ;
bool dd[maxN] ;

int getbit(int x , int i) { return (x >> i) &  1 ;}
int onbit(int x , int i) {return (1 << i) | x ;}
int offbit(int x , int i) {return x & (~(1<<i)) ; }

int ksub ()
{
    if (n == 2 && x == 0) {cout << "NO" ; return 0 ;}
    cout << "YES" << endl ;
    if (n == 1) cout << x ; else if (n == 2) cout << 0 << " " << x ;
    else cout << 0 << " " << x + (1 << 18) << " " << (1 << 18) ;
    return 0 ;
}

int enter()
{
    cin >> n >> x ;
    if (n <= 3) {ksub() ; return 0 ;}

    //ans.push_back(x) ;
    int m = n - ans.size() , sum = 0 ;
    forinc(i,(1<<19)+1,(1<<19)+m-2) {
        ans.push_back(i) ;
        sum = sum ^ i ;
    }
    cout << sum ;
    sum = offbit(sum,19) ; sum = onbit(sum,18) ; ans.push_back(sum) ;
    ans.push_back((1 << 19) | (1 << 18))  ;
    if (ans.size() == n) {
        cout << "YES" << endl ;
        forv(i,ans) cout << ans[i] << " " ;
    } else cout << "NO" ;
    return 0  ;
}

int main()
{
    freopen("862C.inp" , "r" , stdin) ;
    enter() ;
    return 0 ;
}
