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

using namespace std ;

struct node
{
    string sta , stb ;
    int rev ;
};

node a[400001] ;
int n ;

bool cmp (node a , node b)
{
    return (a.sta < b.sta) || ((a.sta == b.sta) && (a.stb < b.stb)) || ((a.sta == b.sta) && (a.stb == b.stb) && (a.rev < b.rev)) ;
}

map<string,int> f ;

int enter()
{
    cin >> n ;
    forinc(i,1,n) {
        string st ; cin >> st ;
        a[i].sta = a[i].sta + st[0] + st[1] ;
        cin >> st ; a[i].stb = st ;
        a[i].rev = 0 ;
    }
    forinc(i,1,n) {
        a[i+n].sta = a[i].stb ;
        a[i+n].stb = a[i].sta ;
        a[i+n].rev = 1 ;
    }
    //sort(a+1,a+1+2*n,cmp) ;
    return 0 ;
}

int process()
{
    int j = 1 ;
    long long res = 0 , id[2] ; id[0] = 0 ; id[1] = 0 ;
    id[a[1].rev] ++ ;
    forinc(i,2,2*n) {
        if (a[i].sta != a[i-1].sta || a[i].stb != a[i-1].stb) {
            if (a[i-1].sta == a[i-1].stb) res += (id[0] / 2) * (id[1] / 2) ; else res += id[0] * id[1] ;
            id[0] = 0 ; id[1] = 0 ; j = i ;
        }
        id[a[i].rev] ++ ;
    }
    //if (a[2*n].sta == a[2*n].stb) res += (id[0] / 2) * (id[1] / 2) ; else res += id[0] * id[1] ;
    cout << res / 2 ;
    return 0 ;
}

int main()
{
    freopen("citystate.in" , "r" , stdin) ;
    //freopen("citystate.out" , "w" , stdout) ;
    enter() ;
    process() ;
    return 0 ;
}
