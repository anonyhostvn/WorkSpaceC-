#include <bits/stdc++.h>

using namespace std ; 

string st ; 

void reverse(string &s) {
	string res = "" ; 
	for (char c : s) res = c + res ; 
	s.erase () ; 
	for (char c : res) s += c ; 
}

void enter () {
	cin >> st ; 
	reverse (st) ; 
	cout << st ; 
}