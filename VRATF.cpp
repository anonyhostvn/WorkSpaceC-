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
#define base (int) 1e9 + 7

using namespace std ;

int n , k ;
queue<int> q ;

int main()
{
    cin >> n >> k ;
    q.push(n) ; int res = 0 ;
    while (!q.empty()) {
        int tmp = q.front() ; q.pop() ;
        if (tmp > k && (tmp + k) % 2 == 0) {
            q.push((tmp+k) / 2) ;
            q.push((tmp-k) / 2) ;
        } else res ++ ;
    }
    cout << res << endl ;
}
