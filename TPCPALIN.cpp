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
#define base 3210121
#define maxN 505

using namespace std ;

string sta , stb ;
int na , nb , f[maxN][maxN][maxN] , a[maxN] , b[maxN] ;
bool dd[maxN][maxN][maxN] ;

void enter()
{
    cin >> sta ;
    cin >> stb ;
    na = sta.length() ;
    nb = stb.length() ;
    forinc(i,1,na) a[i] = (int) sta[i-1] ;
    forinc(i,1,nb) b[i] = (int) stb[i-1] ;
}

int get_right_b(int left_a , int right_a , int left_b) {return na + nb + 2 - left_a - left_b - right_a; }

int cal(int left_a , int right_a , int left_b)
{
    if (dd[left_a][right_a][left_b]) return f[left_a][right_a][left_b] ;
    int right_b = get_right_b(left_a , right_a , left_b) ; dd[left_a][right_a][left_b] = true ;
    if (left_a + 1 > right_a - 1 && left_b + 1 > right_b - 1) {
        f[left_a][right_a][left_b] = 1 ;
        return 1 ;
    }
    if ((left_a + 1 == right_a - 1 && left_b + 1 > right_b-1) || (left_a + 1 > right_a - 1 && left_b + 1 == right_b - 1)) {
        f[left_a][right_a][left_b] = 1 ;
        return 1 ;
    }
    long long res = 0 ;
    if (left_a + 1 < right_a - 1 && left_a + 1 <= na && right_a - 1 >= 1 && a[left_a+1] == a[right_a-1]) res += cal(left_a+1,right_a-1,left_b) , res %= base ;
    if (left_b + 1 < right_b - 1 && left_b + 1 <= nb && right_b - 1 >= 1 && b[left_b+1] == b[right_b-1]) res += cal(left_a,right_a,left_b+1) , res %= base ;
    if (left_a + 1 <= right_a - 1 && left_b + 1 <= right_b - 1) {
        if (left_a + 1 <= na && right_b - 1 >= 1 && a[left_a+1] == b[right_b-1]) res += cal(left_a+1,right_a,left_b) ,  res %= base ;
        if (left_b + 1 <= nb && right_a - 1 >= 1 && b[left_b+1] == a[right_a-1]) res += cal(left_a,right_a-1,left_b+1) , res %= base ;
    }
    f[left_a][right_a][left_b] = res ;
    return res ;
}

int main()
{
    //freopen("TPCPALIN.inp" , "r" , stdin) ;
    enter() ;
    cout << cal(0,na+1,0) ;
    return 0 ;
}
