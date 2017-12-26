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
    pii pair_adj , pair_time ;
    int type ;
};

node mk_node(pii a , pii b , int c)
{
    node res ;
    res.pair_adj = a ;
    res.pair_time = b ;
    res.type = c ;
    return res ;
}

int n , q , sq = 0 , num_block = 0 , lab[100001] , begin_block[320] , end_block[320] , sblock , ans[100001] ;
node f[100001] ;
map<pii , vector<int> > query ;
map<pii, vector<int> > :: iterator it ;

int standard(int &u , int &v)
{
    int tmp = min(u,v) ;
    v = max(u,v) ;
    u = tmp ;
    return 0 ;
}

vector<int> edge_block[320] , query_block[320] ;

int enter()
{
    cin >> n >> q ;
    num_block = (int) sqrt(q) ;
    forinc(i,1,q) {
        int t , u , v ; cin >> t >> u >> v ;
        standard(u,v) ;
        if (t == 3) f[++sq] = mk_node(mk(u,v),mk(i,0),0) ;
        else if (t == 1) query[mk(u,v)].pb(i) ;
        else if (query[mk(u,v)].size() > 0) {
            int add = query[mk(u,v)].back() ; query[mk(u,v)].pop_back();
            f[++sq] = mk_node(mk(u,v),mk(add,i),1) ;
        }
        int id = (i-1) / num_block ;
        if (begin_block[id] == 0) begin_block[id] = i ;
        end_block[id] = i ;
        sblock = id ;
    }
    for (it = query.end() ; it != query.begin() ; --it) {
        while ((*it).second.size() > 0) {
            int add = (*it).second.back() ;
            pii adj = (*it).first ;
            (*it).second.pop_back() ;
            f[++sq] =  mk_node(adj,mk(add,q+1),1) ;
        }
    }
    return 0 ;
}

int add(int u , int v , int pis)
{
   if (pis == 0) query_block[u].push_back(v) ;
   else edge_block[u].push_back(v) ;
   return 0 ;
}

int prepare()
{
    forinc(i,1,sq) {
        int stin = f[i].pair_time.fi , stout = f[i].pair_time.se ;
        add((stin-1)/num_block , i , f[i].type) ;
        if (stout > 0) add((stout-1)/num_block , i , f[i].type) ;
    }
    return 0 ;
}

int preset()
{
    forinc(i,1,n) lab[i] = -1 ;
    return 0 ;
}

int getroot(int u)
{
    while (lab[u] > 0) u = lab[u] ;
    return u ;
}

stack<pii> st ;

int uni(int u , int v , int ok)
{
    int r1 = getroot(u) , r2 = getroot(v) , x = lab[r1] + lab[r2] ;
    if (r1 == r2) return 0 ;
    if (ok) {
        st.push(mk(r1,lab[r1])) ;
        st.push(mk(r2,lab[r2])) ;
    }
    if (lab[r1] < lab[r2]) {
        lab[r2] = r1 ;
        lab[r1] = x ;
    } else {
        lab[r1] = r2 ;
        lab[r2] = x;
    }
    return 0 ;
}

int rolback()
{
    while (st.size() > 0) {
        pii tmp = st.top() ; st.pop() ;
        lab[tmp.fi] = tmp.se ;
    }
    return 0 ;
}

int process()
{
    prepare() ;
    forinc(block,0,sblock) {
        if (query_block[block].size() == 0) continue ;
        preset() ;
        forinc(i,1,sq) if (f[i].type == 1) {
            int u = f[i].pair_time.fi , v = f[i].pair_time.se ;
            if (u <= begin_block[block] && v >= end_block[block]) {
                int adj1 = f[i].pair_adj.fi , adj2 = f[i].pair_adj.se ;
                uni(adj1,adj2,0) ;
            }
        }
        forv(i,query_block[block]) {
            int id = query_block[block][i] , stime = f[id].pair_time.fi ;
            forv(j,edge_block[block]) {
                int id = edge_block[block][j] , s_add = f[id].pair_time.fi , s_sub = f[id].pair_time.se ;
                if (s_add <= stime && s_sub >= stime) {
                    int adj1 = f[id].pair_adj.fi , adj2 = f[id].pair_adj.se ;
                    uni(adj1,adj2,1) ;
                }
            }
            int adj1 = f[id].pair_adj.fi , adj2 = f[id].pair_adj.se ;
            if (getroot(adj1) == getroot(adj2)) ans[id] = 1 ;
            rolback() ;
        }
    }
    forinc(i,1,sq) if (f[i].type == 0) cout << ans[i] ;
    return 0 ;
}

int main()
{
    //freopen("VOSCOMPS.inp" , "r" , stdin) ;
    enter() ;
    process() ;
    return 0 ;
}
