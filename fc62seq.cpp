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
#define maxN 500001
#define base (int) 1e9

using namespace std ;

int n , a[maxN] , minL[maxN] , maxL[maxN]  ;
struct node{
    long long ins[7] ;
};

node null = {0,0,0,0,0,0,0} ;

node val[4*maxN] ;
int rem_Length[4*maxN] , rem_max[4*maxN] , rem_min[4*maxN] ;

void enter()
{
    cin >> n ;
    forinc(i,1,n) cin >> a[i] ;
}

void prepare()
{
    stack<int> st ;
    forinc(i,1,n) {
        while (!st.empty() && a[i] <= a[st.top()]) st.pop() ;
        if (!st.empty()) minL[i] = st.top() + 1 ; else minL[i] = 1 ;
        st.push(i) ;
    }
    while (!st.empty()) st.pop() ;
    forinc(i,1,n) {
        while (!st.empty() && a[i] >= a[st.top()]) st.pop() ;
        if (!st.empty()) maxL[i] = st.top() + 1 ; else maxL[i] = 1 ;
        st.push(i) ;
    }
}

void mod_base_node(int s)
{
    forinc(i,0,6) val[s].ins[i] %= base ;
}

void setnode(int s , int l , int r , int id , int k)
{
    int len = r-l+1 ;
    if (id == 0) {
        val[s].ins[0] += (long long) k * len ;
        val[s].ins[4] += val[s].ins[1] * k ;
        val[s].ins[5] += val[s].ins[2] * k ;
        val[s].ins[6] += val[s].ins[3] * k ;
        rem_Length[s] += k ;
    }
    else if (id == 1) {
        val[s].ins[1] = (long long) k * len;
        val[s].ins[3] = (long long) k * val[s].ins[2] ;
        val[s].ins[4] = (long long) k * val[s].ins[0] ;
        val[s].ins[6] = (long long) k * val[s].ins[5] ;
        rem_min[s] = k ;
    }
    else if (id == 2) {
        val[s].ins[2] = (long long) k * len ;
        val[s].ins[3] = (long long) k * val[s].ins[1] ;
        val[s].ins[5] = (long long) k * val[s].ins[0] ;
        val[s].ins[6] = (long long) k * val[s].ins[4] ;
        rem_max[s] = k ;
    }
    mod_base_node(s) ;
}

void trans(int s , int l , int r)
{
    int mid = (l+r) / 2 ;
    if (rem_Length[s] != 0) {
        setnode(2*s,l,mid,0,rem_Length[s]) ;
        setnode(2*s+1,mid+1,r,0,rem_Length[s]) ;
        rem_Length[s] = 0 ;
    }
    if (rem_min[s] != 0) {
        setnode(2*s,l,mid,1,rem_min[s]) ;
        setnode(2*s+1,mid+1,r,1,rem_min[s]) ;
        rem_min[s] = 0 ;
    }
    if (rem_max[s] != 0) {
        setnode(2*s,l,mid,2,rem_max[s]) ;
        setnode(2*s+1,mid+1,r,2,rem_max[s]) ;
        rem_max[s] = 0 ;
    }
}

node combine(node a , node b)
{
    node res ;
    forinc(i,0,6) res.ins[i] = a.ins[i] + b.ins[i] , res.ins[i] %= base ;
    return res ;
}

void update(int s , int l , int r , int u , int v , int id , int k)
{
    if (r < u || v < l) return ;
    if (u <= l && r <= v) {
        setnode(s,l,r,id,k) ;
        return ;
    }
    int mid = (l+r) / 2 ;
    trans(s,l,r) ;
    update(2*s,l,mid,u,v,id,k) ;
    update(2*s+1,mid+1,r,u,v,id,k) ;
    val[s] = combine(val[2*s],val[2*s+1]) ;
}

void process()
{
    prepare() ;
    long long res = 0 ;
    forinc(i,1,n) {
        update(1,1,n,1,i,0,1) ;
        update(1,1,n,minL[i],i,1,a[i]) ;
        update(1,1,n,maxL[i],i,2,a[i]) ;
        res += val[1].ins[6] ; res %= base ;
    }
    cout << res << endl ;
}

int main()
{
    //freopen("fc62seq.inp" , "r" , stdin) ;
    enter() ;
    process() ;
    return 0 ;
}
