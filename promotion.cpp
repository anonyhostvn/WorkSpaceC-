#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i--)

using namespace std ;

int n , m , f[1001] ;

vector <int> ke[1001] ,ts[1001] ;

int add(int u , int v , int c)
{

    ke[u].push_back(v) ;
    ts[u].push_back(c) ;

}

int enter()
{

    cin >> n >> m ;

    forinc(i,1,n) cin >> f[i] ;

    forinc(i,1,m)
    {

        int u , v , c ;

        cin >> u >> v >> c ;

        add(u,v,c) ;

    }

}

int process()
{



}

int main()
{
}
