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
#define base (int) 1e9 + 7
#define maxN 200000

using namespace std ;

int n , m , t[maxN] , s_guest = 0 ;

void enter()
{
    cin >> n >> m ;
    int t_time = 0 ;
    forinc(i,1,n) {
        int x , s ; cin >> x >> s ;
        forinc(i,1,s) {
            int tmp = 0 ; cin >> tmp ;
            t[++s_guest] = max(0,tmp - t_time) ;
        }
        t_time += x ;
    }
    sort(t+1,t+1+s_guest) ;
    int res = 0 , cnt = 0 ;
    forinc(i,1,
}

int main()
{
    return 0 ;
}
