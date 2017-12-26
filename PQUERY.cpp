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
#define ooll (long long) 1e15
#define ooit (int) 2e9
#define maxN 1000005

template <class _T> bool maximize(_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize(_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

using namespace std ;

int n , a[maxN] ;
string st ;

///_________________________________________________________________________________________________________________________________________///
///                                                     Fast IO                                                                             ///
///_________________________________________________________________________________________________________________________________________///

int ReadInt() {
    char c ; int res = 0 ;
    for (c = getchar() ; c < '0' || c > '9' ; c = getchar()) ;
    for ( ; c >= '0' && c <= '9' ; c = getchar()) res*= 10 , res += c - '0' ;
    return res ;
}

char ReadChar() {
    char c ;
    for (c = getchar() ; c != 'Q' && c != 'C' ; c = getchar()) ;
    return c ;
}

void WriteInt(int x)
{
    if (x > 9) WriteInt(x / 10);
    putchar(x % 10 + '0');
}


///_________________________________________________________________________________________________________________________________________///
///                                                     Enter Input                                                                         ///
///_________________________________________________________________________________________________________________________________________///

void enter() {
    char c ;
    for (c = getchar() ; c == '(' || c == ')' ; c = getchar()) a[++n] = c == '(' ? 1 : -1 ;
}

///_________________________________________________________________________________________________________________________________________///
///                                                    Build Interval                                                                       ///
///_________________________________________________________________________________________________________________________________________///

struct TSegmentTree{

    struct node { int left_ , right_ , sum , q  ; };

    node val[4*maxN] ;
    int id_node[maxN] ;

    void init(int s , int l , int r) {
        val[s].left_ = l ; val[s].right_ = r ;
        if (l == r) { id_node[l] = s ; val[s].sum = a[l] ; val[s].q = a[l] ; return ; }
        int mid = (l+r) / 2 ;
        init(2 * s , l , mid) ;
        init(2 * s + 1 , mid + 1 ,r ) ;
        val[s].sum = val[2 * s].sum + val[2 * s + 1].sum ;
        val[s].q = min(val[2*s].q , val[2*s+1].q + val[2*s].sum) ;
    }

    void Increment(int s , int x) {
        val[s].sum += x ; val[s].q += x ;
        for (s /= 2 ; s >= 1 ; s /= 2) {
            val[s].sum += x ;
            val[s].q = min(val[2 * s].q , val[2 * s].sum + val[2 * s + 1].q) ;
        }
    }

    int solve(int id) {
        if (a[id] < 0) return 0 ;
        int y = -1 , z = -1 , sum = a[id] , tsum = 0  ;

        for (int u = id_node[id] ; u > 0 ; u /= 2) if (u % 2 == 0)  {
            if (sum + val[u+1].q < 0) { y = u  + 1 ;  break ; }
            if (sum + val[u+1].q == 0) z = u + 1 ;
            sum += val[u+1].sum ;
        }

        if (y > -1) while (val[y].left_ < val[y].right_)
            if (sum + val[2 * y].q < 0) y *= 2 ;
            else {
                if (sum + val[2*y].q == 0) z = 2 * y ;
                sum += val[2*y].sum ;
                y *= 2 ; y ++ ;
            }

        if (z != -1) while (val[z].left_ < val[z].right_) z = (val[2 * z].sum + val[2 * z + 1].q == val[z].q) ? 2 * z + 1 : 2 * z ;
        return (z == -1) ? 0 : val[z].right_ - id + 1 ;
    }
} tree ;

///_________________________________________________________________________________________________________________________________________///
///                                                     Xu Li                                                                               ///
///_________________________________________________________________________________________________________________________________________///

void process() {
    tree.init(1,1,n) ;
    int q = ReadInt() ;
    forinc(i,1,q) {
        char ch = ReadChar() ; int x = ReadInt() ;
        if (ch == 'Q') WriteInt(tree.solve(x)) , putchar('\n') ;
        else a[x] = -a[x] , tree.Increment(tree.id_node[x] , a[x] == 1 ? 2 : -2) ;
    }
}

int main() {
    freopen("PQUERY.inp" ,"r" , stdin) ;
    freopen("PQUERY.out" , "w" , stdout) ;
    enter () ;
    process () ;
    return 0 ;
}
