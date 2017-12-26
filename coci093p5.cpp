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
#define ooll (long long) 1e15
#define ooit (int) 2e9
#define maxN 100005

using namespace std ;

int n , c ;

pii val[4 * maxN] ;

void update(int s , int l , int r , int  i , int k) {
    if (r < i || i < l) return ;
    if (l == r) {
        val[s].fi = k ; val[s].se = 1 ;
        return ;
    }
    int mid = (l+r) / 2 ;
}

void enter() {
    cin >> n >> c ;
    forinc(i,1,n) {
        int x ; cin >> x ; update(1,1,n,i,x) ;
    }
}

int main () {
    return 0 ;
}
