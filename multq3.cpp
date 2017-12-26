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
#define maxN 100005

using namespace std ;

struct node {
    int mod[3] ;
};

int n , q , rem[4*maxN] ;
node val[4 * maxN] , null ;

void setnode(int s , int l , int r , int k)
{
    rem[s] += k ;
    node tmp ;
    forinc(i,0,2) tmp.mod[(i+1) % 3] = val[s].mod[i] ;
    val[s] = tmp ;
}

node combine(node s1 , node s2)
{
    node tmp ;
    forinc(i,0,2) tmp.mod[i] = s1.mod[i] + s2.mod[i] ;
    return tmp ;
}

void trans(int s , int l , int r)
{
    if (rem[s] == 0) return ;
    rem[2*s] += rem[s] ;
    rem[2*s+1] += rem[s] ;
    node tmp ;
    forinc(i,0,2) tmp.mod[(i+rem[s]) % 3] = val[2*s].mod[i] ; val[2*s] = tmp ;
    forinc(i,0,2) tmp.mod[(i+rem[s]) % 3] = val[2*s+1].mod[i] ; val[2*s+1] = tmp ;
    rem[s] = 0 ;
}

void update(int s , int l ,int r , int u , int v , int k)
{
    if (r < u || v < l) return ;
    if (u <= l && r <= v) {
        setnode(s,l,r,k) ;
        return ;
    }
    trans(s,l,r) ;
    int mid = (l+r) / 2 ;
    update(2*s,l,mid,u,v,k) ;
    update(2*s+1,mid+1,r,u,v,k) ;
    val[s] = combine(val[2*s],val[2*s+1]) ;
}

node get(int s , int l , int r , int u , int v)
{
     if (r < u || v < l) return null ;
     if (u <= l && r <= v) return val[s] ;
     int mid = (l+r) / 2 ;
     trans(s,l,r) ;
     return combine(get(2*s,l,mid,u,v),get(2*s+1,mid+1,r,u,v)) ;
}

void init(int s , int l , int r)
{
    if (l > r) return ;
    if (l == r) {
        val[s].mod[0] = 1 ;
        return ;
    }
    int mid = (l+r) / 2 ;
    init(2*s,l,mid) ;
    init(2*s+1,mid+1,r) ;
    val[s] = combine(val[2*s],val[2*s+1]) ;
}

int enter()
{
    null.mod[0] = 0 ; null.mod[1] = 0 ; null.mod[2] = 0 ;
    scanf("%d %d" , &n , &q) ;
    init(1,1,n) ;
    forinc(i,1,q) {
        int query = 0 ; scanf("%d" , &query) ;
        if (query == 0) {
            int u ,v ; scanf("%d %d" , &u , &v) ; u ++ ; v ++ ;
            update(1,1,n,u,v,1) ;
        } else {
            int u , v ; scanf("%d %d" , &u , &v) ; u ++ ; v ++ ;
            printf("%d\n" , get(1,1,n,u,v).mod[0]) ;
        }
    }
}

int main()
{
    //freopen("Test.inp" , "r" , stdin) ;
    //freopen("multq3.out" , "w" , stdout) ;
    enter() ;
    return 0 ;
}
