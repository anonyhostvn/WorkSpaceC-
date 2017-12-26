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
#define ll long long
#define maxN 100000

using namespace std ;
int n , k , m , rem[4*maxN+1] , val[4*maxN+1] ;

int trans(int s , int l , int r)
{
    if (l == r || rem[s] == 0) return 0 ;
    rem[2*s] += rem[s]  ;
    rem[2*s+1] += rem[s] ;
    val[2*s] += rem[s] ;
    val[2*s+1] += rem[s] ;
    rem[s] = 0 ;
    return 0 ;
}

int update(int s , int l ,int r , int u , int v)
{
    if (r < u || v < l) return 0 ;
    trans(s,l,r) ;
    if (u <= l && r <= v) {
        rem[s] = 1 ;
        val[s] ++ ;
        return 0 ;
    }
    int mid = (l+r) / 2;
    update(2*s,l,mid,u,v) ;
    update(2*s+1,mid+1,r,u,v) ;
    val[s] = max(val[2*s] , val[2*s+1] ) ;
    return 0 ;
}

int get(int s , int l , int r , int u , int v)
{
    if (r < u || v < l) return 0 ;
    trans(s,l,r) ;
    if (u <= l && r <= v) return val[s] ;
    int mid = (l+r) / 2;
    return max(get(2*s,l,mid,u,v),get(2*s+1,mid+1,r,u,v)) ;
}

int enter()
{
    scanf("%d %d %d" , &n , &k , &m) ;
    forinc(i,1,m) {
        int u , v ; scanf("%d %d", &u ,&v) ; ++ u ; ++v ;
        if (get(1,1,n,u,v-1) < k) {
            printf("%d\n" ,1) ;
            update(1,1,n,u,v-1) ;
        }
        else printf("%d\n" , 0) ;
    }
    return 0 ;
}

int main()
{
    //freopen("TPTICKET.inp" , "r" , stdin) ;
    enter() ;
    return 0 ;
}
