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
#define maxN 1000000
#define oo 2000000000

using namespace std ;

int n , side[4] , lab[maxN+1];
pii coor[maxN+1] ;

int enter()
{
    //cin >> n ;
    scanf("%d" , &n) ;
    forinc(i,1,n){
        int u , v ; //cin >> u >> v ;
        scanf("%d %d" , &u , &v) ;
        coor[i].fi = u - v ; coor[i].se = u + v ;
    }
    return 0 ;
}

int findtop()
{
    int tmp = oo , res = 0 ;
    forinc(i,1,n) if (tmp > coor[i].fi) {
        tmp = coor[i].fi ;
        res = i ;
    }
    side[0] = res ;
    return 0 ;
}

int findbot()
{
    int tmp = -oo , res = 0 ;
    forinc(i,1,n) if (tmp < coor[i].fi){
        tmp = coor[i].fi ;
        res = i ;
    }
    side[1] = res ;
    return 0 ;
}

int findleft()
{
    int tmp = oo , res = 0 ;
    forinc(i,1,n) if (tmp > coor[i].se){
        tmp = coor[i].se;
        res = i;
    }
    side[2] = res ;
    return 0 ;
}

int findright()
{
    int tmp = -oo , res = 0 ;
    forinc(i,1,n) if (tmp < coor[i].se){
        tmp = coor[i].se ;
        res = i ;
    }
    side[3] = res ;
    return 0 ;
}

long long dist (int i , int j)
{
    return max(abs((long long)coor[i].fi - coor[j].fi) , abs((long long)coor[i].se - coor[j].se)) ;
}

int getroot(int u)
{
    if (u == lab[u]) return u ;
    lab[u] = getroot(lab[u]) ;
    return lab[u] ;
}

pair<int,pii> f[4 * maxN+1];

int check()
{
    int cnt = 0 , se = 0  ;
    forinc(i,1,n) lab[i] = i ;
    forinc(i,1,n)
        forinc(j,0,3) if (i != side[j]) {
            f[++cnt].fi = dist(side[j],i) ;
            f[cnt].se.fi = side[j] ; f[cnt].se.se = i ;
        }
    sort(f+1,f+1+cnt) ;
    fordec(i,cnt,1) {
        int u = f[i].se.fi , v = f[i].se.se ;

        if (getroot(u) != getroot(v)){
            lab[lab[u]] = lab[v] ;
            ++se ;
            if (se == n-1) return f[i].fi ;
        }
    }
    return -1 ;
}

int process()
{
    findtop() ; findbot() ;
    findleft() ; findright() ;
    int res = check() ;
    //cout << res << endl ;
    printf("%d\n" , res) ;
    return 0 ;
}

int main()
{
    //freopen("cf.inp" , "r" , stdin) ;
    int t = 0 ; //cin >> t ;
    scanf("%d" , &t) ;
    forinc(i,1,t){
        enter() ;
        process();
    }
    return 0 ;
}
