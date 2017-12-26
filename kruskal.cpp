#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)
#define forv(j,u) for (int j = 0 ; j < u.size() ; j++)

using namespace std ;

int n , m , lab[3001] ;

int getroot(int u)
{
    if (u == lab[u]) return u ;
    lab[u] = getroot(lab[u]) ;
    return lab[u] ;
}

struct cmp{
    bool operator () (pair<int , pair<int,int> > a , pair<int , pair<int,int> > b){return a.first < b.first ;}
};
multiset<pair<int,pair<int,int > > > q ;

int enter()
{
    int res = 0 ;
    cin >> n >> m ;
    forinc(i,1,m){
        int u , v , c ; cin >> u >> v >>c ;
        q.insert(make_pair(c,make_pair(u,v))) ;
    }

    forinc(i,1,n) lab[i] = i ;

    while (!q.empty()){
        pair<int,pair<int,int> > tmp = *q.begin() ;
        q.erase(q.begin()) ;
        int u = tmp.second.first , v = tmp.second.second ;
        if (getroot(u) != getroot(v)){
            res += tmp.first ;
            lab[lab[u]] = lab[v] ;
        }
    }

    cout << res ;
}

int main()
{
    //freopen("kruskal.inp" , "r" , stdin) ;
    enter() ;
}
