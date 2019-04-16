#include <bits/stdc++.h>
#define maxN 205

using namespace std ; 

bool isPrime [maxN] ; 
int n ; 

void estharone () {
	memset (isPrime , 1 , sizeof(isPrime)) ; 
	isPrime[0] = 0 ; isPrime[1] = 0 ; 

	for (int i = 2 ; i <= sqrt (200) ; i ++) {
		int j = i * i ; 
		while (j <= 200) {
			isPrime[j] = 0 ; 
			j += i ; 
		}
	}
}

bool isSemiPrime[maxN] ; 

void buildSemiPrime() {
	estharone () ; 
	for (int i = 1 ; i <= 200 ; i ++) 
		for (int j = i + 1 ; j <= 200 ; j ++) if (isPrime[i] && isPrime[j] && i * j <= 200) isSemiPrime[i * j] = true ; 
}

void enter () {
	cin >> n ; 
	for (int i = 2 ; i <= n ; i ++) if (isSemiPrime[i] && isSemiPrime[n-i]) {
		cout << "YES" << endl ; 
		return ; 
	}
	cout << "NO" << endl ; 
}

void code () {
	buildSemiPrime () ; 
	int T = 0 ; 
	cin >> T ; 
	while (T--) enter () ;
}

int main () {
	code () ; 
	return 0 ; 
}