#include <bits/stdc++.h>

using namespace std; 

long long m , n ; 

int main () {
	cin >> n >> m ; 
	long long minIsolate = 0 , maxIsolate = 0 ;

	for (int i = 1 ; i <= n ; i ++) if ((long long) i * (i + 1) / 2 > m) {
		long long remain = m - i * (i - 1) / 2 ;
		maxIsolate = n - i - (int) (remain > 0) ;
		break ;     
	}

	if (m == 0) maxIsolate = n ; 

	minIsolate = max((long long) 0 , n - m * 2) ; 
	cout << minIsolate << " " << maxIsolate << endl ; 
	return 0; 
}