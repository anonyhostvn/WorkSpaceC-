#include <bits/stdc++.h> 
#define maxN 1005

using namespace std ; 

int n , m , q , a[maxN][maxN] ; 

int fastRead() {
    char c ; int res = 0 ; bool negative = false ; 
    for (c = getchar() ; c < '0' || c > '9' ; c = getchar()) if (c == '-') negative = true ;
    for ( ; c >= '0' && c <= '9' ; c = getchar()) res*= 10 , res += c - '0' ;
    return (negative) ? -res : res ;
}

void enter () {
	n = fastRead() ; m = fastRead() ; q = fastRead () ; 
	for (int i = 1 ; i <= n ; i ++) 
		for (int j = 1 ; j <= m ; j ++) a[i][j] = fastRead() ; 
}

long long f[maxN][maxN] , sum[maxN][maxN]  ; 

void queryUpdate (int x , int y , int u , int v , int val) {
	f[x][y] += val ; 
	f[x][v+1] -= val ; 
	f[u+1][y] -= val ; 
	f[u+1][v+1] += val ; 
}

void doQuery () {
	for (int query = 1 ; query <= q ; query ++) {
		int x = fastRead() , y = fastRead() , u = fastRead() , v = fastRead() , val = fastRead() ; 
		//cout << x << " " << y << " " << u << " " << v << " " << val << endl ; 
		queryUpdate (x,y,u,v,val) ; 
	}
	for (int i = 1 ; i <= n ; i ++) 
		for (int j = 1 ; j <= m ; j ++) sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + f[i][j] ; 
}

void process () {
	doQuery () ; 
	for (int i = 1 ; i <= n ; i ++) {
		for (int j = 1 ; j <= m ; j ++) cout << sum[i][j] + a[i][j] << " " ; 
		cout << "\n" ; 
	}
}

void code () {
	enter() ; 
	process () ; 
}	

int main () {
	code () ; 
	#ifdef OFF_LINE
	system("pause") ; 
	#endif
	return 0 ; 
}