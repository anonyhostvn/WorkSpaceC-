#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)
#define forv(j,u) for (int j = 0 ; j < u.size() ; j++)
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define base 111539786

using namespace std ;

int n ;
struct matrix{
    long long val[2][2] ;
    matrix(){
        memset(val,0,sizeof(val)) ;
     }
     matrix operator * (const matrix &other){
         matrix res ;
         forinc(u,0,1)
         forinc(v,0,1)
         forinc(k,0,1) res.val[u][v] = (res.val[u][v] + (long long)(val[u][k] * other.val[k][v]) % base) % base ;
         return res ;
     }
};

int enter()
{
    cin >> n ;
}

matrix A , null , B;

matrix power(matrix A , int n)
{
    if (n == 0) return null ;
    if (n == 1) return A ;
    matrix tmp = power(A,n / 2) ;
    tmp = tmp * tmp   ;
    if (n % 2 == 0) return tmp ; else return tmp * A ;
}

int process()
{
    if (n <= 2) {
        cout << n  << endl ;
        return 0 ;
    }
    A.val[0][0] = 1 ; A.val[0][1] = 1 ;
    A.val[1][0] = 1 ; A.val[1][1] = 0 ;
    B.val[0][0] = 2 ; B.val[0][1] = 1 ;
    B.val[1][0] = 0 ; B.val[1][1] = 0 ;
    A = power(A,n-1) ;
    B = B * A  ;
    cout << B.val[0][1] << endl ;
}

int main()
{
    //freopen("LATGACH4.inp" , "r" , stdin) ;
    int t ; cin >> t ;
    forinc(i,1,2) null.val[i][i] = 1 ;
    forinc(i,1,t){
        enter() ;
        process() ;
    }
}
