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

int n , k , dd[257] ;
string st ;

int main()
{
    cin >> n >> k ;
    cin >> st ;
    forinc(i,0,n-1) {
        dd[(int)st[i] - (int) 'a'] ++ ;
        if (dd[(int)st[i] - (int)'a'] > k) {
            cout << "NO" ;
            return 0 ;
        }
    }
    cout << "YES" ;
    return 0 ;
}
