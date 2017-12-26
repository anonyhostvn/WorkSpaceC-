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
#define maxN 101

using namespace std ;

int n ;
map<int,int> setmask ;
map<int,int> setgrundy ;
map<int,int> :: iterator  it ;

void enter()
{
    cin >> n ;
    forinc(i,1,n) {
        int x ; cin >> x ;
        for (int j = 2 ; j * j <= x ; j ++) if (x % j == 0) {
            int cnt = 0 ;
            while (x % j == 0) cnt ++ , x /= j ;
            setmask[j] |= (1 << (cnt-1)) ;
        }
        if (x > 1) setmask[x] |= 1 ;
    }
}

int grundy(int mask)
{
    if (setgrundy.count(mask) > 0) return setgrundy[mask] ;
    set <int> s ; s.clear() ;
    forinc(i,1,30) {
        int tmp = (mask >> i) | (mask & ((1 << (i-1)) - 1)) ;
        if (tmp != mask) s.insert(grundy(tmp)) ;
    }
    int ans = 0 ;
    while (s.count(ans) > 0) ans ++ ;
    return setgrundy[mask] = ans ;
}

void process()
{
    long long sum = 0 ;
    //for (it = setmask.begin() ; it != setmask.end() ; it++) cout << (*it).fi << " " << (*it).se << endl ;
    setgrundy[0] = 0 ;
    for (it = setmask.begin() ; it != setmask.end() ; it++) sum ^= grundy((*it).second) ;
    cout << ((sum == 0) ? "Arpa" : "Mojtaba") ;
}

int main()
{
    //freopen("850C.inp" , "r" , stdin) ;
    enter() ;
    process() ;
    return 0 ;
}
