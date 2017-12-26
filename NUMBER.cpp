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
#define maxN 1000005

template <class _T> bool maximize(_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize(_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

using namespace std ;

int n , a[maxN] ;
string st ;

void enter() {
    cin >> st ;
    n = st.length() ;
    forinc(i,1,n) a[i] = (int) st[i-1] - (int) '0' ;
}

int start_block[maxN] ,cnt_block = 0 ;
bool dd[10] ;

void make_dd(int l , int r) {
    //forinc(i,0,9) dd[i] = false ;
    memset(dd , false , sizeof(dd)) ;
    forinc(i,l,r) dd[a[i]] = true ;
}

void make_block() {
    int diff_num = 0 ; start_block[0] = n + 1 ;
    fordec(i,n,1) {
        (!dd[a[i]]) ? dd[a[i]] = true , diff_num ++ : 0 ;
        if (diff_num == 10) start_block[++cnt_block] = i , diff_num = 0 , memset(dd , 0 , sizeof(dd)) ;
    }
    if (diff_num > 0) start_block[++cnt_block] = 1 ;
}

vector<int> ans ;

void process () {
    ans.clear() ;
    make_block() ;

    int last_num = -1 , tf = cnt_block - 1   , diff_num = 0 ;

    make_dd(1,start_block[cnt_block-1]-1) ;
    forinc(i,1,9) diff_num += (int) (dd[i]) ;

    int k = 0 , tfi = 1 ;
    if (diff_num == 9) {
        ans.push_back(1) ;
        forinc(i,1,start_block[cnt_block-1] - 1) if (a[i] == 1) {k = i ; break ; }
        tfi = 0 ;
    }

    make_dd(k + 1 , start_block[cnt_block-1] - 1) ;
    forinc(i,tfi,9) if (!dd[i]) {last_num = i ; break ; }
    ans.push_back(last_num) ;

    fordec(b,tf,1) {
        int k = 0 ; forinc(i,start_block[b],start_block[b-1]-1) if (a[i] == last_num) { k = i ; break ; }
        make_dd(k+1,start_block[b-1] - 1) ;
        forinc(i,0,9) if (!dd[i]) {last_num = i ; break ;}
        ans.push_back(last_num) ;
    }

    for (int tmp : ans) printf("%d" , tmp) ;
}

int main () {
    freopen("NUMBER.inp" , "r" , stdin) ;
    freopen("NUMBER.out" , "w",  stdout) ;
    enter () ;
    process () ;
    return 0 ;
}
