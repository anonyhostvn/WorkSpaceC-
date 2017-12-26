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
#define maxN 105

using namespace std ;

string sta , stb ;
int na , nb , a[maxN] , b[maxN] , nxt[2][maxN][27] , f[maxN][maxN] , max_sub = 0 ;

void enter()
{
    cin >> sta ;
    cin >> stb ;
    na = sta.length() ;
    nb = stb.length() ;
}

void prepare()
{
    forinc(i,1,na) a[i] = (int) sta[i-1] - (int) 'a' ;
    forinc(i,1,nb) b[i] = (int) stb[i-1] - (int) 'a' ;
    fordec(i,na-1,0) {
        forinc(j,0,25) nxt[0][i][j] = nxt[0][i+1][j] ;
        nxt[0][i][a[i+1]] = i+1 ;
    }
    fordec(i,nb-1,0) {
        forinc(j,0,25) nxt[1][i][j] = nxt[1][i+1][j] ;
        nxt[1][i][b[i+1]] = i + 1 ;
    }
}

vector<int> st ;
vector<vector<int> > ans ;
vector<vector<int> > res ;

void track(int i , int j)
{
    if (f[i][j] == max_sub) {
        ans.push_back(st) ;
        return ;
    }
    forinc(ch,0,25) {
        int ia = nxt[0][i][ch] , ib = nxt[1][j][ch] ;
        if (f[ia][ib] == f[i][j] + 1) {
            st.push_back(ch) ;
            track(ia,ib) ;
            st.pop_back() ;
        }
    }
}

bool cmp(vector<int> a , vector<int> b)
{
    forv(i,a) if (a[i] < b[i]) return true ;
    else if (a[i] > b[i]) return false ;
    return false ;
}

void print(vector<int> a)
{ forv(i,a) cout << (char) (a[i] + (int)'a') ; cout << endl ; }

bool equal_(vector<int> a , vector<int> b)
{
    forv(i,a) if (a[i] != b[i]) return false ;
    return true ;
}

void process()
{
    prepare() ;
    forinc(i,0,na)
    forinc(j,0,nb) if (a[i] == b[j])
        forinc(ch,0,25) {
            int ia = nxt[0][i][ch] , ib = nxt[1][j][ch] ;
            if (ia == 0 || ib == 0) continue ;
            f[ia][ib] = max(f[ia][ib],f[i][j] + 1) ;
            max_sub = max(max_sub,f[ia][ib])  ;
        }
    track(0,0) ;
    sort(ans.begin(),ans.end(),cmp) ;
    forv(i,ans) if (!(i > 0 && equal_(ans[i],ans[i-1]))) res.push_back(ans[i]) ;
    cout << res.size() << endl ;
    forv(i,res) print(res[i]) ;
}

int main()
{
    //freopen("Test.inp" , "r" , stdin) ;
    enter() ;
    process() ;
    return 0 ;
}
