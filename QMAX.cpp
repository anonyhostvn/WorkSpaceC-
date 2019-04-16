#include <bits/stdc++.h>
#define maxN 50004
#define debug(x) std :: cerr << #x << " : " << x << endl ;

using namespace std ;

int n , m ;

void enter () {
	scanf("%d%d" , &n , &m) ;
}

int f[maxN] ;

void doFirstQuery () {
	for (int i = 1 ; i <= m ; i ++) {
		int u , v , k;
		scanf("%d%d%d" , &u , &v , &k) ;
		f[u] += k ; f[v+1] -= k ;
	}
	for (int i = 1 ; i <= n ; i ++) f[i] += f[i-1] ;
}

struct SegmentTree  {
	int val[4 * maxN] , tran[4 * maxN] ;

	SegmentTree () {
		memset(val , 0 , sizeof(val)) ;
		memset(tran , 0 , sizeof(tran)) ;
	}

	void updateSingle (int s , int l , int r , int id , int k) {
		if (r < id || id < l) return ;
		if (l == r) {
			val[s] = k ;
			return ;
		}
		int mid = (l+r) / 2 ;
		updateSingle(2 * s , l , mid , id , k) ;
		updateSingle(2 * s + 1 , mid + 1 , r , id , k) ;
		val[s] = max(val[2*s] , val[2 * s + 1]) ;
	}

	int getMaxRange(int s , int l , int r , int u , int v) {
		if (r < u || v < l) return 0 ;
		if (u <= l && r <= v) return val[s] ;
		int mid = (l+r) / 2 ;
		return max(getMaxRange(2 * s , l , mid , u , v) , getMaxRange(2 * s + 1 , mid + 1 , r , u , v)) ;
	}
} ;

SegmentTree greenTree ;

void doSecondQuery () {
	for (int i = 1 ; i <= n ; i ++) greenTree.updateSingle(1,1,n,i,f[i]) ;
	int q ; scanf("%d" , &q) ;

	for (int i = 1 ; i <= q ; i ++) {
		int u , v ; scanf("%d%d" , &u , &v) ;
		printf("%d\n" , greenTree.getMaxRange(1,1,n,u,v)) ;
	}
}

void process () {
	doFirstQuery () ;
	doSecondQuery() ;
}

void code () {
	enter () ;
	process () ;
}

int main () {
	#ifdef OFF_LINE
		freopen("QMAX.inp" , "r" , stdin) ;
		freopen("QMAX.out" , "w" , stdout) ;
	#endif

	code () ;

	return 0 ;
}
