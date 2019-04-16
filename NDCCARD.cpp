#include <bits/stdc++.h>
#define maxN 100005 
#define maxS 500005

using namespace std ; 

template <class _T> bool maximize (_T &a , _T b) {return a < b ? a = b , 1 : 0 ; } 
template <class _T> bool minimize (_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }


int n , a[maxN] , m ; 

void enter () {
	scanf("%d%d" , &n , &m) ; 
	for (int i = 1 ; i <= n ; i ++) scanf("%d" , &a[i]) ; 
}

namespace Way_1 {
	int f[maxS] ; 
	void process () {
		sort(a + 1 , a + 1 + n) ; 
		for (int i = 1 ; i <= n ; i ++ ) f[a[i]] = a[i] ; 
		for (int i = 2 ; i <= 500000 ; i ++) maximize(f[i],f[i-1]) ; 

		int sum = 0 ;  
		for (int i = 1 ; i < n ; i ++) 
			for (int j = i + 1 ; j <= n ; j ++) if (a[i] + a[j] < m) {
				int maxNum= m - a[i] - a[j] , num = 0 ;
				if (f[maxNum] == a[j]) {
					 maxNum = f[maxNum] - 1; 
					 if (f[maxNum] == a[i]) num = f[f[maxNum] - 1] ; else num = f[maxNum] ;  
				} else num = f[maxNum] ; 
				if (sum < a[i] + a[j] + num) sum = a[i] + a[j] + num ; 
			}	

		printf("%d" , sum) ; 
	}
}

void code () {
	enter () ; 
	Way_1 :: process () ; 	
}

int main () {
	//#ifdef OFF_LINE
	//freopen("NDCCARD.inp" , "r" , stdin) ; 
	//freopen("NDCCARD.out" , "w" , stdout) ; 
	//#endif
	code () ; 
	return 0 ; 
}