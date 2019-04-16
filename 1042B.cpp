#include <bits/stdc++.h>
#ifdef OFF_LINE
#include <debug.h>
#endif
#define maxN 1005

template <class _T> bool maximize(_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize(_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

using namespace std ;

int n , price [maxN] , vita[maxN];

int onBit (int x , int id) {
	return ( (1 << id) | x) ; 
}

int getBit(int x , int id) {
	return ((x >> id) & 1) ; 
}

void enter () {
	cin >> n ; 
	for (int i = 1 ; i <= n ; i ++) {
		string vitamin ; 
		cin >> price[i] >> vitamin ;
		for (char c : vitamin) vita[i] = onBit(vita[i] , (int) c - (int) 'A') ; 
	}
}

int f[maxN][10] ; 
const int oo = 1000000000 ; 

void DynamicProgram () {
	for (int i = 0 ; i <= n ; i ++) 
		for (int j = 0 ; j <= 7 ; j ++) f[i][j] = oo ; 
	f[0][0] = 0 ; 
	for (int i = 0 ; i < n ; i ++) 
		for (int j = 0 ; j <= 7 ; j ++) if (f[i][j] < oo) {
			//debug(i,j) ; 
			minimize (f[i+1][j] , f[i][j]) ;  
			int nxt = j ; 
			for (int v = 0 ; v < 3 ; v ++) if (getBit(vita[i+1],v)) nxt = onBit(nxt , v) ; 
			minimize(f[i+1][nxt] , f[i][j] + price[i+1]) ;  
		}

	cout << ((f[n][7] < oo) ? f[n][7] : -1) << endl ; 
}

void code () { 
	enter () ; 
	DynamicProgram () ; 
}

int main () {
	code () ; 
	#ifdef OFF_LINE
	system("echo.") ; 
	system("pause") ; 
	#endif
    return 0 ;
}
