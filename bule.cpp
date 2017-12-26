#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)


using namespace std ;

int n , h , k , f[500003][32] , g[500003][32] , t[103][103]  ;
int base = 666013 ;

struct matrix
{
    int val[103][103];
    matrix()
    {
        memset(val, 0, sizeof(val));
    }

    matrix operator * ( const matrix & x)
    {
        matrix res;
        for (int u = 1; u <= h+1; u++)
            for (int v = 1; v <= h+1; v++)
                for (int i = 1; i <= h+1 ; i++)
                    res.val[u][v] = (((long long)val[u][i] * x.val[i][v]) % base + res.val[u][v] ) % base;
        return res;
    }
};

matrix a,matrix_root ;

matrix matrixPow(matrix mt , long long n)
{

    if (n == 1) return mt ;

    if (n == 0) return matrix_root ;

    matrix tmp = matrixPow(mt,n / 2) ;

    if (n % 2 == 0) return tmp * tmp ;
    return tmp * tmp * mt ;

}

int enter ()
{

    cin >> n >> h >> k ;

}

int sub1()
{

    f[1][0] = 1 ;

    forinc(i,1,n-2)
    forinc(j,0,h)
    if (f[i][j] != 0)
    {

        if (i < n-2)
        {

        forinc(t,0,h) if (abs(j-t) <= k)
            f[i+1][t] =  (f[i+1][t] + f[i][j]) % base ;
        }

        else
        {

        forinc(t,0,h) if ((abs(t-j) <= k) && (abs(h-t) <= k))
            f[i+1][t] = (f[i+1][t] + f[i][j]) % base ;

        }

    }

    int res = 0 ;

    forinc(j,0,h) res =  (res + f[n-1][j]) % base ;
    cout << res ;

}

int print_matrix(matrix a)
{

    forinc(i,1,h+1)
    {

        forinc(j,1,h+1) cout << a.val[i][j] << " " ;

        cout << endl ;

    }

}

int sub2()
{

    f[1][1] = 1 ;
    g[1][1] = 1 ;
    forinc(i,2,h+1) g[1][i] = (g[1][i-1] + f[1][i]) % base ;

    forinc(i,2,n-1)
    forinc(j,1,h+1)
    {

        int tt = min(j+k,h+1) , tt2 = max(1,j-k) ;

        if (i < n-1)

            f[i][j] = ((g[i-1][tt] - g[i-1][tt2-1]) % base + base) % base ;

        else

        {

            if (h+1-j <= k)
            {

                f[i][j] = ((g[i-1][tt] - g[i-1][tt2-1]) % base  + base ) % base ;

            }

        }

        g[i][j] = (g[i][j-1] + f[i][j]) % base ;

    }

    int res = 0 ;

    forinc(i,1,h+1) res = (res + f[n-1][i]) % base ;

    cout << res ;

}

int sub3 ()
{


    cout << base * base ;
    matrix b ;

    forinc(i,1,h+1) matrix_root.val[i][i] = 1 ;

    forinc(i,1,h+1)
    forinc(j,max(1,i-k),min(i+k,h+1)) a.val[i][j] = 1 ;

    b.val[1][1] = 1 ;

    //matrix tmp = matrixPow(a,n-1) * b ;

    //cout << tmp.val[h+1][1] ;

}

int dsub()
{

    if (n <= 200000) sub1() ; else sub2 ();

}

int main ()
{

    freopen("SUPERSEQ.inp" , "r" , stdin) ;
    //freopen("SUPERSEQ.out" , "w" , stdout) ;

    enter() ;
    sub3() ;

}
