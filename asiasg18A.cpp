#include <bits/stdc++.h> 
#ifdef OFF_LINE 
#include <debug.h>
#endif
#define pii pair <int ,int> 
#define maxN 105

using namespace std ; 

int n ; 
string patternString = "!ICPCASIASG" ; 
char aTable[maxN][maxN] ; 

void enter () {
	cin >> n ; 
	for (int i = 1 ; i <= n ; i ++) 
		for (int j = 1 ; j <= n ; j ++) {
			char c ; 
			cin >> c ; 
			aTable [i][j] = c ; 
		}
}

bool checkCoord (int X) {
	return (X > 0 && X <= n) ; 
} 

bool reachIt [maxN][maxN][15] ; 
queue<pair<pii , int> >  qStep ; 

int goX[4] = {-1 , +1 , -2 , +2} ; 
int goY[4] = {+2 , -2 , -1 , +1} ; 

void bfs () {
	for (int i = 1 ; i <= n ; i ++) 
		for (int j = 1 ; j <= n ; j ++) if (aTable[i][j] == 'I') 
			reachIt[i][j][1] = true , qStep.push({{i,j} , 1}) ; 

	while (!qStep.empty() ) {
		pair <pii , int> tmp = qStep.front () ; qStep.pop() ; 
		int recentX = tmp.first.first , recentY = tmp.first.second , pos = tmp.second ;
		//debug(recentX , recentY , pos) ; 
		if (pos == 10) return ; 

		for (int i = 0 ; i < 2 ; i ++) 
			for (int j = 0 ; j < 2 ; j ++) {
				int tX = recentX + goX[i] , tY = recentY + goY[j] ; 
				//debug (tX , tY) ; 
				if (checkCoord(tX) && checkCoord(tY) && aTable[tX][tY] == patternString[pos + 1] && !reachIt[tX][tY][pos + 1]) {
					qStep.push({{tX,tY} , pos +1}) ;
					reachIt[tX][tY][pos + 1] = true ;  
				}
			} 

		for (int i = 2 ; i < 4 ; i ++) 
			for (int j = 2 ; j < 4 ; j ++) {
				int tX = recentX + goX[i] , tY = recentY + goY[j] ; 
				//debug(tX , tY) ; 
				if (checkCoord(tX) && checkCoord(tY) && aTable[tX][tY] == patternString[pos + 1] && !reachIt[tX][tY][pos + 1]) {
					qStep.push({{tX,tY} , pos +1}) ;
					reachIt[tX][tY][pos + 1] = true ;  
				}
			} 
	}	
}

void process () {
	bfs () ; 
	for (int i = 1 ; i <= n ; i ++) 
		for (int j = 1 ; j <= n ; j ++) if (reachIt[i][j][10]) {
			cout << "YES" << endl ; 
			return ; 
		}
	cout << "NO" ; 
}

void code () {
	enter () ; 
	process () ; 
}

int main () {
	#ifdef OFF_LINE 
		//freopen("asiad.inp" , "r" , stdin) ;  
		//freopen("asiad.out" , "w" , stdout) ; 
	#endif
	code () ; 
	//system ("pause") ; 
	return 0 ; 
}