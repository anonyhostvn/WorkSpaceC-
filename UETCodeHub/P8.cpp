#include <bits/stdc++.h>
#define maxN 10005
//#define debug(x) {cerr << #x << " " << x << endl ; }
//#define debug1D (arr , l , r) {for (int i = l ; i <= r ; i ++) cerr << arr[i] << " " ; cout << endl ; }

using namespace std ;

int cnt['z' + 10] , require['z' + 10];
string st ;

char charMax() {
    for (char c = 'a' ; c <= 'z' ; c ++) if (require[c] > 0) return c ;
    return '!' ;
}

int pre[maxN] , f[maxN]['z' + 5] , last['z' + 5] ;

void build() {
    for (int i = 1 ; i < st.length() ; i ++) {
        pre[i] = last[st[i]] ; last[st[i]] = i ;
        for (char c = 'a' ; c <= 'z' ; c ++) f[i][c] = f[i-1][c] + (int) (c == st[i]) ;
    }
}

bool checkNeed(char TChar , int id) {
    int l = pre[id] , r = id ;
    for (char c = 'a' ; c < TChar ; c ++) if (f[r][c] - f[l-1][c] > 0) return false ;
    return true ;
}

int main () {
    string res = "" ;
    cin >> st ; st = '!' + st ;
    build() ;
    for (int i = 1 ; i < st.length() ; i ++ ) cnt[st[i]] ++ ;
    for (char c = 'a' ; c <= 'z' ; c ++) require[c] = cnt[c] / 2 ;

    for (int i = st.length() - 1 ; i > 0 ; i --) {
        if (require[st[i]] > 0 && charMax() == st[i] ) {res += st[i] ; require[st[i]] -- ; }
        else if (require[st[i]] > 0 && cnt[st[i]] == require[st[i]]) {res += st[i] ; require[st[i]] -- ; }
        else if (require[st[i]] > 0 && checkNeed(st[i] , i)) {res += st[i] ; require[st[i]] -- ; }
        cnt[st[i]] -- ;
    }
    cout << res << endl ;
    return 0 ;
}
