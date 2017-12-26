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
#define maxN 10000

using namespace std ;

string st ;
int n = 0 , a[maxN+1] , nxt[maxN+1] , ts[maxN+1] , cs[maxN+1] ;

int enter()
{
    cin >> st ;
    n = st.length() ;
    forinc(i,1,n)
    if (st[i-1] == '(') {a[i] = -1 ; cs[i] = -1 ; }
    else if (st[i-1] == ')') {a[i] = -2 ; cs[i] = -1;}
    else if (st[i-1] == 'H') {a[i] = 1 ; cs[i] = 0;}
    else if (st[i-1] == 'C') {a[i] = 12 ; cs[i] = 0;}
    else if (st[i-1] == 'O') {a[i] = 16 ; cs[i] = 0;}
    else {a[i] = (int) st[i-1] - (int) '0' ; cs[i] = 1 ;}
    return 0 ;
}

int prepare()
{
    stack<int> s ;
    int trc = 0 ;
    forinc(i,1,n) ts[i] = 1 ;
    forinc(i,1,n)
    if (cs[i] == 0) trc = i ;
    else if (a[i] == -1) s.push(i) ;
    else if (a[i] == -2) {
        int id = s.top() ; s.pop() ;
        nxt[id] = i;
        trc = id ;
    }
    else if (cs[i] == 1) ts[trc] = a[i] ;
    return 0 ;
}

long long cal(int l , int r)
{
    if (l > r) return 0 ;
    if (l == r) return a[l] * ts[l] ;
    long long res = 0 , last = l ;
    forinc(i,l,r) if (i >= last) {
        if (cs[i] == 0) {res += a[i] * ts[i] ; ++ last ;}
        else if (a[i] == -1) {res += cal(i+1,nxt[i]-1) * ts[i] ; last = nxt[i] + 1 ;}
        else last ++ ;
    }
    return res ;
}

int process()
{
    prepare() ;
    cout << cal(1,n) ;
    return 0 ;
}

int main()
{
    //freopen("MMAS.inp" , "r" , stdin) ;
    enter() ;
    process() ;
}
