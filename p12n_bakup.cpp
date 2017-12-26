
#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = b ; i >= b ; i --)
#define oo 100000000000

using namespace std ;

int n , a[9] , cnt ;
float dd[5][5][5][5][2][201] , l[6001][2][401] ;
int sh[8][8][8][8][8][8][8] ;

int enter ()
{

    cin >> n ;
    forinc(i,1,n) cin >> a[i] ;

}

//_________________________________________________________________________________________________________________
//_________________________________________________________________________________________________________________

int sub1()
{

    if ((a[1] == 1) && (a[2] == 2) && (a[3] == 3)) cout << "0.00000" ;
    else if ((a[1] == 3) && (a[2] == 1) && (a[3] == 2)) cout << "4.00000" ;
    else if ((a[1] == 1) && (a[2] == 3) && (a[3] == 2)) cout << "1.00000" ;
    else if ((a[1] == 2) && (a[2] == 1) && (a[3] == 3)) cout << "1.00000" ;
    else if ((a[1] == 2) && (a[2] == 3) && (a[3] == 1)) cout << "4.00000" ;
    else cout << "5.00000" ;

}

//_________________________________________________________________________________________________________________
//_________________________________________________________________________________________________________________

bool check(int a1 , int a2, int a3 , int a4)
{

    int b[5] ;

    b[1] = a1 ; b[2] = a2 ; b[3] = a3 ; b[4] = a4 ;

    forinc(i,1,n-1) if (b[i] > b[i+1]) return false ;
    return true ;

}

float solve(int a1 , int a2 , int a3 , int a4 ,int p , int length)
{
    if (length == 200) return 0 ;

    if (check(a1,a2,a3,a4)) return 0 ;


    if (dd[a1][a2][a3][a4][p][length] != -1) return dd[a1][a2][a3][a4][p][length] ;

    float smin = oo , sum =  0 ;
    int b[5] ;

    b[1] = a1 ; b[2] = a2 ;b[3] = a3 ; b[4] = a4 ;

    forinc(i,1,n-1)
    {

        float tmp = 0 ;

        swap(b[i],b[i+1]) ;

        tmp = solve(b[1],b[2],b[3],b[4],1-p,length+1) ;
        smin = min(smin,tmp+1) ;
        sum += tmp + 1 ;

        swap(b[i],b[i+1]) ;

    }

    if (p == 0) dd[a1][a2][a3][a4][p][length] = smin ; else dd[a1][a2][a3][a4][p][length] = sum / (n-1) ;

    if (p == 0) return smin ;
    return sum / (n-1) ;

}

int sub2 ()
{

    forinc(i1,0,n)
    forinc(i2,0,n)
    forinc(i3,0,n)
    forinc(i4,0,n)
    forinc(j,0,1)
    forinc(k,0,200) dd[i1][i2][i3][i4][j][k] = -1 ;

    cout << fixed ;
    cout << setprecision(5) << solve(a[1],a[2],a[3],a[4],0,0) ;

}

//________________________________________________________________________________________________________________
//________________________________________________________________________________________________________________

bool cek(int a1 , int a2 , int a3 , int a4 , int a5 , int a6 , int a7)
{

    int b[8] ;

    b[1] = a1 ; b[2] = a2 ; b[3] = a3 ; b[4] = a4 ;b[5] = a5 ; b[6] = a6 ; b[7] = a7 ;

    forinc(i,1,n-1) if (b[i] > b[i+1]) return false ;
    return true ;

}

int getsh(int a1 , int a2 , int a3 , int a4 , int a5 , int a6 , int a7)
{

    if (sh[a1][a2][a3][a4][a5][a6][a7] == -1)
    {

        cnt ++ ;
        sh[a1][a2][a3][a4][a5][a6][a7] = cnt ;

    }

    return sh[a1][a2][a3][a4][a5][a6][a7] ;

}

float bt(int a1 , int a2 , int a3 , int a4 , int a5 , int a6 , int a7 , int p,int length)
{

    int shhv = getsh(a1,a2,a3,a4,a5,a6,a7) ;

    if (length == 400) return 0 ;

    if (cek(a1,a2,a3,a4,a5,a6,a7)) return 0 ;

    if (l[shhv][p][length] != -1) return l[shhv][p][length] ;

    float smin = oo , sum = 0 ;

    int b[8] ;

    b[1] = a1 ; b[2] = a2 ; b[3] = a3 ; b[4] = a4 ;b[5] = a5 ; b[6] = a6 ; b[7] = a7 ;

    forinc(i,1,n-1)
    {

        float tmp = 0 ;

        swap(b[i],b[i+1]) ;

        tmp = bt(b[1],b[2],b[3],b[4],b[5],b[6],b[7],1-p,length+1) ;
        smin = min(smin,tmp+1) ;
        sum += tmp + 1 ;

        swap(b[i],b[i+1]) ;

    }

    if (p == 0) l[shhv][p][length] = smin ; else l[shhv][p][length] = sum / (n-1) ;

    return l[shhv][p][length] ;

}

int sub3 ()
{

    cnt = 0 ;

    forinc(i1,1,7)
    forinc(i2,1,7)
    forinc(i3,1,7)
    forinc(i4,1,7)
    forinc(i5,1,7)
    forinc(i6,1,7)
    forinc(i7,1,7) sh[i1][i2][i3][i4][i5][i6][i7] = -1 ;

    forinc(i,0,6000)
    forinc(j,0,1)
    forinc(k,0,400) l[i][j][k] = -1 ;

    cout << fixed ;
    cout << setprecision(5) << bt(a[1],a[2],a[3],a[4],a[5],a[6],a[7],0,0) ;

}

//__________________________________________________________________________________________________________________
//__________________________________________________________________________________________________________________

int divsub()
{

    if (n == 3) sub1() ;
    else if (n == 4) sub2() ;
    else if (n == 7) sub3() ;

}

int main ()
{

    freopen("p12n.inp" , "r" , stdin) ;
    freopen("p12n.out" , "w" , stdout) ;

    enter () ;
    divsub() ;

}
