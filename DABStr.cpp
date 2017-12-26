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
#define maxN 25

template <class _T> bool maximize(_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize(_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }


using namespace std ;

int n , m  ;
string s[maxN] ;

void enter() {
    cin >> n ;
    forinc(i,1,n) cin >> s[i] ;
    m = s[1].length() ;
}

int get_bit(int x , int i) {return (x >> i) & 1 ; }

int solve(int x) {
    int res = 0 , d[10] , num0 = 0 , num1 = 0 ;
    forinc(i,0,n-1) (get_bit(x,i) == 0) ? num0 ++ : num1 ++ ;

    forinc(i,0,m-1) {
        memset(d , 0 , sizeof(d)) ; int median = -1 ;
        forinc(j,0,n-1) if (get_bit(x,j) == 0) d[(int) s[j + 1][i] - (int) '0'] ++ ;
        if (d[0] >= (num0 + 1) / 2) median = 0 ;
        forinc(i,1,9) d[i] += d[i-1] , median = (d[i] >= (num0 + 1) / 2 && median == -1) ? i : median ;
        forinc(j,0,n-1) (get_bit(x,j) == 0) ? res += abs((int) s[j + 1][i] - (int) '0' - median) : 0 ;
    }

    forinc(i,0,m-1) {
        memset(d , 0 , sizeof(d)) ; int median = -1 ;
        forinc(j,0,n-1) (get_bit(x,j) == 1) ? d[(int) s[j + 1][i] - (int) '0'] ++ : 0 ;
        if (d[0] >= (num1 + 1) / 2) median = 0 ;
        forinc(i,1,9) d[i] += d[i-1] , median = (d[i] >= (num1 + 1) / 2 && median == -1) ? i : median ;
        forinc(j,0,n-1) (get_bit(x,j) == 1) ? res += abs((int) s[j + 1][i] - (int) '0' - median) : 0 ;
    }

    return res ;
}

#define maxS 1100000
vector<int> sta ;
bool dd[maxS] ;

int _not(unsigned int x) {
    x = ~ x ;
    x &= (unsigned) ((1 << n) - 1) ;
    return x ;
}

void prepare () {
    forinc(i,0,(1 << n) - 1) if (!dd[i]) dd[i] = true , dd[_not(i)] = true , sta.push_back(i)  ;
}

void process() {
    prepare() ;
    int res = ooit ;
    for (auto status : sta) minimize(res,solve(status)) ;
    cout << res << endl ;
}

int main () {
    freopen("DABStr.inp" , "r" , stdin) ;
    freopen("DABStr.out" , "w" , stdout) ;
    enter () ;
    process();
    return  0 ;
}
