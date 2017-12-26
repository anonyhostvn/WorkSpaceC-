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
#define maxBit 10

using namespace std ;

int n , status[maxBit] ;

int get_bit(int x , int i) {return (x >> i) & 1 ; }
int on_bit(int x , int i) {return x | (1 << i) ; }
int off_bit(int x , int i) {return x & (~(1 << i)) ; }

vector<pii> ans ;

void enter() {
    cin >> n ;
    forinc(i,1,n) {
        char bitwise ; int x ;
        cin >> bitwise >> x ;
        //cout << bitwise << endl ; forinc(i,0,9) cout << get_bit(x,i) ; cout << endl ;
        if (bitwise == '|') forinc(i,0,9) if (get_bit(x,i)) status[i] = 3 ;
        if (bitwise == '&') forinc(i,0,9) if (!get_bit(x,i)) status[i] = 2 ;
        if (bitwise == '^') forinc(i,0,9) if (get_bit(x,i)) {
            if (status[i] == 2) status[i] = 3 ; else if (status[i] == 3) status[i] = 2 ; else status[i] = 1 - status[i] ;
        }
    }
    //forinc(i,0,9) cout << status[i] ; cout << endl ;
    forinc(i,1,3) {
        int x = 0 ;
        forinc(j,0,9) if (status[j] == i) x = on_bit(x,j) ;
        if (i == 2) forinc(j,0,9) if (get_bit(x,j) == 0) x = on_bit(x,j) ; else x = off_bit(x,j) ;
        //cout << x << endl ;
        ans.push_back({i,x}) ;
    }
    cout << ans.size() << endl ;
    forv(i,ans) {
        if (ans[i].fi == 1) cout << '^' ; else if (ans[i].fi == 2) cout << '&' ; else cout << '|' ; cout << " " ;
        cout << ans[i].se << endl ;
    }
}

int main() {
    //freopen("878A.inp" , "r" , stdin) ;
    enter() ;
    return 0 ;
}
