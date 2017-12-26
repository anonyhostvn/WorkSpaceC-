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
#define maxN 1000

using namespace std ;

int n ;

struct matrix
{
    int val[maxN+1][maxN+1] ;
    matrix (){
        memset(val,0,sizeof(val)) ;
    }
    matrix operator * (const matrix & x){
        matrix res ;
        forinc(i,1,1)
        forinc(j,1,n)
        forinc(k,1,n) {
            res.val[i][j] += val[i][k] * x.val[k][j] ;
            res.val[i][j] %= 10 ;
        }
        return res ;
    } ;
    bool check(const matrix & x){
        forinc(i,1,n) if (val[1][i] != x.val[1][i]) return false ;
        return true ;
    }
};

matrix a[4] ;
int enter()
{
    cin >> n ;
    forinc(id,1,3){
        forinc(i,1,n){
            string st ; cin >> st ;
            forinc(j,1,n) a[id].val[i][j] = (int) st[j] - (int) '0' ;
        }
    }
    return 0 ;
}

int process()
{
    forinc(i,1,n) a[0].val[1][i] = rand() % 2 ;
    if ((a[0] * a[1]) * a[2] == a[3]) cout << "YES" ; else cout << "NO" ;
    return 0 ;
}

int main()
{

}
