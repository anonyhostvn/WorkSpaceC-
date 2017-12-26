#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ;  i >= b ; i--)

using namespace std ;

long long  n , k , m ;
pair<long long , long long > a[51] ;

bool cmp(pair<long long , long long > a , pair<long long ,long long > b)
{

    if ((a.first < b.first) || ((a.first == b.first) && (a.second < b.second))) return true ;

    return false ;

}

int enter()
{

    cin >> n >> m >> k ;

    forinc(i,1,k) cin >> a[i].first >> a[i].second ;
    sort(a+1,a+1+k) ;

}

int process()
{

    long long  diff = 1 , cnt = 0 ;

    forinc(i,2,k) if (a[i].first != a[i-1].first) diff++ ;

    int i = 1 ;

    while (i <= k)
    {

        int last = 0 ;

        cnt += max((long long) 0 , a[i].second-2) ;

        while ((i < k) && (a[i].first == a[i+1].first))
        {

            cnt += a[i+1].second - a[i].second - 2 ;

            i++ ;

        }

        cnt += m+1-a[i].second -2 ;

        i++ ;

    }

    cout << ((long long)(n-diff) * (m-1)) + cnt ;

}

int main ()
{

    //freopen("seating.inp" , "r" , stdin) ;

    enter() ;
    process() ;

}
