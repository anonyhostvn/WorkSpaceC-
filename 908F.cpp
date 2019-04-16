#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)
#define forv(j,u) for (int j = 0 ; j < u.size() ; j++)
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define mk make_pair
#define pii pair<int,int>
#define pli pair<long long , int>

template <class _T> bool maximize(_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize(_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

const int ooit = 2e9 ;
const long long ooll = 1e15 ;

using namespace std ;

int n ;
vector<int> color[3] ;

void enter () {
    cin >> n ;
    forinc(i,1,n) {
        int p ; char c ; cin >> p >> c ;
        if (c == 'G') color[0].push_back(p) ;
        else if (c == 'R') color[1].push_back(p) ;
        else if (c == 'B') color[2].push_back(p) ;
    }
}

void prepare () {
    forinc(i,0,2) sort(color[i].begin() , color[i].end()) ;
}

long long cost = 0 ;

void conect_green() {
    int last = color[0].front() ;
    for (auto tmp : color[0]) cost += abs(tmp - last) , last = tmp ;
}

int _find(int id , int x) {
    int l = 0 , r = color[id].size() - 1 , res = -1 ;
    while (l <= r) {
        int mid = (l+r) / 2 ;
        if (color[id][mid] <= x) l = mid + 1 , res = mid ; else r = mid - 1 ;
    }
    return res ;
}

void conect_to(int id) {
    long long res = 0 ;
    for (auto tmp : color[id]) {
        int it1 = _find(0,tmp) , it2 = _find(id,tmp) ;

    }
}

void process () {
    prepare () ;
    conect_green() ;
}

int main () {
    return 0 ;
}
