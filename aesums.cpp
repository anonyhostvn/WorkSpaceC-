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
#define maxN 500001

using namespace std ;

int n , a[maxN] , pos1 = 0 , pos2 = 0  , q = 0 ;
long long sum = 0 , sabs[maxN]  ;

void enter()
{
    cin >> n ;
    forinc(i,1,n) cin >> a[i] ; cin >> q ;
    sort(a+1,a+1+n) ;
}

int tfind(int add)
{
    int l = 1 , r = n , res = 0 ;
    while (l <= r) {
        int mid = (l+r) / 2 ;
        if (a[mid] + add >= 0) r = mid - 1 , res = mid ; else l = mid + 1 ;
    }
    return res ;
}

void prepare()
{
    forinc(i,1,n) sum += abs(a[i]) , sabs[i] = sabs[i-1] + abs(a[i]) ;
    int l = 1 , r =  n ;
    while (l <= r) {
        int mid = (l+r) / 2 ;
        if (a[mid] < 0) pos2 = mid , l = mid + 1 ; else r = mid - 1 ;
    } l = 1 ; r = n ;
    while (l <= r) {
        int mid = (l+r) / 2 ;
        if (a[mid] >= 0) pos1 = mid , r = mid - 1 ; else l = mid + 1 ;
    }
}

long long solve(int leg_1 , int reg_1 , int leg_2 , int reg_2 , int leg_3 , int reg_3 , int sup , long long tmp)
{
    long long res = sum ;
    if (reg_1 >= leg_1) res -= (long long) tmp * (reg_1 - leg_1 + 1) ;
    if (reg_3 >= leg_3) res += (long long) tmp * (reg_3 - leg_3 + 1) ;
    if (reg_2 >= leg_2) {
        res -= (long long) 2 *  (sabs[reg_2]  - sabs[leg_2-1]) ;
        res += (long long) abs(tmp) * (reg_2 - leg_2 + 1) ;
    }
    return res ;
}

void process()
{
    prepare() ;
    long long tmp = 0 ;
    while (q--) {
        int x ; cin >> x ; tmp += x ;
        int id = tfind(tmp) ;
        if (tmp > 0) cout << solve(1,id-1,id,pos2,pos1,n,1,tmp) ; else cout << solve(1,pos2,pos1,id-1,id,n,-1,tmp) ;
        cout << endl ;
    }
}

int main()
{
    //freopen("aesums.inp" , "r" , stdin) ;
    enter() ;
    process() ;
    return 0 ;
}
