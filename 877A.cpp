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
#define oo (int) 1e9 + 7

using namespace std ;

string st ;
vector<string> name ;

bool check(int u , int v , int id)
{
    forinc(i,u,v) if (st[i] != name[id][i-u]) return false ;
    return true ;
}

void enter()
{
    cin >> st ;
    name.push_back("Danil") ;
    name.push_back("Olya") ;
    name.push_back("Slava") ;
    name.push_back("Ann") ;
    name.push_back("Nikita") ;
    int cnt = 0 , n = st.length() ;
    forinc(i,0,n-1) forv(j,name) if (st[i] == name[j][0] && check(i,i+name[j].length() - 1,j)) cnt ++ ;
    if (cnt == 1)cout << "YES" ; else cout << "NO" ;
}

int main()
{
    //freopen("877A.inp" , "r" , stdin) ;
    enter() ;
    return 0 ;
}
