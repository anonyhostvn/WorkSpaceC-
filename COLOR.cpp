#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)
#define forv(j,u) for (int j = 0 ; j < u.size() ; j++)
#define fi first
#define se second
#define pii pair<int,int>
#define pli pair<long long , int>

template <class _T> bool maximize(_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize(_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

const int ooit = 2e9 ;
const long long ooll = 1e15 ;
const int base = 1000000007 ;

using namespace std ;

int S , a[10][15] ;

void enter () {
    cin >> S ;
    forinc(i,1,5) forinc(j,1,10) {
        char c ; cin >> c ; a[i][j] = (int) c - (int) '0' ;
    }
}

int power[55] , count_[15] ;

void prepare () {
    power[0] = 1 ;
    forinc(i,1,50) power[i] = power[i-1] * 2 , power[i] %= base ;

    int cnt = 0 ;
    forinc(i,10,1) {
        forinc(j,1,5) cnt += (a[j][i] == 0) ;
        count_[i] = cnt ;
    }
}

int max_rect (int s1 ,int s2 ,int s3 ,int s4 ,int s5) {
    int h[5] = {s1 , s2 , s3 , s4 ,s5} ;
    int minH = ooit , Tfirst = -1 , res = 0 ;
    forinc(i,0,4) if (h[i] == 0) {
        if (minH < ooit) maximize(res , minH * (i - Tfirst)) ;
        minH = ooit ; Tfirst = -1 ;
    } else Tfirst = (Tfirst == -1) ? i : Tfirst , minimize(minH , h[i]) ;


    return res ;
}

int f[15][10][6][6][6][6][6] ;

void update(int i , int j , int s1 , int s2 , int s3 , int s4 , int s5 , int x) {
    f[i][j][s1][s2][s3][s4][s5] += x ;
    f[i][j][s1][s2][s3][s4][s5] %= base ;
}

void process () {
    prepare () ;

    f[0][5][0][0][0][0][0] = 1 ;

    long long res = 0 ;
    forinc(i,0,10) forinc(j,1,5)
        forinc(s1,0,5) forinc(s2,0,5) forinc(s3,0,5) forinc(s4,0,5) forinc(s5,0,5) if (f[i][j][s1][s2][s3][s4][s5] > 0) {
            int recent = f[i][j][s1][s2][s3][s4][s5] , h[6] = {0 , s1 , s2 , s3 , s4 , s5};
            if (j == 5) {
                int rec_s = max_rect(s1,s2,s3,s4,s5) , ts[6] ; forinc(t , 1 , 5) ts[i] = (!a[t][j+1]) ? h[t] + 1 : 0 ;

                if (rec_s < S) {
                    update(i + 1 , 1 , ts[1] , ts[2] , ts[3] , ts[4] , ts[5] , recent);
                    if (ts[1]) update(i + 1 , 1 , 0 , ts[2] , ts[3] , ts[4] , ts[5] , recent) ;
                } else if (rec_s == S) res += (long long) recent * power[count_[i+1]] , res %= base ;
            }

            else {
                update(i , j + 1 , h[1] , h[2] , h[3] , h[4] , h[5] ,recent) ;
                if (h[j+1]) {
                    int ts[6] ; forinc(i,1,5) if (i != j + 1) ts[i] = h[i] ; else ts[i] = 0 ;
                    update(i , j + 1 , ts[1] , ts[2] , ts[3] , ts[4] , ts[5] , recent) ;
                }
            }
        }

    cout << res << endl ;
}

int main () {
    return 0 ;
}
