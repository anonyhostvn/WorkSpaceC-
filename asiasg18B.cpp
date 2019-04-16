#include <bits/stdc++.h>
#define maxN 1000005
#ifdef OFF_LINE
#include <debug.h>
#endif

using namespace std ;

int n , k ; 
vector<int> nxt[maxN] ; 

void enter () {
	cin >> n >> k ; 
	for (int i = 0 ; i < k ; i ++) {
		int u , v ; 
		cin >> u >> v ; 
		nxt[u].push_back(v) ; 
		nxt[v].push_back(u) ; 
	}
}

int group[maxN] ; 

void dfs (int u , int id) {
	group[u] = id ; 
	for (int v : nxt[u]) if (!group[v]) dfs(v,id) ; 
}

void process () {
	int cnt = 1 ; 
	for (int i = 1 ; i <= n ; i ++) if (!group[i]) dfs(i,++cnt) ;  
	//for (int i = 1 ; i <= n ; i++) debug(group[i]) ; 
	for (int i = 1 ; i <= (n / 2) ; i ++) if (group[i] != group[n-i+1]) {
		cout << "No" ; 
		return ; 
	}
	cout << "Yes" ; 
}

void code () {
	enter () ; 
	process () ; 
}

int main () {
	code () ; 
	#ifdef OFF_LINE
	system("echo.") ; 
	system("pause") ;
	#endif
    return 0 ;
}
