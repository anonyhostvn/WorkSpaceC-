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
#define maxN 200005
#define oo 1000000000

using namespace std ;
int n ;

int enter()
{
    int res = 0 , sign = 0 , speed  = 0 ;
    stack<int> st ;
    cin >> n ;
    while (n--) {
        int query ; cin >> query ;
        if (query == 1) {
            cin >> speed ;
            while (!st.empty() && speed > st.top()) {
                st.pop() ;
                res ++ ;
            }
        }
        else if (query == 2) {
            res += sign ;
            sign = 0 ;
        }
        else if (query == 3) {
            int lim ; cin >> lim ;
            if (speed > lim) res ++ ; else st.push(lim) ;
        }
        else if (query == 4) sign = 0 ;
        else if (query == 5) while (!st.empty()) st.pop() ;
        else if (query == 6) sign ++ ;
    }
    cout << res ;
    return 0 ;
}

int main()
{
    //freopen("845D.inp" , "r" , stdin) ;
    enter() ;
    return 0 ;
}
