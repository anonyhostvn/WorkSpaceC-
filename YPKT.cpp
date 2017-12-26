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
#define maxN 100001

using namespace std ;

struct node
{
    int sl , sr , sk ;
};

node tree[20 * maxN] ;
pii b[maxN] ;
int n , q , a[maxN] , snode , id[maxN] , real_val[maxN];

int enter()
{
    cin >>  n  ;
    forinc(i,1,n) {
        cin >> b[i].fi ;
        b[i].se = i ;
    }
    return 0 ;
}

int mini()
{
    sort(b+1,b+1+n) ;
    int cnt = 1 ; a[b[1].se] = 1 ; real_val[1] = b[1].fi ;
    forinc(i,2,n) {
        if (b[i].fi != b[i-1].fi) cnt ++ ;
        real_val[cnt] = b[i].fi ;
        a[b[i].se] = cnt ;
    }
    return 0 ;
}

int set_node(int id , int l , int r , int x , int k)
{
    if (l == r){
        tree[id].sk += k ;
        return 0 ;
    }
    int mid = (l+r) / 2 ;
    if (x <= mid) {
        if (tree[id].sl == 0) tree[id].sl = ++snode ;
        set_node(tree[id].sl,l,mid,x,k) ;
    }
    else {
        if (tree[id].sr == 0) tree[id].sr = ++snode ;
        set_node(tree[id].sr,mid+1,r,x,k) ;
    }
    tree[id].sk = tree[tree[id].sl].sk + tree[tree[id].sr].sk ;
    return 0 ;
}

int init()
{
    id[1] = 1 ; snode = 1 ;
    forinc(i,1,n) set_node(1,1,n,i,0) ;
    set_node(1,1,n,a[1],1) ;
    return 0 ;
}

int connect_tree(int recent , int l , int r , int older , int x)
{
    if (l == r) {
        tree[recent].sk ++ ;
        return 0 ;
    }
    int mid = (l+r) / 2 ;
    if (x <= mid) {
        tree[recent].sr = tree[older].sr ;
        tree[recent].sl = ++snode ;
        connect_tree(snode,l,mid,tree[older].sl,x) ;
    }
    else {
        tree[recent].sl = tree[older].sl ;
        tree[recent].sr = ++snode ;
        connect_tree(snode,mid+1,r,tree[older].sr,x) ;
    }
    tree[recent].sk = tree[tree[recent].sl].sk + tree[tree[recent].sr].sk ;
    return 0 ;
}

int build()
{
    init() ;
    forinc(i,2,n) {
        id[i] = ++snode ;
        connect_tree(snode,1,n,id[i-1],a[i]) ;
    }
    return 0 ;
}

int go(int id , int l , int r , int x)
{
    if (l == r) return tree[id].sk ;
    int mid = (l+r) / 2 ;
    if (x <= mid) return go(tree[id].sl,l,mid,x) ;
    else return tree[tree[id].sl].sk + go(tree[id].sr,mid+1,r,x) ;
}

int smaller(int x , int l , int r)
{
    return go(id[r],1,n,x) - go(id[l-1],1,n,x) ;
}

int query(int l , int r , int k)
{
    int le = 1 , ri = n  , res = 0 ;
    while (le <= ri){
        int mid = (le+ri) / 2 ;
        if (smaller(mid,l,r) >= k){
            ri = mid - 1 ;
            res = mid ;
        }
        else le = mid + 1 ;
    }
    cout << real_val[res] << endl ;
    return 0 ;
}

int process()
{
    mini() ;
    build() ;
    cin >> q ;
    forinc(i,1,q) {
        int l , r , k ; cin >> l >> r >> k ;
        query(l,r,k) ;
    }
    return 0 ;
}

int main()
{
    //freopen("YPKT.inp" , "r" , stdin) ;
    enter() ;
    process() ;
    return 0 ;
}

