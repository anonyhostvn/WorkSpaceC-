#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)
#define forv(j,u) for (int j = 0 ; j < u.size() ; j++)

using namespace std;

string st ;
int l  ;
bool dd[300] ;

int enter()
{
    cin >> st ;
    forinc(i,0,st.length()-1) dd[(int)st[i]] = true ;
    cin >> st ;
    l = st.length() ;
}

int process()
{
    int star = l ;
    forinc(i,0,l-1) if (st[i] == '*') star = i ;
    int n = 0 ;
    cin >> n ;
    forinc(i,1,n){
        string t ;
        cin >> t ;
        int sl = t.length() ;
        bool ok = true ;

        forinc(i,0,star-1) {
            if (st[i] == '?' && dd[(int)t[i]]) continue ;
            else if (st[i] == '?') {
                ok = false ;
                break ;
            }
            if (st[i] != t[i]){
                ok = false ;
                break ;
            }
        }

        int j = sl - 1 ;
        fordec(i,l-1,star+1){
            if (j == star-1) {
                ok = false ;
                break ;
            }
            if (st[i] == '?' && !dd[(int)t[j]]){
                ok = false ;
                break ;
            }
            else if (st[i] == '?') continue ;
            if (st[i] != t[j]){
                ok = false ;
                break ;
            }
            j-- ;
        }

        forinc(i,star,j) if (dd[(int)t[i]]) {
            ok = false ;
            break ;
        }

        if (ok) cout << "YES" << endl  ; else cout << "NO" << endl ;
    }
}

int main()
{
    //freopen("832B.inp" , "r" , stdin) ;

    enter() ;
    process() ;
}
