#include <bits/stdc++.h>
#ifdef OFF_LINE
#include <debug.h>
#endif

using namespace std ;

string sta , stb ; 
int nA , nB ; 

char upCase (char c) {
	if (c >= 'A' && c <= 'Z') return c ; 
	return (char) ((int) c - 32) ; 
}

bool canTransform () {
	int na = sta.length() , nb = stb.length() ; 
}

int main () {
	int Q = 0 ; 
	cin >> Q ;
	for (int i = 1 ; i <= Q ; i ++) {
		cin >> sta >> stb ; 
		if (canTransform()) cout << "YES" ; else cout << "NO" ; 
		cout << endl ; 
	}
	#ifdef OFF_LINE
	system("echo.") ; 
	system("pause") ; 
	#endif
    return 0 ;
}
