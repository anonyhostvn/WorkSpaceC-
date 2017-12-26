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

template <class _T> bool maximize(_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize(_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

const int ooit = 2e9 ;
const long long ooll = 1e15 ;


using namespace std ;

#define maxN 1000005
int n , a[maxN] , s[maxN] , f[1005][1005] ;

int main()
{
    srand(time(nullptr));
    freopen("Test.inp" , "r" , stdin) ;
    string st = "What are you doing while sending \"What are you doing at the end of the world\? Are you busy\? Will you save us\?\"\? Are you busy\? Will you send \"What are you doing at the end of the world\? Are you busy\? Will you save us\?\"\?" ;
    string st2 = "What are you doing at the end of the world\? Are you busy\? Will you save us\?" ;
    string st3 = "What are you doing while sending \"\"\? Are you busy\? Will you send \"\"\?";
    cout << st.length() << " " << st2.length() << " " << st3.length() ;
    return 0 ;
}
