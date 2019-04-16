#include <bits/stdc++.h>
#define maxN 1000005

using namespace std ; 

int n , a[maxN] ; 

void enter () {
	cin >> n ;  
	for (int i = 1 ; i <= n ; i ++) cin >> a[i] ; 
}

void process () {
	int nimSum = 0 ; 
	for (int i = 1 ; i <= n ; i ++) nimSum ^= a[i] ; 
	if (nimSum) cout << 1 ; else cout << 0 ; 
}

void code ()  {
	enter () ; 
	process () ; 
}

int main () {
	code () ; 
	//system("pause") ; 
	return 0 ; 
}