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
#define maxN 105

using namespace std ;

int n , k , a[maxN] ;

void enter() {
    cin >> n >> k ;
    forinc(i,1,n) {
        char ch ; cin >> ch ;
        if (ch == 'H') a[i] = 1 ;
    }
}

void process() {
}

int main() {
    return 0 ;
}
