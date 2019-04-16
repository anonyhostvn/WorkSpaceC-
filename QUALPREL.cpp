#include <bits/stdc++.h>

using namespace std ; 

#define maxN 100005

int n , k ; 

void enter () {
	map<int,int> numberSocre ; 	numberSocre.clear() ; 
	 
	cin >> n >> k ; 
	for (int i = 1 ; i <= n ; i ++) {
		int x ; cin >> x ;
		numberSocre[x] ++ ; 
	}

	//for (auto temp : numberSocre) cout << temp.first << " " << temp.second << endl ; 

	map<int,int>::iterator it = numberSocre.end() , itEnd = numberSocre.begin() ;
	it-- ; //itEnd -- ; 
	//cout << (it == itEnd) << endl ; 

	int cnt = 0 ; 
	for ( ; ; it --) {
		//cout << (*it).first << " " << (*it).second << endl ; 
		cnt += (*it).second ; 
		if (cnt >= k) break ; 
		if (it == numberSocre.begin()) break ; 
	}

	cout << cnt << endl ; 
}

void code () {
	int T ; 
	cin >> T ; 
	while (T--) enter () ; 
}

int main () {
	code () ; 
	return 0 ; 
}