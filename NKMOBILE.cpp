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

int f[2048][2048] ;

struct it2d
{
    int id , ll , rr ;
    it2d (int s , int l , int r){
        ll = l ; rr = r ; id = s ;
    }
    it2d left () const {
        return it2d(2*id,ll,(ll+rr)/2) ;
    }
    it2d right() const {
        return it2d(2*id+1,(ll+rr)/2+1,rr) ;
    }
    inline bool irre(int l , int r) const {
        return (l > r) || (ll > r) || (rr < l) ;
    }
};

int update(const it2d &dx, const it2d &dy , int x , int y , int k , bool only_y)
{
    if (dx.irre(x,x) || dy.irre(y,y)) return 0 ;
    f[dx.id][dy.id] += k ;
    if (!only_y && dx.ll != dx.rr){
        update(dx.left(),dy,x,y,k,false) ;
        update(dx.right(),dy,x,y,k,false) ;
    }
    else if (dy.ll != dy.rr){
        update(dx,dy.left(),x,y,k,true) ;
        update(dx,dy.right(),x,y,k,true) ;
    }
    return 0 ;
}

int get(const it2d &dx , const it2d &dy , int x , int y , int u , int v )
{
    if (dx.irre(x,u) || dy.irre(y,v)) return 0 ;
    if (dx.ll >= x && dx.rr <= u) {
        if (dy.ll >= y && dy.rr <= v) return f[dx.id][dy.id] ;
        int s1 = get(dx,dy.left(),x,y,u,v) ,
            s2 = get(dx,dy.right(),x,y,u,v) ;
        return s1 + s2 ;
    }
    else {
        int s1 = get(dx.left(),dy,x,y,u,v) ,
            s2 = get(dx.right(),dy,x,y,u,v) ;
        return s1 + s2 ;
    }
}

int S ;

int enter()
{
    int command = 0 ;
    cin >> command >> S ;
    it2d dx(1,1,S) ; it2d dy(1,1,S) ;
    while (cin >> command){
        if (command == 3) return 0 ;
        if (command == 1){
            int x , y , a ;
            cin >> x >> y >> a ;
            ++x ; ++y ;
            update(dx,dy,x,y,a,false) ;
        }
        else {
            int x ,y , u , v ;
            cin >> x >> y >> u >>  v ;
            ++x ; ++y ; ++u ; ++v ;
            cout << get(dx,dy,x,y,u,v) << endl ;
        }
    }
    return 0 ;
}

int main()
{
    freopen("nkmobile.inp" , "r" , stdin) ;
    enter() ;
    return 0 ;
}
