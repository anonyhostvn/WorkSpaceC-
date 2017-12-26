#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)
#define forv(j,u) for (int j = 0 ; j < u.size() ; j++)
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define mk make_pair
#define oo 1e9
#define pii pair<int,int>

using namespace std ;

const
    int gox[4] = {-1 , +1 , 0 , 0} ;
    int goy[4] = { 0 ,  0 ,-1 ,+1} ;

int n , m , a[8][5001] , tx[30001] , ty[30001] , tu[30001] , tv[30001], q , query[30001] , query_left[30001] , query_right[30001] , query_mid[30001];
int qres[30001] , d[8][5001] ;

int enter()
{
    ios_base::sync_with_stdio(false) ;
    cin >> n >> m ;
    forinc(i,1,n)
    forinc(j,1,m) cin >> a[i][j] ;
    cin >> q ;
    forinc(i,1,q) {
        cin >> tx[i] >> ty[i] >> tu[i] >> tv[i]  ;
        tx[i] ++ ; ty[i] ++ ; tu[i] ++ ; tv[i] ++ ;
    }
    return 0 ;
}


priority_queue <pair<int,pair<int,int> > > heap ;
vector<pair<int,pii> > ke[8][5001] ;

int add(pii x , pii y , int dist)
{
    pair<int,pii> tmp ;
    tmp.fi = dist ; tmp.se.fi = y.fi ; tmp.se.se = y.se ;
    ke[x.fi][x.se].pb(tmp) ;
}

int dkstra(int xmid , int ymid , int l , int r)
{
    forinc(i,1,n)
    forinc(j,l,r) d[i][j] = oo ;
    heap.push(mk(-a[xmid][ymid],mk(xmid,ymid))) ;
    d[xmid][ymid] = a[xmid][ymid] ;
    while (!heap.empty()){
        pair<int,pair<int,int> > tmp = heap.top() ; heap.pop() ;
        int u = tmp.second.first , v = tmp.second.second ;
        if (d[u][v] != -tmp.first) continue ;
        forv(j,ke[u][v]) {
            pair<int,pii> tmp = ke[u][v][j] ;
            int cx = tmp.se.fi , cy = tmp.se.se , dist = tmp.fi ;
            if (cx >= 1 && cy >= l && cx <= n && cy <= r  && d[cx][cy] > d[u][v] + dist) {
                d[cx][cy] = d[u][v] + dist ;
                heap.push(mk(-d[cx][cy],mk(cx,cy))) ;
            }
        }
    }
    return 0 ;
}

int speedup(int l , int r , int ql , int qr)
{
    if (ql > qr) return 0 ;
    if (r-l <= 1){
        forinc(i,ql,qr) {
            int squery = query[i] ;
            dkstra(tx[squery],ty[squery],l,r) ;
            qres[squery] = d[tu[squery]][tv[squery]] ;
        }
        return 0 ;
    }
    int cleft = 0 , cright = 0 , cmid = 0 ;
    int mid = (l+r) / 2 ;
    forinc(i,ql,qr) {
        int squery = query[i] ;
        if (ty[squery] <= mid && tv[squery] >= mid) query_mid[++cmid] = squery ;
        else if (ty[squery] < mid && tv[squery] < mid) query_left[++cleft] = squery ;
        else if (ty[squery] > mid && tv[squery] > mid) query_right[++cright] = squery ;
    }

    forinc(i,1,n) {
        dkstra(i,mid,l,r) ;
        forinc(j,1,cmid) {
            int squery = query_mid[j] ;
            qres[squery] = min(qres[squery] , d[tx[squery]][ty[squery]] + d[tu[squery]][tv[squery]] - a[i][mid]) ;
        }
        forinc(j,1,n) if (i != j) add(mk(i,mid),mk(j,mid),d[j][mid]-a[i][mid])  ;
    }

    forinc(i,1,cleft) query[ql+i-1] = query_left[i] ;
    forinc(i,1,cright) query[ql+i+cleft-1] = query_right[i] ;

    if (cleft > 0) speedup(l,mid,ql,ql+cleft-1) ;
    if (cright > 0) speedup(mid,r,ql+cleft,ql+cleft+cright-1) ;
    return 0 ;
}

int prepare()
{
    forinc(i,1,q) {
        query[i] = i ; qres[i] = oo ;
        if (ty[i] > tv[i]) {
            swap(ty[i],tv[i]) ;
            swap(tx[i],tu[i]) ;
        }
    }
    forinc(i,1,n)
    forinc(j,1,m) {
        forinc(k,0,3){
            int cx = i + gox[k] , cy = j + goy[k] ;
            if (cx > 0 && cy > 0 && cx <= n && cy <= m) add(mk(i,j),mk(cx,cy),a[cx][cy]) ;
        }
    }
    return 0 ;
}

int process()
{
    prepare() ;
    speedup(1,m,1,q);
    forinc(i,1,q) cout << qres[i] << endl ;
    return 0 ;
}

int main()
{
    freopen("path1.inp" , "r" , stdin) ;
    freopen("path1.out" , "w" , stdout) ;
    enter() ;
    process() ;
    return  0 ;
}
