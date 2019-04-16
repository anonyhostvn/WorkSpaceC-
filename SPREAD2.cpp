#include <bits/stdc++.h>

using namespace std ; 

#define maxN 100005

int n ; long long  f[maxN] ; 

void enter () {
	cin >> n ; 
	for (int i = 1 ; i <= n ; i ++) {
		int x ; cin >> x ; 
		f[i] = f[i-1] + x ; 
	}
}

void process () {
	long long recentID = 1 , res = 0 ; 
	while (recentID < n) {
		res ++ ; 
		recentID += f[recentID] ; 
	}
	cout << res << endl ; 
}

void code () {
	int T = 0 ; 
	cin >> T ; 
	while (T--) {
		enter () ; 
		process() ; 
	}
}

int main () {
	code () ; 
	return 0 ; 
}