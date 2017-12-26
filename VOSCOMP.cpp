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
    pii seg , point ;
    int type ;
};

node mk_node(pii a , pii b , int c) {
    node res ;
    res.seg = a ; res.point = b ; res.type = c ;
}

map<pii , vector<int> > query ;
node f[100001] ;
int n , q , even = 0 ;

int enter()
{
    cin >> n >> q ;
    forinc(i,1,q){
        int u , v , t , su , sv ; cin >> t >> su >> sv ;
        u = min(su,sv) ; v = max(su,sv) ;
        if (t == 3) f[++even] = mk_node(mk(u,v),mk(i,0),0) ;
        else if (t == 1) query[mk(u,v)].pb(i) ;
        else if (t == 2) {
            int tin = query[mk(u,v)].back() ; query[mk(u,v)].pop_back() ;
            f[++even] = mk_node(mk(u,v),mk(tin,i-1),1) ;
        }
    }
    return 0 ;
}

int process()
{

}

int main()
{
    return 0  ;
}

