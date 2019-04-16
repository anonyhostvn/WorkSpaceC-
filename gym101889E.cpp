#include <bits/stdc++.h>
#define maxN 1005
#ifdef OFF_LINE
#include <debug.h>
#endif

template <class _T> bool minimize(_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

using namespace std ;

const int oo = 1000000 ; 
string st ; 
int divisor = 0 , a[maxN] , n ; 

void enter () {
	cin >> st ; 
	n = st.length() ; 
	for (int i = 1 ; i <= n ; i ++) a[i] = (st[i-1] != '?') ? ((int) st[i-1] - (int) '0') : -1 ; 
	cin >> divisor ; 
}

int powerTen[maxN] , addModul[maxN] , m = 0 , mustFind[maxN] ; 
int recentModul = 0 ; 

void prepare () {
	powerTen[0] = 1; 
	for (int i = 1 ; i <= 1000 ; i ++) powerTen[i] = (powerTen[i-1] * 10) % divisor ; 
	for (int i = 1 ; i <= n ; i ++) if (a[i] > -1) recentModul += (a[i] * powerTen[n-i]) % divisor ;
	int b[maxN] ; 
	for (int i = 1 ; i <= n ; i ++) if (a[i] == -1) b[++m] = n - i + 1 ; 
	for (int i = 1 ; i <= m ; i ++) mustFind[i] = b[m-i+1] ; 
}

int f[maxN][maxN] ; 

void DynamicProgram () {
	for (int i = 1 ; i <= m ; i ++) 
		for (int j = 0 ; j <= divisor ; j ++) f[i][j] = oo ; 
	f[0][recentModul] = 0 ; 
	for (int i = 0 ; i < m ; i ++) 
		for (int j = 0 ; j <= divisor ; j ++) if (f[i][j] < oo) {
			for (int dig = ((mustFind[i] < n) ? 0 : 1) ; dig < 10 ; dig ++) 
				minimize(f[i+1][(j + dig * powerTen[mustFind[i+1]-1]) % divisor] , dig) ;
		}
}

int digitRes[maxN] ; 

void Trace (int id) {
	digitRes[id] = f[id][0] ; 
}

int main () {
	#ifdef OFF_LINE
	system("echo.") ; 
	system("pause") ; 
	#endif
    return 0 ;
}
