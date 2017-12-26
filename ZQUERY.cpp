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
#define maximize(a,b)
#define oo 1000000000

using namespace std ;

int n , m , s[50001] , p , last_block = 0 , id[4][100005] , ans[50001] , wall[300] , res1 , res2 ;

struct node
{
    int id , sl , sr ;
    node (int s , int l , int r){
        id = s ; sl = l ; sr = r ;
    }
};
vector<node> c[225] ;

int block(int i)
{
    if (i == 0) return 0 ;
    return (i-1) / p ;
}

int enter()
{
    ios_base::sync_with_stdio(false) ;
    cin >> n >> m ;
    p = (int) sqrt(n) ;
    s[0] = n ;
    forinc(i,1,n) {
        wall[block(i)] = i ;
        last_block = block(i) ;
        int x ; cin >> x ;
        s[i] = s[i-1] + x ;
    }
    forinc(i,1,m) {
        int u , v ; cin >> u >> v ; u-- ;
        c[block(u)].pb(node(i,u,v)) ;
    }
    return 0 ;
}

bool cmp (node a , node b)
{
    return (a.sr < b.sr) ;
}

int prepare()
{
    forinc(i,0,last_block) if (c[i].size() > 0) sort(c[i].begin() , c[i].end() , cmp) ;
    return 0 ;
}

int preset(int pos , int u , int v)
{
    int valre = -oo ;
    if (pos % 2 == 0) valre = oo ;
    forinc(i,u,v) id[pos][s[i]] = valre ;
    return 0 ;
}

int push(int i , int x , int wall)
{
    if (i <= wall) {
        id[0][x] = min(id[0][x],i) ;
        id[1][x] = max(id[1][x],i) ;
        res1 = max(res1,max(id[1][x],id[3][x]) - id[0][x]) ;
        return 0 ;
    }
    id[2][x] = min(id[2][x],i) ;
    id[3][x] = max(id[3][x],i) ;
    res1 = max(res1,id[3][x] - id[0][x]) ;
    res2 = max(res2,id[3][x] - id[2][x]) ;
    return 0 ;
}

int process()
{
    prepare() ;
    forinc(ibo,0,last_block) {

        if (c[ibo].size() == 0) continue ;
        preset(0,0,n) ;
        preset(1,0,n) ;
        preset(2,0,n) ;
        preset(3,0,n) ;

        int la = wall[ibo] ; res1 = 0 , res2 = 0 ;
        forinc(i,c[ibo][0].sl,c[ibo][0].sr) push(i,s[i],la) ;
        ans[c[ibo][0].id] = max(res1,res2) ;

        for (int i = 1 ; i < c[ibo].size() ; i++) {
            if (c[ibo][i].sl <= c[ibo][i-1].sl)
                forinc(j,c[ibo][i].sl,c[ibo][i-1].sl) push(j,s[j],la) ;
            else {
                res1 = 0 ;
                preset(0,c[ibo][i-1].sl,la) ;
                preset(1,c[ibo][i-1].sl,la) ;
                forinc(j,c[ibo][i].sl,min(c[ibo][i].sr,la)) push(j,s[j],la) ;
            }
            forinc(j,max(c[ibo][i].sl,c[ibo][i-1].sr),c[ibo][i].sr) push(j,s[j],la) ;
            ans[c[ibo][i].id] = max(res1,res2) ;
        }
    }

    forinc(i,1,m) cout << ans[i] << endl ;
    return 0 ;
}

int main()
{
    //freopen("ZQUERY.inp" , "r" , stdin) ;
    //freopen("ZQUERY.out" , "w" , stdout) ;
    enter() ;
    process() ;
    return 0 ;
}
