#include <bits/stdc++.h> 

#define maxN 200005

using namespace std ; 

int n , k , a[maxN] ;

void enter () {
	scanf ("%d%d" , &n , &k) ; 
	for (int i = 1 ; i <= n ; i ++) scanf("%d" , &a[i]) ;
}

long long f[maxN] ; 

void buildF () {
	sort (a + 1 , a + 1 + n) ;
	int id = n ; 
	for (int i = a[n] ; i > 0 ; i --) {
		while (id > 1 && a[id-1] == i) id -- ;
		f[i] = f[i+1] + (n-id+1) ; 
	}
}

void process (){
	buildF () ; 

	int sliceCut = a[n] , res = 0 ;

	while (sliceCut > a[1]) {
		//cout << sliceCut << endl ; 
		int l = 0 , r = sliceCut , newSliceCut = 0 ; 
		while (l <= r) {
			int mid = (l+r) / 2 ; 
			if (f[mid+1] - f[sliceCut+1] > k) l = mid + 1 ; 
			else {
				newSliceCut = mid ; 
				r = mid - 1 ; 	
			}
		}

		res ++ ; 
		sliceCut = newSliceCut ; 
	}

	cout << res << endl ; 
}

void code () {
	enter () ; 
	process () ; 
}

int main () {
	code () ; 
	return 0 ; 
}