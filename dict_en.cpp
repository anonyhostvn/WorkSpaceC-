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
#define maxNode 1000000

using namespace std ;

int n , nxt[maxNode][27] , snode = 1 , q ;
bool is_word[maxNode] ;

void add(string st)
{
    int u = 1 , n = st.size() ;
    forinc(i,1,n) {
        int ch = (int) st[i-1] - (int) 'a' ;
        nxt[u][ch] = (nxt[u][ch] == 0) ? ++snode : nxt[u][ch] ;
        u = nxt[u][ch] ;
    }
    is_word[u] = true ;
}

void enter()
{
    cin >> n ;
    forinc(i,1,n) {
        string st ; cin >> st ; add(st) ;
    }
}

vector<int> a ;

void print(vector<int> a)
{
    forv(i,a) cout << (char) (a[i] + (int) 'a') ; cout << endl ;
}

void dfs(int u , int root)
{
    if (u != root && is_word[u]) print(a) ;
    forinc(i,0,25) if (nxt[u][i] != 0) {
        a.push_back(i) ;
        dfs(nxt[u][i],root) ;
        a.pop_back() ;
    }
}

bool look_up(string st)
{
    int u = 1 , l = st.length() ;
    forinc(i,1,l) {
        int ch = (int) st[i-1] - (int) 'a' ;
        if (nxt[u][ch] == 0) return false ;
        u = nxt[u][ch] ;
    }
    a.clear() ; forinc(i,0,l-1) a.push_back((int) st[i] - (int) 'a') ;
    dfs(u,u) ;
    return true ;
}

void process()
{
    cin >> q ;
    forinc(i,1,q) {
        cout << "Case #" << i << ":" << endl ;
        string st ; cin >> st ;
        if (!look_up(st)) cout << "No match." << endl ;
    }
}

int main()
{
    //freopen("dict_en.inp" , "r" , stdin) ;
    ios_base::sync_with_stdio(false) ;
    cin.tie(0) ; cout.tie(0) ;
    enter() ;
    process() ;
    return 0 ;
}
