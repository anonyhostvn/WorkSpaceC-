#include<bits/stdc++.h> 
using namespace std ; 

template <class _T> bool maximize (_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize (_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

int S[3] ; 

void enter () {
	for (int i = 0 ; i < 3 ; i ++) scanf("%d" , &S[i]) ; 
}

namespace Dynamic {

	int f[4][100] ; 

	void process () {
		f[0][0] = 1 ; 
		for (int i = 0 ; i <= 2 ; i ++) 
			for (int j = 0 ; j <= 100 ; j ++) if (f[i][j] > 0) 
				for (int k = 1 ; k <= S[i] ; k ++ ) f[i+1][j + k] += f[i][j] ;  

		int max_appear = 0 , res = 0 ; 
		for (int i = 0 ; i <= 100 ; i ++) if (maximize(max_appear , f[3][i])) res = i ; 
		printf("%d\n", res) ;
	}

}

namespace Back_track {
	int f[100] ; 
	void backtrack (int num_dice , int sum) {
		if (num_dice == 3) {
			f[sum] ++ ;
			return ; 
		}

		for (int i = 1 ; i <= S[num_dice] ; i ++)  backtrack (num_dice + 1 , sum + i) ; 
	}


	void process () {
		backtrack(0,0) ; 
		int max_appear = 0 , res = 0 ; 
		for (int i = 1 ; i <= 100 ; i ++) if (maximize(max_appear,f[i])) res = i ; 
		printf("%d\n", res);
	}
}

void code () {
	enter () ;
	Back_track :: process() ; 
}

int main () {
	//freopen("BONES.inp" , "r" , stdin) ; 
	//freopen("BONES.out" , "w" , stdout) ; 
	code () ; 
	//system("pause");
	return 0 ; 
}