#include <bits/stdc++.h>
#ifdef OFF_LINE
#include <debug.h>
#endif
#define oo (int) 2000000000

using namespace std ;

template <class _T> bool maximize(_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize(_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

const int maxN = 200005 ;

int n , a[maxN] , numberRemain = 0 ;

void enter () {
	scanf("%d" , &n) ;
	numberRemain = n ;
	for (int i = 1 ; i <= n ; i ++) scanf("%d" , &a[i]) ;
}

vector <int> idZero ;
int idZeroRemain = -1 ;
bool Del[maxN] ;

void combineZero () {
	for (int i = 1 ; i <= n ; i ++) if (a[i] == 0) idZero.push_back(i) ;
	while (idZero.size() > 1) {
		cout << 1 << " " << idZero[idZero.size() - 1] << " " << idZero[idZero.size() - 2] << endl ;
		Del[idZero.back()] = true ; numberRemain -- ;
		idZero.pop_back() ;
	}
	if (idZero.size() > 0) idZeroRemain = idZero.back() ;
}

void process () {
	combineZero () ;

	int cntNegative = 0 , maxNegative = -oo , idMaxNegative = -1 ;

	for (int i = 1 ; i <= n ; i ++) if (!Del[i] && a[i] < 0) {
		cntNegative ++ ;
		if (maximize(maxNegative , a[i])) idMaxNegative = i ;
	}

	if (cntNegative % 2 == 0) {
		if (numberRemain > 1 && idZeroRemain > -1) {
            cout << 2 << " " << idZeroRemain << endl ;
			Del[idZeroRemain] = true ;
			numberRemain -- ;
		}
	} else {
		if (idZeroRemain > -1) {
            cout << 1 << " " << idZeroRemain << " " << idMaxNegative << endl ;
			Del[idZeroRemain] = true ;
			numberRemain -- ;
		}
		if (numberRemain > 1) {
            cout << 2 << " " << idMaxNegative << endl ;
            Del[idMaxNegative] = true ;
            numberRemain -- ;
		}
	}

	vector<int> id ;
	for (int i = 1 ; i <= n ; i ++) if (!Del[i]) id.push_back(i) ;
	if (id.size() > 1) for (int i = 0 ; i < (int) id.size() - 1 ; i ++) cout << 1 << " " << id[i] << " " << id[i+1] << endl ;
}

void code () {
	enter () ;
	process () ;
}

int main () {
	code () ;
    return 0 ;
}
