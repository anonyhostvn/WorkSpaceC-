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
#define maxN 1000005

using namespace std ;

string st ;
int n , a[maxN] ;

void enter()
{
    cin >> st ;
    int n = st.length() ;
    forinc(i,1,n-1) a[i] = (int) st[i-1] - (int)'a' ;
}

vector<int> u[26] ;

int main()
{
    return 0 ;
}
