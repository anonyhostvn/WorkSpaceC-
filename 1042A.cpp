#include <bits/stdc++.h>
#ifdef OFF_LINE
#include <debug.h>
#endif
#define maxN 105

using namespace std ;

template <class _T> bool maximize(_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize(_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

int n , a[maxN] , m , maxSeat = 0 ; 

int main () {
	cin >> n >> m ; 
	for (int i = 1 ; i <= n ; i ++) {
		cin >> a[i] ; 
		maximize(maxSeat,a[i]) ; 
	}


	int maxRes = maxSeat + m , numSeat = 0 , minRes = 1000000000 ;
	for (int i = 1 ; i <= n ; i ++) numSeat += maxSeat - a[i] ; 
	if (numSeat >= m) minRes = maxSeat ; else {
		int add = (m - numSeat) % n == 0 ? (m-numSeat) / n : (m-numSeat) / n + 1 ;
		minRes = maxSeat + add ;  
	}

	cout << minRes << " " << maxRes << endl ; 	

	#ifdef OFF_LINE
	system("echo.") ; 
	system("pause") ; 
	#endif
    return 0 ;
}
