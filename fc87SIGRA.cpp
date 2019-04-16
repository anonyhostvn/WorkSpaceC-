#include <bits/stdc++.h>  
#define maxN 100005

using namespace std ; 

int n , m  ; 
vector<int> nxt[maxN] ; 

void enter () {
	cin >> n >> m ; 
	for (int i = 1 ; i <= m ; i ++) {
		int u , v ; 
		cin >> u >> v ; 
		nxt[u].push_back(v) ; 
		nxt[v].push_back(u) ; 
	}
}

int criticalEdge = 0 , low[maxN] , num[maxN] , cntVer = 0  ; 

void dfs (int u , int parU) {
	low[u] = num[u] = ++cntVer ; 
	for (int v : nxt[u]) if (v != parU) {
		if (num[v]) low[u] = min(low[u] , num[v]) ; 
		else {
			dfs(v,u) ; 
			low[u] = min(low[u] , low[v]) ; 
			if (low[v] >= num[v]) criticalEdge ++ ; 
		}
	} 
}

void process () {
	dfs(1,0) ; 
	//for (int i = 1 ; i <= n ; i ++) cout << low[i] << " " ; 
	cout << criticalEdge << endl ; 
}

void code () {
	enter () ; 
	process () ; 
}

int main () {
	code () ; 
	//system("pause") ; 
	return 0 ; 
}