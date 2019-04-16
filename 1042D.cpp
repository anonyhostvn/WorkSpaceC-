#include <bits/stdc++.h>
#define maxN 200005

using namespace std ; 

int n , a[maxN] ;
long long patternT ;  

void enter () {
	cin >> n >> patternT ; 
	for (int i = 1 ; i <= n ; i ++) cin >> a[i] ; 
}

long long sum[maxN] , subSum[maxN] ;

void makeSumArr () {
	for (int i = 1 ; i <= n ; i ++) sum[i] = sum[i-1] + a[i] ; 
	for (int i = 0 ; i <= n ; i ++) subSum[i] = sum[i] - patternT ; 
}

int maxValue ; 

void makeMinimum () {
	map <long long , int> mapValue ; 
	for (int i = 0 ; i <= n ; i ++) mapValue[sum[i]] = 0 , mapValue[subSum[i]] = 0 ;
	for (auto &tmp : mapValue) tmp.second = ++maxValue ; 
	for (int i = 0 ; i <= n ; i ++) sum[i] = mapValue[sum[i]] , subSum[i] = mapValue[subSum[i]] ;  
}

struct binaryIndexTree {
	int BIT [3 * maxN] ; 

	binaryIndexTree () {
		memset (BIT , 0 , sizeof(BIT)) ; 
	}

	void update (int id , int x) {
		for ( ; id > 0 ; id -= id & (-id)) BIT[id] += x ; 
	}  

	int get (int id ) {
		int res = 0 ; 
		for ( ; id <= maxValue ; id += id & (-id)) res += BIT[id] ; 
		return res ;
	}

} ; 

binaryIndexTree firstTree  ; 

long long  countAnswer () {
	long long res = 0 ; 
	firstTree.update (sum[0] , 1) ;  
	for (int i = 1 ; i <= n ; i ++) {
		res += firstTree.get (subSum[i] + 1) ;
		firstTree.update (sum[i] , 1) ;  
	}
	return res ;  
}

void process ()  {
	makeSumArr () ; 
	makeMinimum () ; 
	cout << countAnswer () << endl ; 
}

void code () {
	enter () ; 
	process () ; 
}

int main () {
	#ifdef OFF_LINE 
	freopen("test.inp" , "r" , stdin) ; 
	freopen("test.out" , "w" , stdout) ; 
	#endif 
	code () ; 
	return 0 ; 
}