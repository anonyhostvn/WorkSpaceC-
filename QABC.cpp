#include <bits/stdc++.h>

using namespace std ; 

#define maxN 100005

int n , a[maxN] ; 

bool enter () {
	cin >> n ; 
	for (int i = 1 ; i <= n ; i ++) cin >> a[i] ; 
	for (int i = 1 ; i <= n ; i ++) {
		int x ; 
		cin >> x ; 
		a[i] = x - a[i] ; 
		if (a[i] < 0) return false ; 
	}
	return true ; 
}

bool checkImposs () {
	if (!enter()) return false ; 
	for (int i = 3 ; i <= n ; i ++) {
		a[i] -= a[i-2] * 3 ; 
		a[i-1] -= a[i-2] * 2 ; 
		a[i-2] = 0 ; 
	}

	for (int i = 1 ; i <= n ; i ++) if (a[i] != 0) return false ; 
	return true ; 
}

void process () {
	int T = 0 ; 
	cin >> T ; 
	while (T--) cout << ((checkImposs()) ? "TAK" : "NIE") << endl ; 
}

int main () {
	process () ; 
	return 0 ; 
}