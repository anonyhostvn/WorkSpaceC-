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

int n ;
map<string,int> f ;
map<string,int> :: iterator it ;

void enter()
{
    cin >> n ;
    forinc(i,1,n) {
        string st ; cin >> st ;
        f[st] ++ ;
    }
    for (it = f.begin() ; it != f.end() ; it ++) if ((*it).se % 2 != 0) {
        cout << (*it).fi ;
        return ;
    }
}

int main()
{
    //freopen("LTPMSEQ.inp" , "r" , stdin) ;
    enter() ;
    return 0 ;
}
