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
#define maxN 55

using namespace std ;

int n , k , d , b[maxN] ;

struct matrix{
    int val[maxN][maxN] ;
    matrix operator * (const matrix &other) {
        matrix res ;
        forinc(i,1,d) forinc(j,1,d) {
            res.val[j][i] = 0 ;
            forinc(k,1,d) res.val[j][i] += val[k][i] * other.val[j][k] ;
            res.val[j][i] %= 3 ; res.val[j][i] += 3 ; res.val[j][i]%=3 ;
        }
        return res ;
    }
};

matrix sa , sb;

void enter()
{
    cin >> n >> d ;
    forinc(i,1,d) cin >> b[i] ;
    forinc(i,1,d) if (b[i] == -1) b[i] = 0 ;
}

void build_matrix()
{
    int j = 2 ;
    forinc(i,1,d-1) sb.val[i][i+1] = 1 ;
    forinc(i,1,d) sb.val[d][i] = -1 ; sb.val[d][1] = 1 ;
}

void print(matrix sb)
{
    forinc(i,1,d) { forinc(j,1,d) cout << sb.val[i][j] ; cout << endl ; }
}

matrix power(matrix a , int x)
{
    if (x == 1) return a ;
    matrix tmp = power(a,x/2) ;
    if (x % 2 == 0) return tmp * tmp ;
    return tmp * tmp * a;
}

void process()
{
    build_matrix() ;
    forinc(i,1,d) sa.val[i][1] = b[d-i+1] ;
    //print(sa) ; cout << endl ; print(sb) ; cout << endl ;
    //print(sa*power(sb,n-1)) ;
    matrix res = sa * power(sb,n-1) ;
    fordec(i,d,1) cout << res.val[i][1] << " " ; cout << endl ;
}

int main()
{
    freopen("RECURR.inp" , "r" , stdin) ;
    freopen("RECURR.out" , "w" , stdout) ;
    cin >> k ;
    while (k --) { enter() ; process() ;}
    return 0 ;
}
