#include <bits/stdc++.h>

using namespace std ; 

long long s , a , b , c  ; 
int T ; 

int main () {
	cin >> T ; 
	for (int i = 1 ; i <= T ; i ++) {
		cin >> s >> a >> b >> c ; 
		long long numPro = s / c ; numPro += (numPro / a) * b ; 
		cout << numPro << endl ; 
	}
	return 0 ; 
}