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
#define maxM 100001

using namespace std ;

int n , m , num[maxN] , low[maxN] , cnt = 0 , res = 0 , ComponentCount = 0 , LastComponent[maxN] ;
vector<int> ke[maxN] ;

void enter()
{
    cin >> n >> m ;
    forinc(i,1,m) {
        int u , v ; cin >> u >> v ;
        ke[u].push_back(v) ;
        ke[v].push_back(u) ;
    }
}

stack<int> st ;

void dfs(int u)
{
    num[u] = low[u] = ++cnt ;
    forv(i,ke[u]) {
        int v = ke[u][i] ;
        if (num[v]) low[u] = min(low[u],num[v]) ;
        else {
            st.push(u) ; dfs(v) ;
            low[u] = min(low[u],low[v]) ;
            if (low[v] >= num[u]) {
                int count_ = 0 ; ComponentCount ++ ;
                do {
                    v = st.top() ; st.pop() ;
                    if (LastComponent[v] < ComponentCount) LastComponent[v] = ComponentCount , count_ ++ ;
                } while (v != u) ;
                res = max(res,count_) ;
            }
        }
    }
    st.push(u) ;
}

void process()
{
    forinc(i,1,n) if (num[i] == 0) dfs(i) ;
    cout << max(1,res) ;
}

int main()
{
    //freopen("safenet.inp" , "r" , stdin) ;
    enter() ;
    process() ;
    return 0 ;
}
