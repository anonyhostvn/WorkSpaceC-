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
#define maxC 1003

using namespace std ;

int n , k , tx[maxN+1] , ty[maxN+1] , tc[maxN+1] , f[4096][4096] ;

struct nodeit
{
    int id , ll , lr  ;
    nodeit(int s , int l , int r){
        id = s ; ll = l ; lr = r ;
    }
    nodeit left() const {
        return nodeit(2*id,ll,(ll+lr) / 2) ;
    }
    nodeit right() const{
        return nodeit(2*id+1,(ll+lr) / 2 +1,lr) ;
    }
    inline bool irre (int l , int r) const {
        return (l > r) || (lr < l) || (r < ll) ;
    }
};

int maximize(int &x , int y)
{
    x = max(x,y) ;
    return 0 ;
}

int update(const nodeit &dx , const nodeit &dy , int x , int y , int k , bool only_y)
{
    if (dx.irre(x,x) || dy.irre(y,y)) return 0 ;
    maximize(f[dx.id][dy.id],k) ;
    if (!only_y && dx.ll != dx.lr){
        update(dx.left(),dy,x,y,k,false) ;
        update(dx.right(),dy,x,y,k,false) ;
    }
    if (dy.ll != dy.lr){
        update(dx,dy.left(),x,y,k,true) ;
        update(dx,dy.right(),x,y,k,true) ;
    }
    return 0 ;
}

int get(const nodeit &dx , const nodeit &dy , int lx , int ly , int rx , int ry)
{
    if (dx.irre(lx,rx) || dy.irre(ly,ry)) return 0 ;
    if (lx <= dx.ll && dx.lr <= rx) {
        if (ly <= dy.ll && dy.lr <= ry) return f[dx.id][dy.id] ;
        int max1 = get(dx,dy.left(),lx,ly,rx,ry) ,
            max2 = get(dx,dy.right(),lx,ly,rx,ry) ;
        return max(max1,max2) ;
    }
    else {
        int max1 = get(dx.left(),dy,lx,ly,rx,ry) ,
            max2 = get(dx.right(),dy,lx,ly,rx,ry) ;
        return max(max1,max2) ;
    }
}

int enter()
{
    cin >> n >> k ;
    forinc(i,1,n) cin >> tx[i] >> ty[i] >> tc[i] ;
    return 0 ;
}

int process()
{
    nodeit dx(1,1,maxC + maxC) ; nodeit dy(1,1,maxC+maxC) ;
    fordec(i,n,1) {
        #define actual(x,y,k) x+y-k , x-y-k+maxC , x+y+k , x-y+k+maxC
        int tmp = get(dx,dy,actual(tx[i],ty[i],k)) + tc[i] ;
        update(dx,dy,tx[i]+ty[i],tx[i]-ty[i]+maxC,tmp,false) ;
    }
    cout << get(dx,dy,actual(0,0,k)) ;
    return 0 ;
}

int main()
{
    enter() ;
    process() ;
    return 0 ;
}
