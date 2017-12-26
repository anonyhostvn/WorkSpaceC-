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

template <class _T> bool maximize(_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize(_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

const int ooit = 2e9 ;
const long long ooll = 1e15 ;


struct big_num{
    vector<int> a ;

    //big_num(int s) {a.resize(s) ; }

    void convert_to_big_num(long long x) {
        while (x > 0) {
            a.push_back(x % BASE) ;
            x /= BASE ;
        }
    }

    void print() {
        cout << a.back() ;
        fordec(i,a.size()-2,0) {
            if (a[i] < 10) cout << "000" ; else if (a[i] < 100) cout << "00" ; else if (a[i] < 1000) cout << "000" ;
            cout << a[i] ;
        }
    }

    void fix() {
        a.push_back(0) ;
        forinc(i,0,a.size() - 2) {
            a[i+1] += a[i] / BASE ; a[i] %= BASE ;
            if (a[i] < 0) a[i] += BASE , a[i+1] -- ;
        }
        while (a.size() >= 2 && a.back() == 0) a.pop_back() ;
    }

    big_num operator * (const big_num &b) {
        big_num c ;
        c.a.resize(a.size() + b.a.size()) ;
        forv(i,a) forv(j,b.a) c.a[i+j] += a[i] * b.a[j] ;
        c.fix() ; return c ;
    }

    void operator += (const big_num &b) {
        a.resize(max(a.size() , b.a.size())) ;
        forv(i,b.a) a[i] += b.a[i] ; fix() ;
    }

    bool diff_0() {
        if (a.size() != 1) return true ;
        if (a[0] > 0) return true ;
        return false ;
    }
};


big_num Power(big_num a , int n) {
    big_num res ;
    if (n == 0) return res.convert_to_big_num(1) , res ;
    if (n == 1) return a ;
    res = Power(a , n / 2) ;
    if (n % 2 == 0) return res * res ; return res * res * a ;
}

