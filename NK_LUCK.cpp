#include <bits/stdc++.h>
#define maxN 500005
#define debug(x) cerr << #x << " : " << x << endl ;

using namespace std ;

int fastRead() {
    char c ; int res = 0 ;
    for (c = getchar() ; c < '0' || c > '9' ; c = getchar()) ;
    for ( ; c >= '0' && c <= '9' ; c = getchar()) res*= 10 , res += c - '0' ;
    return res ;
}

int n , X , a[maxN] ;

void enter () {
    n = fastRead() ; X = fastRead();
    for (int i = 1 ; i <= n ; i ++) a[i] = fastRead() ;
}

struct BIT {
    int t[maxN] ;

    BIT () {
        memset(t , 0 , sizeof(t)) ;
    }

    void update(int id , int x) {
        for ( ; id <= n + 1 ; id += (id & (-id))) t[id] += x ;
    }

    int get(int id) {
        int res = 0 ;
        for ( ; id > 0 ; id -= (id & (-id))) res += t[id] ;
        return res ;
    }
};

int s[maxN] , c[maxN] , b[maxN] ;

void RR () {
    map <int , int> value ; value.clear() ;
    for (int i = 0 ; i <= n ; i ++) value[b[i]] = 0 ;
    int cnt = 0 ;
    for (auto &tmp : value) tmp.second = ++cnt ;
    for (int i = 0 ; i <= n ; i ++) b[i] = value[b[i]] ;
}

void prepareS(int x) {
    memset(s , 0 , sizeof(s)) ;
    memset(b , 0 , sizeof(b)) ;

    for (int i = 1 ; i <= n ; i ++) {
        int tmp = 0 ;
        if (a[i] < X) tmp = x ; else if (a[i] > X) tmp = -x ;
        s[i] = s[i-1] + tmp ;
    }

    for (int i = 1 ; i <= n ; i ++) c[i] = c[i-1] + (a[i] == X ? 1 : 0) ;
    for (int i = 1 ; i <= n ; i ++) b[i] = s[i] - c[i] ;
    RR() ;
}

long long solveSum (int x) {
    BIT greenTree ;
    long long res = 0 ;
    for (int i = 0 ; i <= n ; i ++) {
        res += greenTree.get(b[i] - x) ;
        greenTree.update(b[i] , 1) ;
    }

    return res ;
}

void process () {
    prepareS(1) ;
    long long notApro1 = solveSum(1) ;
    prepareS(-1) ;
    long long notApro2 = solveSum(0) ;
    long long total = (long long) n * (n+1) / 2 ,  Apro = total - notApro1 - notApro2 ;
    cout << setprecision(6) << fixed << (double) Apro / total << endl ;
}

void code () {
    enter () ;
    process () ;
}

int main () {
    #ifdef OFF_LINE
        freopen("NK_LUCK.inp" , "r" , stdin) ;
        freopen("NK_LUCK.out" , "w" , stdout) ;
    #endif // OFF_LINE
    code () ;
    return 0 ;
}
