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
#define maxN 1005
#define base 1000000009

using namespace std ;

struct Node {
    int x ; bool isFj ;
    bool operator < (const Node &other) {
        return x < other.x || ();
    }
};

int n , m , h ;

void enter() {
    cin >> n >> m >> h ;
}

int f[2 * maxN][15][15] ;

void add(int &a , int b) {
    a += b ; a %= base ;
}

void process() {
}

int main() {
    freopen("USACO673.inp" , "r" , stdin)  ;
    enter() ;
    process() ;
    return 0 ;
}

