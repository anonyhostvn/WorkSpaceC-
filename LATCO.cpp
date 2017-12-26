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
#define oo (int) 1e9
#define maxN 105

using namespace std;

int n , k , a[maxN] , b[maxN] ;
char st[maxN] ;

void enter()
{
    scanf("%d%d", &n , &k) ;
    scanf("%s" , &st) ;
    forinc(i,0,n-1) a[i] = (int) st[i] - (int) '0' ;
    scanf("%s" , &st) ;
    forinc(i,0,n-1) b[i] = (int) st[i] - (int) '0' ;
}

int get_bit(int x , int id) {return (x >> id) & 1 ; }
int count_bit(int st) {
    int res = 0 ; forinc(i,0,k-1) res += get_bit(st,i) ;
    return res ;
}

int ax[maxN] , bx[maxN] ;

void tac_dong(int id)
{
    forinc(i,1,k) ax[(id+i-1) % n]  = 1 - ax[(id+i-1) % n] ;
}

int solve(int p , int st)
{
    int res = count_bit(st) ;
    forinc(i,0,n-1) ax[i] = a[i] ;
    forinc(i,0,n-1) bx[(p+i) % n] = b[i] ;
    forinc(i,0,k-1) if (get_bit(st,i) == 1) tac_dong(i) ;
    forinc(i,k,n-1) if (ax[i] != bx[i]) tac_dong(i) , res ++ ;
    forinc(i,0,n) if (ax[i] != bx[i]) res = oo ;
    return res ;
}

void process()
{
    int l = (1 << k) - 1 ;
    int res = oo ;
    forinc(st,0,l) forinc(i,0,n-1) res = min(res,solve(i,st)) ;
    printf("%d" , res ) ;
}

int main()
{
    freopen("LATCO.inp" , "r" , stdin) ;
    freopen("LATCO.out" , "w" , stdout) ;
    enter() ;
    process() ;
    return 0 ;
}

///11010100111101010011
///01100000110110000011
