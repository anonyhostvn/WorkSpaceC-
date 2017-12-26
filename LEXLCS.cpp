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
#define ooll (long long) 1e15
#define ooit (int) 2e9
#define maxN 2005

template <class _T> bool maximize(_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize(_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

using namespace std ;

int na , nb , a[maxN] , b[maxN] ;
string sta , stb ;

/*_________________________________________________________________________________________________________________________________________________________________________________
                                                Input
___________________________________________________________________________________________________________________________________________________________________________________*/


void enter() {
    cin >> sta ;
    cin >> stb ;
    na = sta.length()  ; nb = stb.length() ;
    forinc(i,1,na) a[i] = (int) sta[i-1] - (int) 'a' ;
    forinc(i,1,nb) b[i] = (int) stb[i-1] - (int) 'a' ;
}

int nxt_a[maxN][27] , nxt_b[maxN][27] , last[27] ;

/*_________________________________________________________________________________________________________________________________________________________________________________
                                                        Prepare
___________________________________________________________________________________________________________________________________________________________________________________*/


void build_() {
    memset(last , 0 , sizeof(last)) ; last[26] = na + 1 ;
    fordec(i , na , 0) {
        forinc(j , 0 , 26) nxt_a[i][j] = last[j] ;
        last[a[i]] = i ;
    }

    memset(last , 0 , sizeof(last)) ; last[26] = nb + 1 ;
    fordec(i , nb , 0 )  {
        forinc(j , 0 , 26) nxt_b[i][j] =last[j]  ;
        last[b[i]] = i ;
    }
}

/*_________________________________________________________________________________________________________________________________________________________________________________
                                                                query _ 1
___________________________________________________________________________________________________________________________________________________________________________________*/

int f[maxN][maxN]  , tip[maxN][maxN] ;
pii trace[maxN][maxN] ;

int cal(int i , int j) {
    if (f[i][j] > -1) return f[i][j] ;
    if (i > na || j > nb) { f[i][j] = 0 ; return 0 ; }
    int res = -1 ;
    fordec(ch,26,0) {
        int u = nxt_a[i][ch] , v = nxt_b[j][ch] ;
        if (u > 0 && v > 0 && maximize(res,cal(u,v))) tip[i][j] = ch , trace[i][j] = {u,v} ;
    }
    f[i][j] = res + 1 ;
    return f[i][j] ;
}

/*_________________________________________________________________________________________________________________________________________________________________________________
                                                                    query _ 2
___________________________________________________________________________________________________________________________________________________________________________________*/


int g[maxN][maxN] ;

int cal__(int i , int j) {
    if (g[i][j] > -1) return g[i][j] ;
    if (i == na && j == nb) {g[i][j] = 0 ; return 0 ; }
    int res = ooit ;
    if (i == na) res = cal__(i,j + 1) ;  else if (j == nb) res = cal__(i + 1,j) ;
    else {
        if (a[i+1] == b[j+1]) res = cal__(i + 1 , j + 1) ;
        else res = min(cal__(i+1,j) , cal__(i,j+1)) ;
    }

    g[i][j] = res + 1 ;
    return res + 1 ;
}

/*_________________________________________________________________________________________________________________________________________________________________________________
                                                                trace
___________________________________________________________________________________________________________________________________________________________________________________*/


vector<int> ans , ans_2 ;

void _ (int i , int j) {
    if (i > na || j > nb) return ;
    if (tip[i][j] < 26) ans.push_back(tip[i][j]) ;
    int u = trace[i][j].fi , v = trace[i][j].se ;
    _(trace[i][j].fi , trace[i][j].se) ;
}

void __(int i , int j) {
    if (i == na && j == nb) return ;
    if (i == na)  ans_2.push_back(b[j+1])  , __(i , j + 1) ;   else if (j == nb)  ans_2.push_back(a[i+1]) , __(i + 1 , j) ;
    else {
        if (a[i+1] == b[j+1]) ans_2.push_back(a[i+1]) , __(i + 1 , j + 1) ;
        else {
            if (g[i+1][j] < g[i][j+1]) ans_2.push_back(a[i+1]) , __(i + 1 , j) ;
            else if (g[i+1][j] > g[i][j+1]) ans_2.push_back(b[j+1]) , __(i , j + 1) ;
            else if (g[i+1][j] == g[i][j+1]) {
                if (a[i+1] < b[j + 1]) ans_2.push_back(a[i+1]) , __(i + 1 , j) ;
                else ans_2.push_back(b[j+1]) , __(i , j + 1) ;
            }
        }
    }
}

void print_query_1(vector<int> ans) { forv(i,ans) cout << (char) (ans[i] + (int) 'a') ; cout << endl ; }

/*_________________________________________________________________________________________________________________________________________________________________________________
                                                                PROCESS
___________________________________________________________________________________________________________________________________________________________________________________*/


void process () {
    build_()  ;
    forinc(i,0,na) forinc(j,0,nb) f[i][j] = -1 ;
    forinc(i,0,na) forinc(j,0,nb) g[i][j] = -1 ;

    cal(0,0) ;
    _(0,0) ;

    cal__(0,0) ;
    __(0,0) ;

    print_query_1(ans) ;
    print_query_1(ans_2) ;
}

int main() {
    freopen("LEXLCS.inp" , "r" , stdin) ;
    freopen("LEXLCS.out" , "w" , stdout) ;
    enter() ;
    process() ;
    return 0 ;
}
