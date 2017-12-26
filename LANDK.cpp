#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)
#define forv(j,u) for (int j = 0 ; j < u.size() ; j++)

using namespace std ;

int k ,n ,  nxt[2001][2001] ;
long long s[2001][2001] , a[2001][2001] ;
bool ok = true ;

int enter()
{
    cin >> k >> n ;
    forinc(i,1,n)
    forinc(j,1,n) {
        cin >> a[i][j];
        if (a[i][j] >= k && a[i][j] <= 2 * k){
            cout << j << " " << i << " " << j << " " << i ;
            ok = false ;
            return 0 ;
        }
        s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + a[i][j] ;
        if (s[i][j] >= k && s[i][j] <= 2 * k){
            cout << 1 << " " << 1 << " " << j << " " << i ;
            ok = false ;
            return 0 ;
        }
    }
    return 0 ;
}

int prepare()
{
    forinc(i,1,n){
        int j = 1 ;
        long long sum = 0 ;
        forinc(t,1,n) {
            while (sum + a[t][i] > 2 * k && j < t){
                nxt[j][i] = t-1 ;
                sum -= a[j][i] ;
                j++ ;
            }
            if (a[t][i] <= 2 *k ) sum += a[t][i] ; else sum = 0 ;
        }
        forinc(t,j,n) nxt[t][i] = n ;
    }
    return 0 ;
}

long long get (int x , int y , int u , int v)
{
    return s[u][v] - s[x-1][v] - s[u][y-1] + s[x-1][y-1] ;
}

int lside[2001] , rside[2001] ;
long long b[2001] ;

int histogram()
{
    forinc(i,1,n) {
        rside[i] = 0 ;
        lside[i] = 0 ;
    }
    int st[2001] , top = 0 ; st[0] = 0 ;
    forinc(i,1,n){
        while (top > 0 && b[i] <=  b[st[top]]) top -- ;
        lside[i] = st[top] + 1 ;
        st[++top] = i ;
    }
    top = 0 ; st[0] = n + 1;
    fordec(i,n,1){
        while (top > 0 && b[i] <= b[st[top]]) top -- ;
        rside[i] = st[top] -1 ;
        st[++top] = i ;
    }
    return 0 ;
}

bool cget(int x , int y , int u , int v)
{
    while (get(x,y,u,v) > 2 * k) v-- ;
    cout << y << " " << x << " " << v << " " << u ;
    return 0 ;
}

int process()
{
    if (!ok) return 0 ;
    prepare() ;
    forinc(i,1,n){
        forinc(j,1,n) if (nxt[i][j] >= i) b[j] = get(i,j,nxt[i][j],j) ; else b[j] = 0 ;
        histogram() ;
        forinc(j,1,n)
        if (b[j] > 0 && get(i,lside[j],nxt[i][j],rside[j]) > k) {
            cget(i,lside[j],nxt[i][j],rside[j]) ;
            return 0 ;
        }
    }
    cout << "NIE" ;
    return 0 ;
}

int main()
{
    //freopen("LANDK.inp" , "r" , stdin) ;
    enter() ;
    process() ;
    return 0;
}
