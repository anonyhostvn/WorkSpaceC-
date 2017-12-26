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

using namespace std ;

int n , k ;
vector<pii> customer[2] ;

void enter() {
    cin >> n >> k ;
    forinc(i,1,n) {
        int x , m ; cin >> x >> m ;
        if (x < 0) customer[0].push_back({-x,m}) ; else customer[1].push_back({x,m}) ;
    }
    sort(customer[0].begin(),customer[0].end()) ;
    sort(customer[1].begin(),customer[1].end()) ;
}

void process() {
    long long res = 0 ;
    forinc(i,0,1) while (!customer[i].empty()) {
        int parcel = customer[i].back().se , pos = customer[i].back().fi ;
        customer[i].pop_back() ;
        if (parcel % k == 0) res += (long long) 2 * pos * (parcel / k) ; else {
            res += (long long) 2 * pos * (parcel / k + 1) ;
            int s = parcel % k ;
            while (s > 0 && !customer[i].empty()) {
                if (s <= customer[i].back().se) s = 0 , customer[i].back().se -= s ; else s -= customer[i].back().se , customer[i].back().se = 0 ;
                if (customer[i].back().se == 0) customer[i].pop_back() ;
            }
        }
    }
    cout << res << endl ;
}

int main() {
    freopen("POSTMAN.inp" , "r" , stdin) ;
    freopen("POSTMAN.out" , "w" , stdout) ;
    enter() ;
    process() ;
    return 0 ;
}
