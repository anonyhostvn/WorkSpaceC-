#include <bits/stdc++.h>
#include "dna.h"

#include <cstdlib>

using namespace std ;

static std::string s;
static int tests;

bool make_test(std::string p) {
  tests++;
  for (int i = 0; i < p.size(); i++) {
    if (p[i] != '0' && p[i] != '1') {
      return false;
    }
  }
  std::string ss = p + "#" + s;
  std::vector<int> pr(ss.size() + 1);
  pr[0] = -1;
  bool answer = false;
  for (int i = 1; i <= ss.size(); i++) {
    int k = pr[i - 1];
    while (k >= 0 && ss[k] != ss[i - 1])
      k = pr[k];
    pr[i] = k + 1;
    if (pr[i] == p.size()) {
      answer = true;
      break;
    }
  }
  return answer;
}



std ::string a[1001] ;

int firstString(int n , int t)
{

    a[0] = "" ;

    int res = 0 ;

    for (int i = 1 ; i <= n ; i++) a[i] = a[i-1] + "1" ;

    int l = 0 , r = n ;

    while (l <= r)
    {

        int mid = (l+r) / 2 ;

        if (make_test(a[mid]))
        {

            l = mid + 1 ;

            res = mid ;

        }
        else r  = mid - 1;

    }

    return res ;

}

std ::string analyse(int n, int t) {

    int cnt = 0 , let = firstString(n,t)  ;

    std ::string st = a[let]  ;

    /**while (cnt < n)
    {

        if (make_test(st + "1"))
        {

            cnt ++ ;

            st = st + "1" ;

        }

        else if (make_test(st + "0"))
        {

            cnt ++ ;

            st = st + "0" ;

        }

        else if (make_test("1" + st))
        {

            cnt ++ ;

            st = "1" + st ;

        }

        else if (make_test("0" + st))
        {

            cnt ++ ;

            st = "0" + st ;

        }

    }**/

    while (true)
    {

        if (make_test(st + "0"))
        {

            st = st + "0" ;

            cnt = 0 ;

        }
        else
        {

            if (cnt < let)
            {

                cnt ++ ;

                st = st + "1" ;

            }

            else
            {

                int l = st.length() ;

                std :: string stt = "" ;

                for (int i = 0 ; i <= l-1-let ; i++) stt = stt + st[i] ;

                st = stt ;

                break ;

            }

        }

    }

    cnt = st.length() ;

    while (cnt < n)
    {

        if (make_test("0" + st)) st = "0" + st ;

        else st = "1" + st ;

        cnt ++ ;

    }

    return st ;
}


int main() 
{
	
	freopen("dna.inp" , "r" , stdin) ; 
	freopen("dna.out" , "w" , stdout) ; 	
	
  	int t;
  	//std::cout << "enter S and t\n";
  	std::cin >> s >> t;
  	std::string ans = analyse(s.size(), t);
  	//std::cout << "the program made " << tests << " tests and answer " << ans << std::endl;
  	if (tests <= t) std::cout << "OK" ; else std::cout << "NO" ; 
  	return 0;
}
