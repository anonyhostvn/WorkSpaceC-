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
#define base (int) 1e9 + 7
#define maxNode 1000005

using namespace std ;

int n , nxt[maxNode][10] , snode = 1 ;
bool is_word[maxNode] ;

void reset_trie()
{
    forinc(i,1,snode) forinc(j,0,9) nxt[i][j] = 0 , is_word[i] = false ;
    snode =  1 ;
}

bool add(string st)
{
    int u = 1 , l = st.length() ;
    forinc(i,1,l) {
        int ch = (int) st[i-1] - (int) '0' ;
        if (nxt[u][ch] == 0) nxt[u][ch] = ++snode ;
        u = nxt[u][ch] ; if (i != l && is_word[u]) return false ;
    }
    is_word[u] = true ;
    return true ;
}

vector<string> a ;

bool cmp(string a , string b)
{
    return a.length() < b.length() ;
}

void enter()
{
    a.clear() ;
    cin >> n ; bool ok = true ;
    forinc(i,1,n) {
        string st ; cin >> st ;
        a.push_back(st) ;
    }
    sort(a.begin(),a.end(),cmp) ;
    forv(i,a) ok &= add(a[i]) ;
    if (!ok) cout << "NO" ; else cout << "YES" ; cout << endl ;
    reset_trie() ;
}

int main()
{
    //freopen("PHONELIST.inp" , "r" , stdin) ;
    ios_base::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    int t = 0 ; cin >> t ;
    while (t--) enter() ;
    return 0 ;
}
