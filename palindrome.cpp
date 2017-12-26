#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i--)

using namespace std ;

string st ;
int n , r[3000001] ;

int enter()
{

    cin >> st ;

    n = st.length() ;

}

string fixString(string st)
{

    n = 2 * n + 1 ;

    string res = string(n,'.') ;

    forinc(i,0,n-1) if (i % 2 == 1) res[i] = st[i/2] ;

    return res ;

}

int Manacher()
{

    st = fixString(st) ;

    int L = 0 , R = 0 ;
    r[0] = 0 ;

    forinc(i,1,n-1)
    {

        if (i > R)
        {

            L = R = i ;

            while ((R < n) && (2 * i - R >= 0) && (st[R] == st[2*i-R])) R++ ;

            r[i] = R - i  - 1; R-- ; L = 2 * i - R ;

        }

        else
        {

            int k = L + R - i ;

            if (r[k] < R-i)  r[i] = r[k] ;
            else
            {

                while (R < n && 2* i - R >= 0 && (st[R] == st[2*i-R])) R++ ;

                r[i] = R - i - 1 ; R-- ; L = 2 * i - R ;

            }

        }

    }

}

int process()
{

    Manacher() ;

    int nmax = 0 ;

    forinc(i,0,n-1) nmax = max(nmax,2 * r[i] +1) ;

    cout << nmax / 2 ;

}

int main()
{

    //freopen("palindrome.inp" , "r" , stdin) ;

    enter() ;

    process() ;

}
