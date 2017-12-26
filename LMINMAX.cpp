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
#define oo (long long) 1e15
#define maxN 1000005

using namespace std ;

int n , d , a[maxN] ;

void enter()
{
    scanf("%d%d" , &n , &d) ;
    forinc(i,1,n) scanf("%d", &a[i]) ;
}

deque<int> st[2] ;

void add_0(int i) {
    while (!st[0].empty() && a[i] <= a[st[0].back()]) st[0].pop_back() ;
    st[0].push_back(i) ;
}

void add_1(int i) {
    while (!st[1].empty() && a[i] >= a[st[1].back()]) st[1].pop_back() ;
    st[1].push_back(i) ;
}

void remove_(int j)
{
    if (st[1].front() == j) st[1].pop_front() ;
    if (st[0].front() == j) st[0].pop_front() ;
}

void process()
{
    int j = 1 , res = 0 ;
    forinc(i,1,n) {
        add_0(i) ; add_1(i) ;
        while (j <= i && abs(a[st[1].front()] - a[st[0].front()]) > d) remove_(j++) ;
        res = max(res,i-j + 1) ;
    }
    printf("%d"  , res) ;
}

int main()
{
    freopen("LMINMAX.inp" , "r" , stdin) ;
    freopen("LMINMAX.out" , "w" , stdout) ;
    enter() ;
    process() ;
    return 0 ;
}
