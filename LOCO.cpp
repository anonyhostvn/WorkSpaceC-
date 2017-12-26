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
#define LL long long
#define ooll (long long) 1e15
#define ooit (int) 2e9

using namespace std ;

const int base = 123456789 ;
long long n  ;
int m  ;

struct matrix {
    long long val[105][105] ;
    matrix () {memset(val,0,sizeof(val)) ; }
    matrix operator * (const matrix& other) {
        matrix res ;
        forinc(i,1,m)
        forinc(j,1,m)
        forinc(k,1,m) res.val[i][j] += ((LL) val[i][k] * other.val[k][j]) , res.val[i][j] %= base ;
        return res ;
    }
} ;

void enter() {
    cin >> n >> m ;
}

matrix A , B ;

matrix POWW(matrix A, long long b)
{
    matrix C;
    for (int i = 1; i <= m; i++) C.val[i][i] = 1;
    for ( ; b; b /= 2, A = A * A)
        if (b % 2) C = C * A;
    return C ;
}

void Build_matrix() {
    forinc(i,1,m-1) B.val[i][i+1] = 1 ;
    forinc(i,1,m) B.val[m][i] = 1 ;
    A.val[m][1] = 1 ;
}

void process() {
    Build_matrix() ;
    A = POWW(B,n) * A ;
    cout << A.val[m][1] << endl ;
}

int main() {
    freopen("LOCO.inp" , "r" , stdin) ;
    freopen("LOCO.out" , "w" , stdout) ;
    enter() ;
    process()  ;
    return 0 ;
}
