#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)

using namespace std ;

long long n , s ;

bool check(long long x)
{
    int sum = 0 ;
    long long tmp = x ;

    while (tmp)
    {
        sum += tmp % 10 ;
        tmp /= 10 ;
    }

    return (x - sum) >= s ;
}

int main()
{

    cin >>  n >> s ;

    long long l = 0 , r = n  , res = n+1 ;

    while  (l <= r)
    {
        long long mid = (l+r) / 2 ;

        if (check(mid))
        {
            res = mid ;
            r = mid - 1 ;
        }

        else l = mid + 1 ;
    }

    cout << n - res + 1 ;

}
