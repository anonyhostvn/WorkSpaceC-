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

template <class _T> bool maximize(_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize(_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

const int ooit = 2e9 ;
const long long ooll = 1e15 ;

using namespace std ;

int q ;
bool in_queue[5] ;
deque<int> Tclass , Tstu[5] ;

void process_query_1() {
    int x , y ; cin >> x >> y ;
    if (!in_queue[x]) Tclass.push_back(x) , in_queue[x] = true  ;
    Tstu[x].push_back(y) ;
}

void process_query_2() {
    int rec =  Tclass.front() ;
    cout << rec << " " << Tstu[rec].front() << endl ; Tstu[rec].pop_front() ;
    if (!Tstu[rec].size()) Tclass.pop_front() , in_queue[rec] = false ;
}

void enter () {
    cin >> q ;
    forinc(i,1,q) {
        char query ; cin >> query ;
        if (query == 'E') process_query_1 () ; else process_query_2() ;
    }
}

int main () {
    freopen("SCHOOL.inp" , "r" , stdin) ;
    freopen("SCHOOL.out" , "w" , stdout) ;
    enter () ;
    return 0 ;
}
