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
#define oo (int) 1e8
#define maxN 505

using namespace std ;

struct node{
    int  score ;
    string sub ;
};
node a[maxN] ;
int n ;

void enter()
{
    cin >> n ;
    forinc(i,1,n) cin >> a[i].sub >> a[i].score ;
}

string X[5] = {"A" , "A1" , "B" , "C" , "D"} ;
map<string,int> id  ;
bool cmp(node a , node b) {return (id[a.sub] < id[b.sub]) || (id[a.sub] == id[b.sub] && a.score < b.score) ; }

int get_bit(int x , int i) {return (x >> i) & 1 ; }

node b[maxN] ;

void solve(int st)
{
    forinc(i,1,n) b[i] = a[i] ;
    forinc(i,1,n) if (get_bit(st,id[b[i].sub]) == 1) b[i].score = oo - b[i].score ;
    sort(b+1,b+1+n,cmp) ;
}

void process()
{
    do {
        forinc(i,0,4) id[X[i]] = i ;
        int l = (1 << 5) - 1 ;
        forinc(i,0,l) solve(l) ;
    } while (next_permutation(X,X+5)) ;
}

int main()
{
    freopen("degree.inp" , "r" , stdin) ;
    freopen("degree.out" , "w" , stdout) ;
    enter() ;
    process() ;
    return 0 ;
}
