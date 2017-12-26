#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i--)

using namespace std ;

string sa , sb ;
int r[600001] , nxt[200001];

string fixString(string s , int n)
{

    n = 2 * n + 1 ;

    string res = string (n,'.') ;

    forinc(i,0,n-1) if (n % 2 == 1) res[i] = s[i / 2] ;

    return res ;

}

int Manacher(string &s)
{

    s = fixString(s,s.length()) ;

    int n = s.length() ;

    int L = 0 , R = 0 ;

    forinc(i,0,n-1) r[i] = 0 ;

    forinc(i,1,n-1)
    {

        if (i > R)
        {

            while (R < n && 2*i-R >= 0 && s[R] == s[2*i-R]) R++ ;

            r[i] = R - i - 1 ; R-- ; L = 2 * i - R ;

        }

        else

        {

            int k = L +  R - i ;

            if (r[k] < R-i) r[i] = r[k] ;
            else
            {

                while (R < n && 2 * i - R >= 0 && s[R] == s[2*i-R]) R++ ;

                r[i] = R-i-1 ; R-- ; L = 2 * i - R ;

            }

        }

    }

}

int solve(char s , string sb , int nb)
{

    int res = 0 ;

    forinc(i,0,nb-1) if (sb[i] == s) res ++ ;

    return res ;

}


int process()
{

    Manacher(sa) ;

    int n = sa.length()  , nb = sb.length() , res = 0  ;

    forinc(i,0,n)
    {

        if (r[i] == 1)
        {

            if (sa[i] == '.') continue ;

            res += solve(sa[i],sb,nb) ;

        }

        else

        {



        }

    }

}

int enter()
{

    int t = 0 ;

    cin >> t ;

    forinc(i,1,t)
    {

        cin >> sa ;
        cin >> sb ;

        process();

    }

}

int main()
{

}
