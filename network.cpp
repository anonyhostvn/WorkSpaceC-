#include <bits/stdc++.h>
#include "network.h"
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)

using namespace std;

int cnt = 0 ;
pair<int , int> path[2001] ;
bool dd[2001] ;
//_____________________________________________________________________________________________________________________________________________________-
/**
static int MAX_N = 1010;
#define distance alksdjflaskdjf

static int N, a, b, M,
           pingCount,
           routeLength, current;
static int distance[1010][1010] ;

static void raiseError (const char* message)
{
    printf ("ERROR\n%s\n", message);
    exit (0);
}

int ping (int i, int j)
{
    if (i < 1 || j < 1 || i > N || j > N || i == j)
        raiseError ("ping called with invalid arguments");

    ++pingCount;
    if (pingCount > M)
        raiseError ("Too many calls to ping");

    return distance[i-1][j-1] + 1 ;
}

void travelTo (int k)
{
    if (k < 1 || k > N)
        raiseError ("travelTo called with invalid argument");

    if (k == current || distance[current-1][k-1] > 0)
        raiseError ("Travelling to nonadjacent computer");

    ++routeLength;
    if (routeLength > distance[a-1][b-1] + 1)
        raiseError ("Route is too long");

    current = k;
}

**/
//_______________________________________________________________________________________________________________________________________________-
/**
int findInter(int root ,int n , int a , int b , int shortest)
{

    if (shortest == 1) return 0 ;

    forinc(i,1,n)
    if ((i != a) && (i != b) && (!dd[i]))
    {

        int partf = ping(a,i) , partl = ping(i,b) ;

        if (partf + partl == shortest)
        {

            cnt ++ ;

            path[cnt].first = ping(root,i) ;

            path[cnt].second = i ;

            dd[i] = true ;

            findInter(root,n,a,i,partf) ;
            findInter(root,n,i,b,partl) ;

            break ;

        }

    }

}

void findRoute (int n, int a, int b) {

    int shortest = ping(a,b) ;

    dd[a] = true ; dd[b] = true ;

    findInter(a,n,a,b,shortest) ;

    sort(path+1,path+1+cnt) ;

    forinc(i,1,cnt) travelTo(path[i].second) ;

    travelTo(b) ;

}

**/
vector <int> a[4001] ;

int shortest = 0 , trace[2001] ;

int prepare(int root , int n , int b)
{

    forinc(i,1,n)
        if (i != root)
        {

            int tmp = ping(root,i);

            a[tmp].push_back(i) ;

            if (i == b) shortest = tmp ;

        }

}

void findRoute(int n , int a , int b)
{

    int cnt = 0 ;

    prepare(a,n,b)  ;

    forinc(i,1,shortest)
    {

        forinc(j,0,a[i].size()-1)
            if (ping(a[i][j],b) + i == shortest)
            {

                cnt++ ;

                trace[cnt] = a[i][j] ;

            }

    }

}

//_______________________________________________________________________________________________________________________________________________________________
/**
int main()
{

    freopen("network.inp" , "r" , stdin) ;

    scanf ("%d%d%d%d", &N, &a, &b, &M);

    for (int u = 0; u < N; ++u)
        for (int v = 0; v < N; ++v)
            scanf("%d", &distance[u][v]);

    pingCount = 0;
    routeLength = 0;
    current = a;

    findRoute (N, a, b);

    if (current != b)
        raiseError ("Message has not reached its target");

    if (routeLength < distance[a-1][b-1] + 1)
        raiseError ("Unexpected: route is too short");

    printf ("OK\n");

    return 0;
}
**/

