#include <bits/stdc++.h>

using namespace std ; 

template <class _T> bool maximize (_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize (_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

int sum_row[6] , sum_col[6] ; 

void enter () {
	for (int i = 1 ; i <= 5 ; i ++) scanf("%d" , &sum_row[i]) ; 
	for (int i = 1 ; i <= 5 ; i ++) scanf("%d" , &sum_col[i]) ; 
}

namespace Way_1 {
	int a[7][7] ;
	bool ok = false , mark[26]  ; 

	void backTrack(int R , int C) {
		if (ok) return ; 
		if (C == 6) {
			if (a[R][6] == sum_row[R]) backTrack(R+1,1) ;
			return ; 
		}
		if (R == 6) { ok = true ; return ; }

		for (int i = 1 ; i <= 25 ; i ++) {
			if (a[R][6] + i > sum_row[R] || a[6][C] + i > sum_col[C]) return ;

			if (!mark[i]) {
				mark[i] = true ; 
				if ((R < 5) || (R == 5 && a[6][C] + i == sum_col[C])) {
					a[R][C] = i ; a[R][6] += i ; a[6][C] += i ; 
					backTrack(R,C+1) ; if (ok) return ; 
					a[R][6] -= i ; a[6][C] -= i ; 
				}
				mark[i] = false ; 
			}
		}
	}
 
	void process () {
		memset(a , 0 , sizeof(a)) ; 
		memset(mark , 0 , sizeof(mark)) ; 
		backTrack(1,1) ; 
		for (int i = 1 ; i <= 5 ; i ++) {
			for (int j = 1 ; j <= 5  ; j ++) printf("%d " , a[i][j]) ; 
			printf("\n");
		}
	}
}

void code () {
	enter () ; 
	Way_1 :: process () ; 
}

int main () {
	#ifdef OFF_LINE
		freopen("VMMTFIVE.inp" , "r" , stdin) ; 
		freopen("VMMTFIVE.out" , "w" , stdout) ; 
	#endif
	code () ; 
	return 0 ; 
}