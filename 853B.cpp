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
#define oo (long long) 1e15
#define maxN 100005

using namespace std ;

struct flight{
    int day , place , cost ;
    flight (int d , int p , int c) {
        day = d ; place = p  ; cost = c ;
    }
};

int n , m , k ;
vector<flight> go[2] ;

void enter()
{
    cin >> n >> m >> k ;
    forinc(i,1,m) {
        int d , u , v , c ;
        cin >> d >> u >> v >> c ;
        if (u == 0) go[1].push_back(flight(d,v,c)) ; else go[0].push_back(flight(d,u,c));
    }
}

bool cmp(flight a , flight b) {return a.day < b.day ; } ;
int min_cost[2][maxN]  ;
long long sum_min , S[maxN]  ;

void build()
{
    int cnt = 0 ; long long sum = 0 ;
    fordec(i,go[1].size()-1,0) {
        int plane = go[1][i].place , c = go[1][i].cost ;
        if (min_cost[1][plane] == 0) {
            cnt ++ ; min_cost[1][plane] = c ;
            sum += c ;
        } else if (min_cost[1][plane] > c) sum -= min_cost[1][plane] , sum += c , min_cost[1][plane] = c ;
        if (cnt == n) S[i] = sum ;
    }
}

void process()
{
    forinc(i,0,1) sort(go[i].begin() , go[i].end() , cmp) ;
    build() ; long long res = oo ; int cnt = 0 , j = 0 ;
    forv(i,go[0]) {
        int plane = go[0][i].place , c = go[0][i].cost ;
        if (min_cost[0][plane] == 0) {
            cnt ++ ; sum_min += c ; min_cost[0][plane] = c ;
        } else if (min_cost[0][plane] > c) sum_min -= min_cost[0][plane] , sum_min += c , min_cost[0][plane] = c ;
        while (j < go[1].size() && go[1][j].day < go[0][i].day + k + 1) j ++ ;
        if (cnt == n && j < go[1].size() && S[j] > 0) res = min(res,sum_min + S[j]) ;
    }
    cout << ((res < oo) ? res : -1) << endl ;
}

int main()
{
    //freopen("853B.inp" , "r" , stdin) ;
    enter() ;
    process() ;
    return 0 ;
}
